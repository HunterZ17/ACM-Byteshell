CFLAGS=-DUNIX -lreadline
DEBUG=-g

all: shell

shell:	shell.c parse.c headers/parse.h headers/builtin.h
	gcc $(DEBUG) shell.c parse.c builtin.c -o shell $(CFLAGS)
clean:
	rm -f shell *~