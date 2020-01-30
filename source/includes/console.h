#ifndef _CONSOLE_INCLUDE_
#define _CONSOLE_INCLUDE_

#include <stdio.h>
#include "word.h"

//--------------------------------------------------

void Console_message(const String mess)
{
  printf("> SYSTEM: ");
  printf(mess);
  printf("\n\n");
}

void Console_searchResult(const Word word)
{
  printf("> SYSTEM: Search word successful.\n");
  printf("    English: %s\n", Word_getEnglsh(word));
  printf("    Pronunciation: %s\n", Word_getPronunciation(word));
  printf("    Vietnamese: %s", Word_getVietnamese(word));
  printf("\n\n");
}

#endif