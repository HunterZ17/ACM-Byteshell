#include "headers/parse.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

parseInfo *parse(char *commandLine){
    parseInfo *Result;
	char command[81];
	int pos = -1;
    if (commandLine[0] == '\n' || commandLine[0] == '\0')
        return NULL;
    
    Result = malloc(sizeof(parseInfo));

    char *token;

    token = strtok(commandLine, (("\t") || ("-")));

    if(token!=NULL){
        Result->comm = token;
    }

    token = strtok(0,commandLine);
    if(token!=NULL){
        Result->arg = token;
    }

    pos =0;
    command[pos]= "\0";

   
    
    return Result;

}


