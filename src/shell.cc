/**
 * Copyright (c) 2018 Marius Mikucionis
 * Customizable shell commands.
 */

#include "shell.h"

#include <algorithm>
#include <map>
#include <iostream>
#include <cstring> // strchr
#include <cstdlib> // getenv

#include <unistd.h> // getpid

/** file-path to the dot-executable: */
const char* dotpath_key = "DOTPATH";
const char* dotpath_value = "dot";

/** preferable picture format: */
const char* format_key = "DOTFORMAT";
const char* format_value = "svg";

/** extra arguments to graphviz: */
const char* options_key = "DOTOPTIONS";
const char* options_value = "-Gcenter=1 -Gsize=\"7,10\"";

/** graphviz input dot-file-path: */
const char* dotinput_key = "DOTINPUT";

/** graphviz output image-file-path: */
const char* dotoutput_key = "DOTOUTPUT";

/** entire command to dot/graphviz: */
const char* dotcmd_key = "DOTCMD";

/** external viewer command: */
const char* viewpath_key = "VIEWPATH";

const char* viewcmd_key = "VIEWCMD";

static std::map<std::string,std::string> props;


void execute_command(const std::string& cmd)
{
    std::cout << cmd << std::endl;
    auto res = system(cmd.c_str());
    if (res) {
	std::cout << "error: " << res << std::endl;
    }
}

std::string find_browser()
{
    auto xdg = getenv("XDG_SESSION_DESKTOP");
    if (xdg) {
	auto f = popen("xdg-mime query default text/html", "r");
	char buffer[128];
	auto res = fgets(buffer, sizeof(buffer), f);
	pclose(f);
	if (res) {
	    auto dot = strrchr(buffer, '.');
	    if (dot) {
		*dot = '\0';
		return buffer;
	    }
	}
	return "xdg-open";
    }
    auto desktop = getenv("DESKTOP_SESSION");
    if (desktop) {
	if (strstr(desktop, "gnome"))
	    return "gnome-open";
	if (strstr(desktop, "kde"))
	    return "kde-open";
    }
    return "firefox";
}

const char* get_property(const std::string& key)
{
    auto it = props.find(key);
    if (it != std::end(props))
	return it->second.c_str();

    auto env = getenv(key.c_str());
    if (env)
	return env;

    if (key == dotcmd_key) {
	auto& value = props[key];
	value = get_property(dotpath_key);
	value += " -T";
	value += get_property(format_key);
	value += " ";
	value += get_property(options_key);
	value += " -o ";
	value += get_property(dotoutput_key);
	value += " ";
	value += get_property(dotinput_key);
	return value.c_str();
    }
    if (key == viewcmd_key) {
	auto& value = props[key];
	value = get_property(viewpath_key);
	value += " ";
	value += get_property(dotoutput_key);
	value += " > /dev/null 2> /dev/null";
	return value.c_str();
    }
    if (key == dotpath_key) {
	auto& value = props[key];
	value = dotpath_value;
	return value.c_str();
    }
    if (key == options_key) {
	auto& value = props[key];
	value = options_value;
	return value.c_str();
    }
    if (key == format_key) {
	auto& value = props[key];
	value = format_value;
	return value.c_str();
    }
    if (key == viewpath_key) {
	auto& value = props[key];
	value = find_browser();
	return value.c_str();
    }
    if (key == dotinput_key) {
	auto& value = props[key];
	char tmp[] = "/tmp/iben-XXXXXX.dot";
	auto f = mkstemps(tmp, 4);
	if (!f) {
	    perror("iben");
	    exit(1);
	}
	close(f);
	value = tmp;
	return value.c_str();
    }
    if (key == dotoutput_key) {
	auto& value = props[key];
	auto ext = get_property(format_key);
	char tmp[80];
	snprintf(tmp, sizeof(tmp), "/tmp/iben-XXXXXX.%s", ext);
	auto f = mkstemps(tmp, strlen(ext)+1);
	if (!f) {
	    perror("iben");
	    exit(1);
	}
	close(f);
	value = tmp;
	return value.c_str();
    }
    return nullptr;
}

void set_property(const std::string& name, const std::string& value)
{
    auto key = std::string(name);
    props[key] = value;
}

void parse_options(int argc, char* argv[])
{
    for (auto i = 1; i < argc; ++i) {
	auto option = argv[1];
	auto eq = std::strchr(option, '=');
	if (eq) {
	    auto key = std::string(option, eq-option);
	    std::transform(key.begin(), key.end(), key.begin(), ::toupper);
	    set_property(key, eq+1);
	} else if (0==strncmp(option, "-h", 2) ||
		   0==strncmp(option, "/h", 2) ||
		   0==strncmp(option, "--help", 6))
	{
	    std::cout <<
		"This IBEN support options in the form of KEY=VALUE:\n"
		"DOTPATH    -- path to dot executable from graphviz [dot]\n"
		"DOTFORMAT  -- image format to be selected for graphviz [svg]\n"
		"DOTOPTIONS -- extra options to dot executable [-Gcenter=1 -Gsize=\"7,10\"]\n"
		"DOTINPUT   -- path for dot-input file [mktmp]\n"
		"DOTOUTPUT  -- path for dot-output file [mktmp]\n"
		"DOTCMD     -- overrides the whole dot-command line\n"
		"VIEWPATH   -- path to the viewer [browser]"
		"VIEWCMD    -- overrides the whole viewer command\n\n"
		"For example, the following selects png format:\n"
		"  " << argv[0] << " DOTFORMAT=png\n";
	} else {
	    std::cout << "Unhandled option: " << option << std::endl;
	}
    }
}

const char* get_dot_input_path()
{
    return get_property(dotinput_key);
}

void render_dot()
{
    auto dotcmd = get_property(dotcmd_key);
    execute_command(dotcmd);

    //ShellExecute(0, 0, L"http://www.google.com", 0, 0 , SW_SHOW);
    auto viewcmd = get_property(viewcmd_key);
    execute_command(viewcmd);
}

std::string get_install_dir()
{
    char buffer[256];
    auto size = readlink("/proc/self/exe", buffer, sizeof(buffer));
    if (size < 0) {
	perror("iben");
	return ".";
    }
    auto slash = strrchr(buffer, '/');
    if (slash) {
	*slash = '\0';
	return buffer;
    }
    return ".";
}

void render_help()
{
    auto viewcmd = std::string(get_property(viewpath_key));
    viewcmd += " \"";
    viewcmd += get_install_dir();
    viewcmd += "/iben.html\"";
    execute_command(viewcmd);
}

