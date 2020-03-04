#ifndef _STRING_TYPE_INCLUDE_
#define _STRING_TYPE_INCLUDE_

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//--------------------------------------------------

// String type
typedef char *String;

//--------------------------------------------------

/**
 * Create empty String
 *
 * @return - Empty String
 */
String String_create()
{
  String string = (String)malloc(sizeof(char));
  strcpy(string, "");
  return string;
}

/**
 * Destroy String
 *
 * @param string - Destroyed String
 */
void String_destroy(String string)
{
  free(string);
}

//--------------------------------------------------

/**
 * Compare two strings are equal without case of string
 *
 * @param string1 - First string
 * @param string2 - Second string
 *
 * @return - Bool result true or false
 */
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

/**
 * Join the Char into end of String
 *
 * @param string - String
 * @param c - joined char
 */
void String_joinChar(String *string, const char c)
{
  const size_t length = strlen(*string);
  (*string) = (String)realloc((*string), sizeof(char) * (length + 2));
  (*string)[length] = c;
  (*string)[length + 1] = '\0';
}

#endif