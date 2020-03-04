#ifndef _WORD_TYPE_INCLUDE_
#define _WORD_TYPE_INCLUDE_

#include "string.h"

//--------------------------------------------------

// Word struct
struct WordStruct
{
  // English Word
  String english;

  // Vietnamese mean of Word
  String vietnamese;
};

// Word type
typedef struct WordStruct *Word;

//--------------------------------------------------

/**
 * Create Word
 *
 * @param position - Position of word
 * @param english - English Word
 * @param vietnamese - Vietnamese meaning
 *
 * @return - New Word
 */
Word Word_create(const String english, const String vietnamese)
{
  Word word = (Word)malloc(sizeof(struct WordStruct));
  word->english = (String)malloc(sizeof(char) * (strlen(english) + 1));
  word->vietnamese = (String)malloc(sizeof(char) * (strlen(vietnamese) + 1));

  strcpy(word->english, english);
  strcpy(word->vietnamese, vietnamese);

  return word;
}

/**
 * Destroy Word
 *
 * @param word - Destroyed Word
 */
void Word_destroy(Word word)
{
  free(word->english);
  free(word->vietnamese);
  free(word);
  word->english = NULL;
  word->vietnamese = NULL;
  word = NULL;
}

//--------------------------------------------------

/**
 * Get english meaning of Word
 *
 * @param word - Getted Word
 *
 * @return - English meaning of Word
 */
String Word_getEnglsh(Word word)
{
  return word->english;
}

/**
 * Get vietnamese meaning of Word
 *
 * @param word - Getted Word
 *
 * @return - Vietnamese meaning of Word
 */
String Word_getVietnamese(Word word)
{
  return word->vietnamese;
}

/**
 * Get Key from Word
 *
 * @param word - Getted Word
 *
 * @return Key of Word
 */
String Word_getKey(const Word word)
{
  return Word_getEnglsh(word);
}

#endif
