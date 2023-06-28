#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_CHAR_SIZE 100

int cd_fun(char *path);
int hola_fun(char *x);
int help_fun();
int exit_fun();