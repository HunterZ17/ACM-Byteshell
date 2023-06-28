#include "headers/builtin.h"

int exit_fun(){
    return 0;
}

int help_fun(){
    puts(
        "`help` - List all the commands\n"
        "`hola` - Terminal says hello\n"
        "`exit` - Exit from the shell\n"
        "`cd` - To change the directory "
    );
    return 1;
}

int cd_fun(char *arg){
    if(arg == NULL){
        printf("psh: expected argument to \"cd\"\n");
    }
    else{
        if(chdir(arg) != 0){
            printf("Oops! Cant able to change the directory\n");
        }
    }

    return 1;
}

int hola_fun(char *x){
    if (x == 0){
        printf("Hola Amigos\n");
    }
    else{
        printf("Use Help command to move further\n");
    }
    return 1;
}