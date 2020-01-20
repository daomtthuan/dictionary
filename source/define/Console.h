#ifndef _CONSOLE_DEFINE_
#define _CONSOLE_DEFINE_

#include "Word.h"

//--------------------------------------------------

void Console_message(const String mess)
{
  printf("> SYSTEM: ");
  printf(mess);
  printf("\n\n");
}

void Console_result(const Word word)
{
  printf("> SYSTEM: Search \"%s\"\n", Word_getEnglsh(word));
  printf("    Pronunciation: %s\n", Word_getPronunciation(word));
  printf("    Vietnamese: %s", Word_getVietnamese(word));
  printf("\n\n");
}

#endif