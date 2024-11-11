#ifndef ROGRAMM_H
#define PROGRAMM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <locale.h>

extern char **environ;

void print_env_1(void);
void print_env_2(void);
void print_file_content(const char *filename);
void print_usage(const char *program_name);

#endif
