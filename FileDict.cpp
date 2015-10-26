#include <cstdio>
#include <cctype>
#include <iostream>
#include <cstring>

/*	Name:Chadd Trudel
	Student ID: 5010918
	Project: Assignment 1
	Description: Simple file dictionary that reads input from a file, counts the words and displays the word 				and frequency of each word.	
*/

using namespace std;

const int ROW = 150;
const int COL = 30;
const int MAXWORD = 200;

char Dictionary [ROW][COL];
int count[ROW] = {0};
int NumWords = 0;

int SearchDict(char *buffer) 
{
	
	for (int i = 0; i < NumWords; i++) 
		{
		if (!strcmp(Dictionary [i], buffer))
		return i;  
		}
	return -1;	
}

void AddWord(char *buffer) 
{
		
	if (NumWords < ROW) 
	{
		strcpy(Dictionary[NumWords], buffer);
		NumWords++;
	}
		else cout << "Sorry, there are too many words."<< endl;

}

void DumpDict(void) 
{
	cout << "	File Dictionary Program" << endl;
	cout << "---------------------------------------" << endl;
	cout << "Word			Frequency" << endl;
	cout << "____			_________" << endl << endl;
	
	for (int i = 0; i < NumWords; i++) 
	{
	
	cout << Dictionary[i] << "			" << count[i] << endl;
	}
}

int main() 
{

char ch;
int newLine= 0;
char Buffer[MAXWORD];
int Length = 0;
int RowPosition = 0;

	while( cin.good() )
	{
		ch = cin.get();
 		if ( isalpha(ch) )  // test to see if the next token is a letter/word
    		{
       			Buffer[Length] = ch;
			Length++;
       			newLine = 1;
    		}
	else

	if (newLine)
	{
              	Buffer[Length] = '\0';	
        	
		if ( (RowPosition = SearchDict(Buffer) ) < 0)
                {
			count[NumWords] = 1;			
			AddWord(Buffer);
              		newLine = 0;
		   
		}
		else count[RowPosition]++;
	        Length = 0;
		newLine = 0;
          }
	

 
}

DumpDict();
return 0;
}
