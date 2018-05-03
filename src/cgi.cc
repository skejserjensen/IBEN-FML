#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>

#include <unistd.h>


std::string get_boundary(const std::string& line)
{
    auto res = std::string{};
    auto sname = std::string(" boundary=");
    auto pname = line.find(sname);
    if (pname != std::string::npos) {
	res = "--";
	res += line.substr(pname+sname.size());
    }
    return res;
}


std::string get_attribute(const std::string& line, const std::string& name)
{
    auto res = std::string{};
    auto sname = std::string(" ")+name+"=\"";
    auto pname = line.find(sname);
    if (pname != std::string::npos) {
	auto e = line.find("\"", pname+sname.size());
	if (e != std::string::npos) {
	    res = line.substr(pname+sname.size(), e-pname-sname.size());
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
    std::string content_type;
    std::string content;
    bool empty() { return content.empty(); }
};

inline
std::istream& gettrimline(std::istream& is, std::string& line)
{
    std::getline(is,line);
    if (line.back()=='\r')
	line.erase(line.size()-1);
    return is;
}

std::vector<form_field> get_form_data(std::istream& is,
				      const std::string& boundary)
{
    static auto cd = std::string("Content-Disposition:");
    static auto ct = std::string("Content-Type:");
    auto res = std::vector<form_field>{};
    auto line = std::string{};
    gettrimline(is, line);
    if (line != boundary) {
	error("got \"", line, "\" (",line.size(),") instead of \"", boundary, "\" (",
	      boundary.size(),")\n");
    }
    while (is) {
	auto field = form_field{};
	if (getline(is, line) && line.compare(0, cd.size(), cd)==0) {
	    field.name = get_attribute(line, "name");
	    field.filename = get_attribute(line, "filename");
	    gettrimline(is, line);
	    if (line.compare(0, ct.size(), ct)==0) {
		field.content_type = line.substr(ct.size()+1);
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
	    if (field.content.size()>0 && field.content.back()=='\n')
		field.content.erase(field.content.size()-1);
	}
	res.emplace_back(std::move(field));
    }
    return res;
}

void output_file(std::ostream& os, const std::string& path, size_t skip=0)
{
    auto is = std::ifstream{path};
    auto line = std::string{};
    while (skip-->0 && gettrimline(is, line));
    while (gettrimline(is, line))
	os << line << "\n";
}

std::pair<int,int> proc_open(const char* cmdline)
{
    static const char* sh = "sh";
    static const char* mc = "-c";
    char *const args[] = { (char*)sh, (char*)mc, (char*)cmdline, nullptr };
    auto PATH = std::string("PATH=")+getenv("PATH");
    char *const envp[] = { (char*)PATH.c_str(), nullptr };

    int fds1[2];
    int fds2[2];
    pipe(fds1); /* first pair of pipe descriptors */
    pipe(fds2); /* second pair of pipe descriptors */

    switch (fork()) {
    case 0: /* child */
	close(fds1[1]); // close the write end
	close(fds2[0]); // close the read end

	dup2(fds1[0], 0); // redirect stdin to the first pipe
	dup2(fds2[1], 1); // redirect stdout to the second pipe

	/* the original ends of the pipes are not needed anymore */
	close(fds1[0]);
	close(fds2[1]);

	execve("/bin/sh", args, envp);
	break;

    case -1:
	error("could not fork");
	break;

    default: /* parent */
	close(fds1[0]); // close the read end
	close(fds2[1]); // close the write end
	break;
    }
    return {fds1[1], fds2[0]};
}


void print_form_page(std::ostream& os)
{
    auto script_name = getenv("SCRIPT_NAME");// "/cgi-bin/iben.cgi"
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

int handle_cgi(int argc, char* argv[])
{
    using std::cout;
    auto method = getenv("REQUEST_METHOD"); // "POST", or "GET"
    if (!method)
	error("no REQUEST_METHOD");

    if (std::string(method)=="GET") {
	print_form_page(cout);
	return 0;
    }
    if (std::string(method)!="POST")
	error("expecting REQUEST_METHOD=POST but got ", method);

    auto script_filename = getenv("SCRIPT_FILENAME"); // ".../iben.cgi"
    if (!script_filename)
	error("no SCRIPT_FILENAME\n");

    auto content_type = getenv("CONTENT_TYPE");
    if (!content_type)
	error("no CONTENT_TYPE\n");

    auto enctype = std::string("multipart/form-data;");
    if (std::string(content_type).compare(0, enctype.size(), enctype)!=0)
	error("expected multiform/form-data form enctype, but got ",
	      content_type, '\n');

    auto boundary = get_boundary(content_type);
    if (std::empty(boundary))
	error("expected FormBoundary, but got ", boundary, '\n');

    auto fields = get_form_data(std::cin, boundary);
    auto tdir = std::string{};
    {
	char* dirname = strdup("/tmp/iben-XXXXXX");
	auto tmpdir = mkdtemp(dirname);
	if (!tmpdir)
	    error("could not create tmpdir\n");
	tdir = tmpdir;
	free(dirname);
    }
    auto script = std::string{};
    for (auto& field: fields) {
	if (!field.empty() && !field.filename.empty()) {
	    field.filename = tdir+"/"+field.filename;
	    std::ofstream(field.filename) << field.content;
	    script += "load \"";
	    script += field.filename;
	    script += "\";\n";
	}
    }
    for (auto& field: fields)
	if (!field.empty() && field.filename.empty())
	    script += field.content;
    auto dot_input = tdir + "/iben.dot";
    auto dot_output = tdir + "/iben.svg";
    cout << "Content-type: text/html\n\n"
	"<!DOCTYPE html>\n<html>\n<body>\n<pre>";

    //cout << script << std::endl;

    auto cmd = std::string(script_filename)+
	" DOTINPUT=\""+dot_input+
	"\" DOTOUTPUT=\""+dot_output+
	"\" VIEWPATH=true VIEWCMD=true 2>&1";
    auto iben = proc_open(cmd.c_str());
    write(iben.first, script.c_str(), script.size());
    close(iben.first);
    char* buffer = new char[256];
    ssize_t s;
    while ((s=read(iben.second, buffer, 255)) > 0) {
	buffer[s] = '\0';
	cout << buffer;
    }
    if (s<0) {
	cout << "Error reading from iben\n";
    }
    close(iben.second);
    cout << "</pre>\n\n";
    output_file(cout, dot_output, 6);
    cout << "\n</body>\n</html>\n";

    remove(dot_input.c_str());
    remove(dot_output.c_str());
    for (auto& field: fields)
	if (!field.filename.empty())
	    remove(field.filename.c_str());
    rmdir(tdir.c_str());
    return 0;
}
