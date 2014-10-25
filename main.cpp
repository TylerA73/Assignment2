/*

Author: Tyler Arseneault
Date: October 24, 2014
Assignment 2
Purpose: This program will take a text file, extract the words, storing them into a dictionary. It will track the number of occurences of each word, and display them to the user in alphbetical order.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;
using std::string;

#define MAX 100

typedef int BOOL;
typedef string WORD;
typedef WORD DICT[MAX];

/*
  you will have to write code for these 5 functions. 
*/

int LocateWord(DICT, WORD);
BOOL FullDictionary(DICT);
BOOL InsertWord(DICT,WORD);
WORD GetNextWord(void);
void DumpDictionary(DICT ,int[]);

/*
  note that these are global variables so that they are already initialized to 0
*/

DICT dictionary;  //your dictionary 
WORD word;        // 
int count[MAX];   //tracks word frequencies

int main (void) {
    int pos;

    while (1) {
       word = GetNextWord();
       if ( 0 == word.length() )  {
           DumpDictionary(dictionary,count);
           break;
       }
       if ((pos = LocateWord(dictionary,word)) >=  0 ) 
           count[pos]++;
       else
           if (!InsertWord(dictionary,word)) cout << "dictionary full " << word << " cannot be added\n";
    }
    return 0;
}
