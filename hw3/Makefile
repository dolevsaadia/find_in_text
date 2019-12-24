CC=gcc
CFLAGS=-I.
DEPS =	isort.htxtfind.h
OBJ =	mainforisrt.c	isort.c	
OJ =	mainfortxt.c	txtfind.c
# $@ - the file on the left side of the :
# $< - the first name in the dependencies list
# $^ - the right side of :

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

isort: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

txtfind: $(OJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f hellomake *.o  
