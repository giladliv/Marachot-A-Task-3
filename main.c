#include "StringFunctions.h"

int main()
{
	char word[WORD] = { 0 };
	char text[TXT] = { 0 };
	setWord(word);
	setText(text);

	printf("Gematria Sequences: ");
	printAllGimatrig(word, text);
	
	printf("\nAtbash Sequences: ");
	printAllAtbash(word, text);

	printf("\nAnagram Sequences: ");
	printAllAnagrams(word, text);
	
	return (0);
}