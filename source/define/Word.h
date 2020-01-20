#ifndef _WORD_DEFINE_
#define _WORD_DEFINE_

#include "String.h"
#include <stdbool.h>
#include <stdlib.h>

//--------------------------------------------------

// Word struct
struct WordStruct
{
  String english;
  String vietnamese;
};

// Word
typedef struct WordStruct Word;

//--------------------------------------------------

// Create Word
void Word_create(Word *word, String english, String vietnamese)
{
  word->english = (String)malloc(sizeof(english));
  word->vietnamese = (String)malloc(sizeof(vietnamese));
  strcpy(word->english, english);
  strcpy(word->vietnamese, vietnamese);
}

// Destroy Word
void Word_destroy(Word *word)
{
  free(word->english);
  free(word->vietnamese);
}

// Check equal
bool Word_isEqual(Word word1, Word word2)
{
  return String_isEqual(word1.english, word2.english);
}

#endif
