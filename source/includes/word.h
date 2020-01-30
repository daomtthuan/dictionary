#ifndef _WORD_INCLUDE_
#define _WORD_INCLUDE_

#include "string.h"

//--------------------------------------------------

// Word struct
struct WordStruct
{
  // English Word
  String english;

  // Pronunciation of English Word
  String pronunciation;

  // Vietnamese mean of Word
  String vietnamese;
};

// Word
typedef struct WordStruct *Word;

//--------------------------------------------------

// Create Word
Word Word_create(const String english, const String pronunciation, const String vietnamese)
{
  Word word = (Word)malloc(sizeof(struct WordStruct));
  word->english = (String)malloc(sizeof(english));
  word->pronunciation = (String)malloc(sizeof(pronunciation));
  word->vietnamese = (String)malloc(sizeof(vietnamese));

  strcpy(word->english, english);
  strcpy(word->pronunciation, pronunciation);
  strcpy(word->vietnamese, vietnamese);

  return word;
}

// Destroy Word
void Word_destroy(Word word)
{
  free(word->english);
  free(word->vietnamese);
  free(word);
}

//--------------------------------------------------

// Get English
String Word_getEnglsh(Word word)
{
  return word->english;
}

// Get Pronunciation
String Word_getPronunciation(Word word)
{
  return word->pronunciation;
}

// Get Vietnamese
String Word_getVietnamese(Word word)
{
  return word->vietnamese;
}

// Set Pronunciation
void Word_setPronunciation(Word word, const String pronunciation)
{
  word->pronunciation = (String)realloc(word->pronunciation, sizeof(pronunciation));
  strcpy(word->pronunciation, pronunciation);
}

// Set Vietnamese
void Word_setVietnamese(Word word, const String vietnamese)
{
  word->vietnamese = (String)realloc(word->vietnamese, sizeof(vietnamese));
  strcpy(word->vietnamese, vietnamese);
}

#endif
