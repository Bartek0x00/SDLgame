SRCDIR=src/
OBJDIR=obj/
CC=gcc
LIB=SDL2

.PHONY : run update 

main : $(OBJDIR)main.o $(OBJDIR)update.o $(OBJDIR)input.o $(OBJDIR)draw.o
	$(CC) -o main $(OBJDIR)main.o $(OBJDIR)update.o $(OBJDIR)input.o $(OBJDIR)draw.o -l$(LIB)

$(OBJDIR)main.o : main.c
	$(CC) -c  main.c -o $(OBJDIR)main.o 

$(OBJDIR)update.o : $(SRCDIR)update.c
	$(CC) -c $(SRCDIR)update.c -o $(OBJDIR)update.o

$(OBJDIR)input.o : $(SRCDIR)input.c
	$(CC) -c $(SRCDIR)input.c -o $(OBJDIR)input.o

$(OBJDIR)draw.o : $(SRCDIR)draw.c
	$(CC) -c $(SRCDIR)draw.c -o $(OBJDIR)draw.o

run:
	./main

update:
	touch main.c src/*.c
