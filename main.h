#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void free_str(char **input);
int string_cleaning(char *l);
int number_of_token(char *del, char *string);
char **string_tok(char *ln, char *del);
int executing(char *path, char **string);

#endif
