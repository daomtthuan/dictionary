#ifndef _WORD_TYPE_INCLUDE_
#define _WORD_TYPE_INCLUDE_

#include "./string.h"

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
 * @param english - English Word
 * @param pronunciation - Pronunciation of Word in english
 * @param vietnamese - Vietnamese meaning
 *
 * @return - New Word
 */
Word Word_create(const String english, const String pronunciation, const String vietnamese)
{
  Word word = (Word)malloc(sizeof(struct WordStruct));
  word->english = (String)malloc(sizeof(english));
  word->vietnamese = (String)malloc(sizeof(vietnamese));

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
 * Set Vietnamese meaning of Word
 *
 * @param word - Setted Word
 */
void Word_setVietnamese(Word word, const String vietnamese)
{
  word->vietnamese = (String)realloc(word->vietnamese, sizeof(vietnamese));
  strcpy(word->vietnamese, vietnamese);
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
