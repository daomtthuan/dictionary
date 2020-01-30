#ifndef _DATA_INCLUDE_
#define _DATA_INCLUDE_

#include <stdio.h>
#include "word.h"

//--------------------------------------------------

// English File path
#define ENGLISH_FILE "../data/English.txt"

// English File path
#define PRONUNCIATION_FILE "../data/Pronunciation.txt"

// English File path
#define VIETNAMESE_FILE "../data/Vietnamese.txt"

// Data struct
struct Data
{
  Word *wordList;
  FILE *englishFile;
  FILE *vietnameseFile;
  FILE *pronunciationFile;
};

//--------------------------------------------------

// Create Data
void Data_create(Data *data)
{
  data->wordList = (Word *)malloc(sizeof(Word));
}

// Read Data
void Data_read(Data *data)
{
}

#endif