#include "StringFunctions.h"

int setWord(char word[])
{
	char ch = '\0';
	int size = 0;
	
	//memset(word, '\0', sizeof(word));
	
	scanf("%[^ \n\t]s", word);
	// do
	// {
	// 	ch = getch();
	// 	ch = (ch == '\r') ? '\n' : ch;
	// 	word[size++] = ch;
	// 	putchar(ch);
	// } while (size < WORD && (ch != ' ' && ch != '\t' && ch != '\n'));
	
	//size--;
	//word[size] = '\0';

	return size;
}

int setText(char text[])
{
	char ch = '\0';
	int size = 0;

	//memset(text, '\0', sizeof(text));
	scanf("%[^ \n\t]s", text);
	// do
	// {
	// 	ch = getch();
	// 	ch = (ch == '\r') ? '\n' : ch;
	// 	putchar(ch);
	// 	text[size++] = ch;
	// } while (size < TXT && ch != '~');
	
	//size--;

	//text[size] = '\0';

	return size;
}

int replaceStr(char* word, char oldCh, char newCh)
{
	char* pInd = NULL;
	if (word == NULL)
	{
		return FALSE;
	}

	if ((pInd = strrchr(word, oldCh)) == NULL)
	{
		return FALSE;
	}

	pInd[0] = newCh;

	return TRUE;
	
}