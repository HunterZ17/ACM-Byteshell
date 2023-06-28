#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/builtin.h"
#include "headers/parse.h"
#include <readline/readline.h>
#include <unistd.h>
#include <sys/wait.h>

enum BUILTIN_COMMANDS
{
    NO_SUCH_BUILTIN = 0,
    DED
};

int execute(parseInfo* info)
{
    char *cmd = info->comm;
    char *arg = info->arg;

    if(strcmp(cmd, "cd") == 0){
        cd_fun(arg);
        return DED;
    }
    else if(strcmp(cmd, "exit") == 0){
        int status = exit_fun();
        return status;
    }
    else if(strcmp(cmd, "help") == 0){
        help_fun();
        return DED;
    }
    else if(strcmp(cmd, "Hola") == 0){
        hola_fun(arg);
        return DED;
    }
    fprintf("Command doesnt exist.\n");
    return DED;

}

int launch(char **args)
{
  pid_t pid;
  int status;

  pid = fork();

  if (pid == 0)
   {
    if (execvp(args[0], args) == -1)
     {
       printf("%s: command not found\n",args[0]);
     }
    exit(1);
  } 

  else if (pid < 0)
   {
    return 1;
   } 

  else
   {
    do
     {
      waitpid(pid, &status, WUNTRACED);
     } while (!WIFEXITED(status) && !WIFSIGNALED(status));
   }

  return 1;
}

int main(int argc, char **argv)
{
    char *commandLine;
    parseInfo *info;
    fprintf("Use exit command to exit the terminal\n");

    while(1)
    {
        commandLine = readline("escribir >");

        info = parse(commandLine);
        int status;

        if(info == NULL){
            free(commandLine);
            continue;
        }
        else{
            status = execute(info);
        }

        free(info);
        free(commandLine);
        if (status == 0)
            break;
    }
}