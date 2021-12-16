#include "StringFunctions.h"

int setWord(char word[])
{
	scanf("%[^ \t\n]", word);
	return strlen(word);
}

int setText(char text[])
{
	scanf("%[^~]", text);
	return strlen(text);
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

int getGimtric(char ch)
{
    if('A' <= ch && ch <= 'Z')
    {
    	return (ch -'A' + 1);
    }
	
	if('a' <= ch && ch <= 'z')
    {
    	return (ch -'a' + 1);
    }
    
    return 0;
}

void printAllGimatrig(char word[], char text[])
{
	int lenWord = strlen(word);
	int lenTxt = strlen(text);
	int num = 0;
	int gimW = 0;
	
    for (int i = 0; i < lenWord; i++)
	{
       gimW += getGimtric(word[i]);
    }

	int isFirst = TRUE;
	for (int i = 0; i < lenTxt; i++)
	{
		if (getGimtric(text[i]) == 0)
		{
			continue;
		}
		
		num = gimW;
		
		for (int j = i; j < lenTxt; j++)
		{
			int gimatric = getGimtric(text[j]);
			if (gimatric == 0)
			{
				continue;
			}
			
			num -= gimatric;

			if (num == 0)
			{
				int currlen = j - i + 1;
				printf("%s", (isFirst ? "" : "~"));
				printf("%.*s", currlen, &text[i]);
				isFirst = FALSE;
			}
			else if (num <= 0)
			{
				break;
			}
		}
	}
	
}

void makeAtbash(char word[], char atbash[])
{
    memset(atbash, '\0', TXT);
    int lenW = strlen(word);
    
    for (int i = 0; i < lenW; i++)
	{
        if('A' <= word[i] && word[i] <= 'Z')
        {
            atbash[i] = 26 - getGimtric(word[i]) + 'A';
        }
        else if('a' <= word[i] && word[i] <= 'z')
        {
            atbash[i] = 26 - getGimtric(word[i]) + 'a';
        }
		else
		{
			atbash[i] = word[i];
		}
    }
}

void makeReverse(char word[], char rev[])
{
    memset(rev, '\0', TXT);
	int lenW = strlen(word);

    for (int i = 0 ; i < lenW; i++)
	{
       rev[i] = word[lenW - 1 - i];
    }	
}

void strCopyNoSpc(char str[], char text[], int start, int end)
{
	memset(str, '\0', TXT);
	int ind = 0;
	for (int i = start; i <= end; i++)
	{
		if (text[i] != ' ' && text[i] != '\t' && text[i] != '\n')
		{
			str[ind++] = text[i];
		}
	}
}

void printAllAtbash(char word[], char text[])
{
	int lenWord = strlen(word);
	int lenTxt = strlen(text);
	char atbash[TXT] = {0};
	char reverse[TXT] = {0};
	char temp[TXT] = {0};

	makeAtbash(word, atbash);
	makeReverse(atbash, reverse);

	int isFirst = TRUE;
	for (int i = 0; i < lenTxt; i++)
	{
		if (getGimtric(text[i]) == 0)
		{
			continue;
		}
		
		for (int j = i; j < lenTxt; j++)
		{
			int currlen = j - i + 1;
			if (getGimtric(text[j]) == 0 || currlen < lenWord)
			{
				continue;
			}

			strCopyNoSpc(temp, text, i, j);
			
			if (strcmp(temp, atbash) == 0 || strcmp(temp, reverse) == 0)
			{
				printf("%s", (isFirst ? "" : "~"));
				printf("%.*s", currlen, &text[i]);
				isFirst = FALSE;
				break;
			}
		}
	}
}

int isAnagram(char word[], char text[], int start, int end)
{
	int sum = end - start + 1;
	int lenW = strlen(word);
	char* str = (char*)calloc((lenW + 1), sizeof(char));
	strcpy(str, word);

	for (int i = start; i <= end; i++)
	{
		char ch = text[i];
		if (replaceStr(str, ch, ' ') || ch == ' ' || ch == '\t' || ch == '\n')
		{
			sum -= 1;
		}
		else
		{
			break;
		}
	}
	free(str);
	return (sum == 0 ? TRUE : FALSE);
}

void printAllAnagrams(char word[], char text[])
{
	int lenWord = strlen(word);
	int lenTxt = strlen(text);

	int isFirst = TRUE;
	for (int i = 0; i < lenTxt; i++)
	{
		if (getGimtric(text[i]) == 0)
		{
			continue;
		}
		
		for (int j = i; j < lenTxt; j++)
		{
			int currlen = j - i + 1;
			if (getGimtric(text[j]) == 0 || currlen < lenWord)
			{
				continue;
			}
			
			if (isAnagram(word, text, i, j))
			{
				printf("%s", (isFirst ? "" : "~"));
				printf("%.*s", currlen, &text[i]);
				isFirst = FALSE;
				break;
			}
		}
	}
}