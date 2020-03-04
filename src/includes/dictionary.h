#ifndef _DICTIONARY_TYPE_INCLUDE_
#define _DICTIONARY_TYPE_INCLUDE_

#include "hashtable.h"
#include "program.h"

//--------------------------------------------------

// Data File
#define DATA_FILE "./data/data.txt"

// Dictionary type
typedef HashTable Dictionary;

//--------------------------------------------------

/**
 * Create Dictionary
 *
 * @return New Dictionary
 */
Dictionary Dictionary_create()
{
  return HashTable_create();
}

/**
 * Destroy Dictionary
 *
 * @param dictionary Destroyed Dictionary
 */
void Dictionary_destroy(Dictionary dictionary)
{
  HashTable_destroy(dictionary);
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
  if (HashTable_getBucket(dictionary, english) == NULL)
  {
    HashTable_insertElement(dictionary, Word_create(english, vietnamese));
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
  if (HashTable_getBucket(dictionary, english) == NULL)
  {
    return false;
  }
  else
  {
    HashTable_deleteElement(dictionary, english);
    return true;
  }
}

/**
 * Load Word
 *
 * @param dictionary - Dictionary
 */
void Dictionary_loadData(Dictionary dictionary)
{
  FILE *file = fopen(DATA_FILE, "r+");

  String enLine = String_create();
  String viLine = String_create();

  char cursor;
  bool isEnLine = true;

  fflush(stdin);
  while ((cursor = fgetc(file)) != EOF)
  {
    if (cursor != '\n')
    {
      String_joinChar(isEnLine ? &enLine : &viLine, cursor);
    }
    else
    {
      isEnLine = !isEnLine;
      if (isEnLine)
      {
        Dictionary_insert(dictionary, enLine, viLine);
        enLine = String_create();
        viLine = String_create();
      }
    }
  }

  String_destroy(enLine);
  String_destroy(viLine);
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
  Bucket bucket = HashTable_getBucket(dictionary, english);
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
