#ifndef _DICTIONARY_TYPE_INCLUDE_
#define _DICTIONARY_TYPE_INCLUDE_

#include "../hashtable/hashtable.h"
#include "./program.h"

//--------------------------------------------------

// Dictionary type
typedef Hashtable Dictionary;

//--------------------------------------------------

/**
 * Create Dictionary
 *
 * @return New Dictionary
 */
Dictionary Dictionary_create()
{
  return Hashtable_create();
}

/**
 * Destroy Dictionary
 *
 * @param dictionary Destroyed Dictionary
 */
void Dictionary_destroy(Dictionary dictionary)
{
  Hashtable_destroy(dictionary);
}

//--------------------------------------------------

/**
 * Insert Word
 *
 * @param dictionary - Dictionary
 * @param english - English meaning of inserted Word
 * @param vietnamese - Vietnamese meaning of inserted Word
 *
 * @return Insert result success or not
 */
bool Dictionary_insert(Dictionary dictionary, const String english, const String vietnamese)
{
  if (Hashtable_getBucket(dictionary, english) == NULL)
  {
    Hashtable_insertElement(dictionary, Word_create(english, vietnamese));
    return true;
  }
  else
  {
    return false;
  }
}

/**
 * Delete Word
 *
 * @param dictionary - Dictionary
 * @param english - English meaning of Word
 *
 * @return Delete result success or not
 */
bool Dictionary_delete(Dictionary dictionary, const String english)
{
  if (Hashtable_getBucket(dictionary, english) == NULL)
  {
    return false;
  }
  else
  {
    Hashtable_deleteElement(dictionary, english);
    return true;
  }
}

/**
 * Load Word
 *
 * @param dictionary - Dictionary
 */
void Dictionary_loadData(Dictionary dictionary, const String dataFile)
{
  FILE *file = fopen(dataFile, "r+");

  fflush(stdin);
  char cursor = fgetc(file);
  while (cursor != EOF)
  {
    int line = 0;
    String english = String_create();
    String vietnamese = String_create();

    while (line++ < 2)
    {
      while (cursor != '\n')
      {
        String_joinChar(line == 1 ? &english : &vietnamese, cursor);
        fflush(stdin);
        cursor = fgetc(file);
      }

      fflush(stdin);
      cursor = fgetc(file);
    }

    Dictionary_insert(dictionary, english, vietnamese);
    String_destroy(english);
    String_destroy(vietnamese);
  }

  fclose(file);
}

/**
 * Search Word
 *
 * @param dictionary - Dictionary
 * @param english - English meaning of Word
 *
 * @return Search result found Word or NULL if not found
 */
Word Dictionary_search(Dictionary dictionary, const String english)
{
  BucketHashtable bucket = Hashtable_getBucket(dictionary, english);
  if (bucket == NULL)
  {
    return NULL;
  }
  else
  {
    return bucket->data;
  }
}

#endif
