#ifndef STRING_FUNCTIONS
#define STRING_FUNCTIONS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>

#define TXT 1024
#define WORD 31

#define TRUE 1
#define FALSE 0


int setWord(char word[]);
int setText(char text[]);

int replaceStr(char* word, char oldCh, char newCh);


#endif // STRING_FUNCTIONS_H

