#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
using std::string;

#define MAX 100

typedef int BOOL;
typedef string WORD;
typedef WORD DICT[MAX];

int LocateWord(DICT, WORD);
BOOL FullDictionary(DICT);
BOOL InsertWord(DICT,WORD);
WORD GetNextWord(void);
void DumpDictionary(DICT ,int[]);

int numberWords;
extern int count[MAX];


BOOL InsertWord(DICT dict, WORD word)
{
/* 
  adds word to dictionary , if word can't be added returns 0 else returns 1
*/

   if( !FullDictionary(dict) ){

      dict[numberWords] = word;
      count[numberWords] = 1;
      numberWords++;
      return 1;

   }
   
   return 0;

}

void DumpDictionary(DICT dict, int count[]) {
/* 
  will sort the dictionary, and display the contents
*/

    WORD tmpWord;
    int nextWord = 0;
    int tmpFreq  = 0;
    const int WIDTHFORMAT = 70;

    for ( int i = 0; i < (numberWords - 1); i++ ){ /*for loop will sort the dictionary
                                                    alphabetically*/
       nextWord = i;
      
       for( int j = (i + 1); j < numberWords; j++ ){
    
          if( dict[j] < dict[nextWord] ) nextWord = j;   

       }
       
       tmpWord = dict[i];
       tmpFreq = count[i];
       dict[i]  = dict[nextWord];
       count[i] = count[nextWord];
       dict[nextWord]  = tmpWord;
       count[nextWord] = tmpFreq;
       
    }

    /*prints out the dictionary*/
    cout << left << setfill('-');
    cout << setw(WIDTHFORMAT);
    cout << "Word";
    cout << "Frequency";
    cout << endl;
    cout << endl;
    for( int i = 0; i < numberWords; i++){
       cout << left << setfill(' ');
       cout << setw(WIDTHFORMAT);
       cout << dict[i];
       //cout << right << setfill(' ');
       //cout << setw(50);
       cout << count[i] << endl;

    } 

}

WORD GetNextWord(void){
/* 
   will retrieve next word in input stream. Word is defined just as in assignment #1 
   returns WORD or 0 if no more words in input stream
*/
   bool inputSuccess = false;
   char letter;
   WORD tmp;

   while( cin.good() ){
      
      letter = cin.get();
      if( isalpha(letter) ){

         tmp.push_back( letter );
         inputSuccess = true;
    
      }
      
      else if ( inputSuccess )
          return tmp;
   }
   return tmp;

}

BOOL FullDictionary(DICT dict) { /* determines if the dictionary is full or not */

   if(numberWords == MAX) 
      return 1;

   return 0;
}

int LocateWord(DICT dict, WORD word) {
/*
   will determine if dictionary contains word. if found, returns position else returns value < 0
*/
   int location;
   
   for( location = 0; location < numberWords; location++ ) /* scans through each word in dictionary*/
      if( dict[location] == word ) /*returns location of the word if found*/
         return location;

   return -1; /*returns -1 if word not found in dictionary*/
     
}
