#ifndef SUDOSH_H
#define SUDOSH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// ----------------
#define SUDOSH_BUFFER_SIZE                  1024
#define SUDOSH_TOKEN_BUFSIZE                64
#define SUDOSH_TOKEN_DELIMITER              " \t\r\n\a"






void sudosh(void);
char *sudosh_read_line(void);
char **sudosh_split_line(char *line);
int sudosh_execute(char **args);

void save_history(const char *line);

// -- builtins
int sudosh_cd(char **args);
int sudosh_help(char **args);
int sudosh_exit(char **args);




#endif




/*
 * ---------------------------
 *      sudosh Features
 * ---------------------------
 * 
 *  Basic Enhancements:
 *  [x] Command History: Store executed commands and allow navigation with arrow keys.
 *  [] Command Autocompletion: Use readline for tab-based completion.
 *  [x] Colorful Prompt: Add ANSI escape sequences for a customized look.
 *  [] Improved Error Handling: Provide better messages for invalid commands.
 *  [] Command Aliases: Implement an alias system for frequently used commands.
 * 
 * Intermediate Features:
 *  [] I/O Redirection: Support '< input.txt' and '> output.txt' for redirection.
 *  [] Piping ('|'): Enable command chaining like 'ls | grep .c'.
 *  [] Background Execution ('&'): Allow processes to run in the background.
 *  [] Process Management: Implement 'jobs', 'fg', and 'bg' commands.
 *  [] Configuration File: Load settings (e.g., aliases, prompt format) from '~/.sudoshrc'.
 * 
 * Advanced Features:
 *  [] Scripting Support: Enable script execution with control structures (if, for, etc.).
 *  [] Custom Environment Variables: Support 'export VAR=value' functionality.
 *  [] Signal Handling: Properly handle SIGINT (Ctrl+C) and SIGTSTP (Ctrl+Z).
 *  [] Multi-threaded Execution: Optimize certain operations with parallelism.
 *  [] Tab Completion for Built-ins: Implement command-specific autocompletion.
 * 
 * Expert-Level Additions:
 *  [] Job Control ('kill', 'nohup'): Implement better process management tools.
 *  [] Networking Commands: Add built-in networking features like 'ping' and 'wget'.
 *  [] Plugin System: Allow users to extend the shell with custom scripts or modules.
 *  [] Shell Modes ('vi'/'emacs'): Support different keyboard input styles.
 *  [] Filesystem Navigation Enhancements: Implement 'pushd', 'popd', and 'dirs'.
 *
 */
