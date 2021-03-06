#ifndef _WORD_INCLUDE_
#define _WORD_INCLUDE_

#include "./String.h"

//--------------------------------------------------

// Word struct
struct WordStruct {
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
Word Word_Create(const String english, const String vietnamese) {
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
void Word_Destroy(Word word) {
  free(word->english);
  free(word->vietnamese);
  free(word);
}

#endif
