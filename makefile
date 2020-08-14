INCDIR =./include
OBJDIR =./obj
SRCDIR = ./src
MAIN = main

CC=gcc -g
#CFLAGS=-I$(INCDIR) -I$(OBJDIR) -Wall

_OBJ = global.o gen.o init.o serve.o main.o 
OBJ = $(patsubst %,$(OBJDIR)/%,$(_OBJ))
      
_INC = includes.h defines.h literals.h global.h gen.h init.h serve.h main.h
INC = $(patsubst %,$(INCDIR)/%,$(_INC))

all: clean $(MAIN) #exec

$(MAIN): $(OBJ)
	$(CC) $^ -o $@  $(CFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c 
	$(CC) -c $^ -o $@ $(CFLAGS)

exec:
	./$(MAIN)

.PHONY: clean

clean:
	clear
	$(RM) $(MAIN) $(OBJDIR)/*.o *~ core $(INCDIR)/*~