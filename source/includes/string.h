#ifndef _STRING_INCLUDE_
#define _STRING_INCLUDE_

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//--------------------------------------------------

// String
typedef char *String;

//--------------------------------------------------

bool String_isEqualIgnoreCase(const String string1, const String string2)
{
  if (strlen(string1) == strlen(string2))
  {
    size_t index = 0;
    while (index < strlen(string1))
    {
      if (tolower(string1[index]) == tolower(string2[index]))
      {
        index++;
      }
      else
      {
        return false;
      }
    }
    return true;
  }
  else
  {
    return false;
  }
}

#endif