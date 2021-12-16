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

int getGimtric(char ch);
void printAllGimatrig(char word[], char text[]);

void makeAtbash(char word[], char atbash[]);
void makeReverse(char word[], char rev[]);
void strCopyNoSpc(char str[TXT], char text[TXT], int start, int end);
void printAllAtbash(char word[], char text[]);

int isAnagram(char word[], char text[], int start, int end);
void printAllAnagrams(char word[], char text[]);


#endif // STRING_FUNCTIONS_H

