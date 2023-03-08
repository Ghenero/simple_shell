#ifndef _MAIN_H
#define _MAIN_H

#define HSH_TOK_BUFSIZE 64
#define HSH_TOK_DELIM " \t\r\n\a"

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*builtins*/
int cmd_cd(char **args);
int cmd_help(char **args);
int cmd_exit(char **args);

int built_in_count(void);
int cmd_launch(char **args);
int cmd_execute(char **args);
char *read_line(void);
char **get_tokens(char *line);
void life_cycle(void);
#endif
