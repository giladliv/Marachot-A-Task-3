CC=gcc
AR=ar
FLAGS= -Wall -g
OBJECTS_MAIN=main.o
OBJECTS_STR=StringFunctions.o

all: stringProg

stringProg: $(OBJECTS_MAIN) $(OBJECTS_STR)
	$(CC) $(FLAGS) $(OBJECTS_MAIN) $(OBJECTS_STR) -o stringProg
	
main.o: main.c StringFunctions.h
	$(CC) $(FLAGS) -c main.c
	
StringFunctions.o: StringFunctions.c StringFunctions.h
	$(CC) $(FLAGS) -c StringFunctions.c


.PHONY: clean all

clean:
	rm -f *.o stringProg