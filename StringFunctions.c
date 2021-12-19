#include "StringFunctions.h"


/**
 * @brief Set the Word string, until getting empty char
 * 
 * @param word string
 * @return length on the string
 */
int setWord(char word[])
{
	scanf("%[^ \t\n]", word);
	return strlen(word);
}

/**
 * @brief Set the Text string, until getting the char '~'
 * 
 * @param text string of a whole text
 * @return int 
 */
int setText(char text[])
{
	scanf("%[^~]", text);
	return strlen(text);
}

/**
 * @brief replace the last apperacne of the curr char to a new char
 * 
 * @param word 
 * @param oldCh 
 * @param newCh 
 * @return int 
 */
int replaceStr(char* word, char oldCh, char newCh)
{
	char* pInd = NULL;
	if (word == NULL)
	{
		return FALSE;
	}

	if ((pInd = strrchr(word, oldCh)) == NULL) // if found no char in the string then return false
	{
		return FALSE;
	}
	
	//the return val of pInd is the pointer to the index in string that starts with the wanted char
	pInd[0] = newCh;	// set the char to be the new one

	return TRUE;
	
}

/**
 * @brief print the substring of some string with '~' between them
 * 
 * @param text the original string
 * @param start index of first char of substring
 * @param end index of last char of substring
 * @param isFirst is the first substring to being print (passed by referance)
 */
void printSubString(char text[], int start, int end, int* isFirst)
{
	if (start <= end && end < strlen(text))
	{
		int currlen = end - start + 1;
		// if it is the first time to being printed, dont print '~'
		printf("%s", ((*isFirst) ? "" : "~"));
		// from index i print the substring to j (give the substring len)
		printf("%.*s", currlen, &text[i]);
		(*isFirst) = FALSE; // already printed, then not the first time
	}
	
}

/**
 * @brief Get the Gimtric value of given char, 1 to 26 if between lower or upper abc letters
 * 0 returned else
 * 
 * @param ch given char
 * @return int gimatric value of the char
 */
int getGimtric(char ch)
{
    if('A' <= ch && ch <= 'Z')		// char is a upper char
    {
    	return (ch -'A' + 1);
    }
	
	if('a' <= ch && ch <= 'z')		// char is a lower char
    {
    	return (ch -'a' + 1);
    }
    
    return 0;		// if not big or small abc char then iit has no gimatrig val, return 0
}

/**
 * @brief print all the minimized sub-strings with the same gimatric value of word
 * 
 * @param word string that the subsrtings must has the same gimatric value compared to this one
 * @param text string that all the minimixed substrings must be taken from
 */
void printAllGimatrig(char word[], char text[])
{
	int lenWord = strlen(word);
	int lenTxt = strlen(text);
	int num = 0;
	int gimW = 0;
	
    for (int i = 0; i < lenWord; i++)	// computes the whole gimatric value of word to gimW
	{
       gimW += getGimtric(word[i]);
    }

	int isFirst = TRUE;
	for (int i = 0; i < lenTxt; i++)
	{
		// if the first char of the word has no meaning then skip it
		// not suitable to calculations
		if (getGimtric(text[i]) == 0)
		{
			continue;
		}
		
		num = gimW;		// temp value
		
		for (int j = i; j < lenTxt; j++)	// from some index gets all the sub strings
		{
			int gimatric = getGimtric(text[j]);
			if (gimatric == 0)	// if the last char has no meaning then skip the computing
			{
				continue;
			}
			
			num -= gimatric;

			if (num == 0) // if the substring has got the whole value of word
			{
				printSubString(text, i, j, &isFirst);
			}
			
			if (num <= 0)
			{
				break;	// if got the the word or passed its value don't continue
			}
		}
	}
	
}

/**
 * @brief by given some string puts to the other string it's atbash string
 * 
 * @param word given word
 * @param atbash word as atbash
 */
void makeAtbash(char word[], char atbash[])
{
    memset(atbash, '\0', TXT);	// init the atbash string
    int lenW = strlen(word);
    
    for (int i = 0; i < lenW; i++)
	{
        if('A' <= word[i] && word[i] <= 'Z')
        {
            atbash[i] = 26 - getGimtric(word[i]) + 'A'; // find the mirrored value and add to the start letter
        }
        else if('a' <= word[i] && word[i] <= 'z')
        {
            atbash[i] = 26 - getGimtric(word[i]) + 'a'; // find the mirrored value and add to the start letter
        }
		else
		{
			atbash[i] = word[i]; // dont change because not atbash compatible
		}
    }
}

/**
 * @brief by given some string set to rev the string reversed
 * 
 * @param word given word
 * @param rev word reversed
 */
void makeReverse(char word[], char rev[])
{
    memset(rev, '\0', TXT); // init the rev string
	int lenW = strlen(word);

    for (int i = 0 ; i < lenW; i++)
	{
       rev[i] = word[lenW - 1 - i];		// get the oposite index from word
    }	
}

/**
 * @brief copy from string (by given sub string values) without empty-char's to str,
 * the range of sub string is [start, end] (all included)
 * 
 * @param str the substring without empty-chars
 * @param text the original string
 * @param start start index of sub string
 * @param end end index of substring (end is the last char)
 */
void strCopyNoSpc(char str[], char text[], int start, int end)
{
	memset(str, '\0', TXT);
	int ind = 0;
	for (int i = start; i <= end && i < TXT; i++)
	{
		// if not empty char set it to the out string (rev)
		if (text[i] != ' ' && text[i] != '\t' && text[i] != '\n')
		{
			str[ind++] = text[i];
		}
	}
}

/**
 * @brief print all the substring that in text and equals to word in atbash (or atbash reversed)
 * 
 * @param word the main word
 * @param text text to get the substrings
 */
void printAllAtbash(char word[], char text[])
{
	int lenWord = strlen(word);
	int lenTxt = strlen(text);
	char atbash[TXT] = {0};
	char reverse[TXT] = {0};
	char temp[TXT] = {0};

	makeAtbash(word, atbash);		// set the atbash string to be the atbash
	makeReverse(atbash, reverse);	// set to reverse the reverse of atbash

	int isFirst = TRUE;
	for (int i = 0; i < lenTxt; i++)
	{
		// if the first char of the word has no meaning then skip it
		// not suitable to calculations
		if (getGimtric(text[i]) == 0)
		{
			continue;
		}
		
		for (int j = i; j < lenTxt; j++)
		{
			int currlen = j - i + 1;
			// if the last char of the word has no meaning 
			// or the substring len is smaller than the word's len, 
			// then skip it, not suitable to calculations
			if (getGimtric(text[j]) == 0 || currlen < lenWord)
			{
				continue;
			}

			strCopyNoSpc(temp, text, i, j); // set to temp the string without empty-chars
			
			// if the substring without emptychar equals to the atbash string or reversed
			// then it is an atbashed word
			if (strcmp(temp, atbash) == 0 || strcmp(temp, reverse) == 0)
			{
				printSubString(text, i, j, &isFirst);
				
				// dont continue because its allrade fits,
				// adding another letter to the word will make it not suitable
				break;
			}
		}
	}
}

/**
 * @brief check if substring is a anagram of a given word
 * 
 * @param word 
 * @param text 
 * @param start 
 * @param end 
 * @return int 
 */
int isAnagram(char word[], char text[], int start, int end)
{
	int lenW = strlen(word);
	int sum = lenW;
	char* str = (char*)calloc((lenW + 1), sizeof(char));	// make a copy of the word
	strcpy(str, word);

	for (int i = start; i <= end; i++)
	{
		char ch = text[i];
		if (ch == ' ' || ch == '\t' || ch == '\n') // skip empty chars
		{
			continue;
		}
		// each time that a letter can be replaced then remove 1 from the counter of the word replaces
		else if (replaceStr(str, ch, ' ')) // space is safe because word is space free
		{
			sum -= 1;
		}
		else // if coudn't replace then the substr is not an anagram
		{
			sum = -1;
			break;
		}
	}
	free(str); // free allocated memory
	return (sum == 0 ? TRUE : FALSE);
}

void printAllAnagrams(char word[], char text[])
{
	int lenWord = strlen(word);
	int lenTxt = strlen(text);

	int isFirst = TRUE;
	for (int i = 0; i < lenTxt; i++)
	{
		// if the first char of the word has no meaning then skip it
		// not suitable to calculations
		if (getGimtric(text[i]) == 0)
		{
			continue;
		}
		
		for (int j = i; j < lenTxt; j++)
		{
			int currlen = j - i + 1;
			// if the last char of the word has no meaning 
			// or the substring len is smaller than the word's len, 
			// then skip it, not suitable to calculations
			if (getGimtric(text[j]) == 0 || currlen < lenWord)
			{
				continue;
			}
			
			// is substring is an anagram then print it
			if (isAnagram(word, text, i, j))
			{
				printSubString(text, i, j, &isFirst);
				
				// dont continue because its allrade fits,
				// adding another letter to the word will make it not suitable
				break;
			}
		}
	}
}