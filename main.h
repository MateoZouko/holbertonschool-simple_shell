#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void free_str(char **arg);
int freememory(char **tokens_array, char **path_array);
int executing(char *path, char **string, char **environment);
int finding_the_path(char **path_array, char **args_array, char **environment);
int cleaningstring(char *l);
int tokenident(char *string, char *del);
char **string_tok(char *line, char *del);
int substring_length(char *string, char *del);

#endif
