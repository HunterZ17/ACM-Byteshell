typedef struct 
{
    char *comm;
    char *arg;
} parseInfo;

parseInfo *parse(char *);
free(parseInfo *);
