#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


/* read/write command */
#define MAX_COMMAND_LENGTH 1024

int parse_command(char *command, char *argv[]);
size_t _getline(char *command);
int parse_command(char *command, char *argv[]);
int search_command(char *command, char *full_path);
void _exc(char *argv[]);

#endif
