#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <filesystem>
#include <unistd.h>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std::string_literals;
using namespace std::string_view_literals;

std::string get_boundary(const std::string& line)
{
    auto res = std::string{};
    auto sname = " boundary="sv;
    auto pname = line.find(sname);
    if (pname != std::string::npos) {
        res = "--";
        res += line.substr(pname + sname.length());
    }
    return res;
}

std::string get_attribute(const std::string& line, const std::string& name)
{
    auto res = std::string{};
    auto sname = " " + name + "=\"";
    auto pname = line.find(sname);
    if (pname != std::string::npos) {
        auto e = line.find("\"", pname + sname.size());
        if (e != std::string::npos) {
            res = line.substr(pname + sname.size(), e - pname - sname.size());
        }
    }
    return res;
}

template <typename... Args>
void error(Args&&... args)
{
    std::cout << "Content-type: text/html\n\n"
                 "<!DOCTYPE html>\n<html>\n<head><title>Server Error</title></head>\n"
                 "<body>\nServer Error:\n<pre>";
    ((std::cout << args), ...);
    std::cout << "</pre>\n</body>\n</html>\n";
    exit(EXIT_FAILURE);
}

struct form_field
{
    std::string name;
    std::string filename;
    std::filesystem::path filepath;
    std::string content_type;
    std::string content;
    bool empty() const { return content.empty(); }
};

inline std::istream& gettrimline(std::istream& is, std::string& line)
{
    std::getline(is, line);
    if (line.back() == '\r')
        line.erase(line.size() - 1);
    return is;
}

std::vector<form_field> get_form_data(std::istream& is, const std::string& boundary)
{
    static constexpr auto cd = "Content-Disposition:"sv;
    static constexpr auto ct = "Content-Type:"sv;
    auto res = std::vector<form_field>{};
    auto line = std::string{};
    gettrimline(is, line);
    if (line != boundary) {
        error("got \"", line, "\" (", line.size(), ") instead of \"", boundary, "\" (", boundary.size(), ")\n");
    }
    while (is) {
        auto field = form_field{};
        if (getline(is, line) && line.compare(0, cd.length(), cd) == 0) {
            field.name = get_attribute(line, "name");
            field.filename = get_attribute(line, "filename");
            gettrimline(is, line);
            if (line.compare(0, ct.size(), ct) == 0) {
                field.content_type = line.substr(ct.size() + 1);
                gettrimline(is, line);
            }
            if (line.empty())
                gettrimline(is, line);
            while (is && line.compare(0, boundary.size(), boundary) != 0) {
                field.content += line;
                field.content += '\n';
                gettrimline(is, line);
            }
            // remove the last empty line:
            if (field.content.size() > 0 && field.content.back() == '\n')
                field.content.erase(field.content.size() - 1);
        }
        res.emplace_back(std::move(field));
    }
    return res;
}

void output_file(std::ostream& os, const std::filesystem::path& path, size_t skip = 0)
{
    auto is = std::ifstream{path};
    auto line = std::string{};
    while (skip-- > 0 && gettrimline(is, line))
        ;
    while (gettrimline(is, line))
        os << line << "\n";
}

struct proc_io
{
    int input;
    int output;
};

proc_io proc_open(const char* cmdline)
{
    static const char* sh = "sh";
    static const char* mc = "-c";
    char* const args[] = {(char*)sh, (char*)mc, (char*)cmdline, nullptr};
    auto PATH = "PATH="s + getenv("PATH");
    char* const envp[] = {(char*)PATH.c_str(), nullptr};

    int fds1[2];
    int fds2[2];
    pipe(fds1); /* first pair of pipe descriptors */
    pipe(fds2); /* second pair of pipe descriptors */

    switch (fork()) {
    case 0:              /* child */
        close(fds1[1]);  // close the write end
        close(fds2[0]);  // close the read end

        dup2(fds1[0], 0);  // redirect stdin to the first pipe
        dup2(fds2[1], 1);  // redirect stdout to the second pipe

        /* the original ends of the pipes are not needed anymore */
        close(fds1[0]);
        close(fds2[1]);

        execve("/bin/sh", args, envp);
        break;

    case -1: error("could not fork"); break;

    default:             /* parent */
        close(fds1[0]);  // close the read end
        close(fds2[1]);  // close the write end
        break;
    }
    return {fds1[1], fds2[0]};
}

void print_form_page(std::ostream& os)
{
    auto script_name = getenv("SCRIPT_NAME");  // "/cgi-bin/iben.cgi"
    if (!script_name)
        script_name = getenv("REQUEST_URI");
    os << R"(Content-type: text/html

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8"/>
    <title>IBEN: Interactive BDD Environment</title>
  </head>
  <body>
    <h1>IBEN: Interactive BDD Environment</h1>
    <p>Enter IBEN input here and click Submit:</p>
    <form id="iben" action=")";
    os << script_name <<
        R"(" method="post" target="result" enctype="multipart/form-data">
      <input type="file" name="scriptfile1"/><br/>
      <input type="file" name="scriptfile2"/><br/>
      <textarea name="script" cols="80" rows="10"></textarea><br/>
      <input type="submit" value="Submit"/> <a href="iben.html" target="_blank">IBEN Manual</a>
    </form>
    <iframe name="result" width="1024" height="800"></iframe>
    <p>IBEN as a service &copy; 2018 Marius Mikučionis</p>
  </body>
</html>)";
}

bool starts_with(std::string_view text, std::string_view prefix)
{
    if (text.length() < prefix.length())
        return false;
    auto res = std::equal(prefix.begin(), prefix.end(), text.begin());
    return res;
}

std::filesystem::path create_temp_dir()
{
    auto tmp = std::filesystem::temp_directory_path() / "iben-XXXXXX";
    char* dirname = strdup(tmp.c_str());
    auto tmpdir = mkdtemp(dirname);
    if (!tmpdir)
        error("could not create tmpdir\n");
    std::filesystem::path res = tmpdir;
    free(dirname);
    return res;
}

int handle_cgi(int argc, char* argv[])
{
    using std::cout;
    auto method = getenv("REQUEST_METHOD");  // "POST", or "GET"
    if (!method)
        error("no REQUEST_METHOD");

    if (std::string(method) == "GET") {
        print_form_page(cout);
        return 0;
    }
    if (std::string(method) != "POST")
        error("expecting REQUEST_METHOD=POST but got ", method);

    auto script_filename = getenv("SCRIPT_FILENAME");  // ".../iben.cgi"
    if (!script_filename)
        error("no SCRIPT_FILENAME\n");

    auto content_type = getenv("CONTENT_TYPE");
    if (!content_type)
        error("no CONTENT_TYPE\n");

    auto enctype = std::string("multipart/form-data;");
    if (!starts_with(content_type, enctype))
        error("expected multiform/form-data in CONTENT_TYPE, but got ", content_type, '\n');

    auto boundary = get_boundary(content_type);
    if (std::empty(boundary))
        error("expected FormBoundary, but got ", boundary, '\n');

    auto fields = get_form_data(std::cin, boundary);
    const auto tdir = create_temp_dir();
    auto script = std::string{};
    for (auto& field : fields) {
        if (!field.empty() && !field.filename.empty()) {
            field.filepath = tdir / field.filename;
            std::ofstream{field.filepath} << field.content;
            script += "load \"";
            script += field.filename;
            script += "\";\n";
        }
    }
    for (const auto& field : fields)
        if (!field.empty() && field.filename.empty())
            script += field.content;
    const auto dot_input = tdir / "iben.dot";
    const auto dot_output = tdir / "iben.svg";
    cout << "Content-type: text/html\n\n"
            "<!DOCTYPE html>\n<html>\n<body>\n<pre>";

    // cout << script << std::endl;
    auto cmd_os = std::ostringstream{};
    cmd_os << script_filename;
    cmd_os << " DOTINPUT=" << std::quoted(dot_input.string());
    cmd_os << " DOTOUTPUT=" << std::quoted(dot_output.string());
    cmd_os << " VIEWPATH=true VIEWCMD=true 2>&1";
    const auto cmd = cmd_os.str();
    auto iben = proc_open(cmd.c_str());
    write(iben.input, script.c_str(), script.length());
    close(iben.input);
    char buffer[1025];
    ssize_t s;
    while ((s = read(iben.output, buffer, 1024)) > 0) {
        buffer[s] = '\0';
        cout << buffer;
    }
    if (s < 0) {
        cout << "Error reading from iben\n";
    }
    close(iben.output);
    cout << "</pre>\n\n";
    output_file(cout, dot_output, 6);
    cout << "\n</body>\n</html>\n";

    std::filesystem::remove(dot_input);
    std::filesystem::remove(dot_output);
    for (auto& field : fields)
        if (!field.filename.empty())
            remove(field.filepath);

    rmdir(tdir.c_str());
    return 0;
}
