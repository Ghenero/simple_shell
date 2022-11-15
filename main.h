#ifndef _MAIN_H
#define _MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "structs.h"
#include <sys/wait.h>
/*include functions below*/
char *read_line();
void handle_tokens(char *src);
char **get_tokens(char *src);
int token_oven(char **tokens);
/*end the if preprocessor*/
#endif
