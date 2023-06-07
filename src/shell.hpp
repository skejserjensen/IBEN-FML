/**
 * Interface to the customizable shell environment.
 */

#ifndef SHELL_H
#define SHELL_H

#include <string>

/** options must come in key=value pairs format */
extern void parse_options(int argc, char* argv[]);

extern const char* get_property(const std::string& name);
extern void set_property(const std::string& name, const std::string& value);

extern const char* get_dot_input_path();

extern void render_dot();
extern void render_help();

#endif /* SHELL_H */
