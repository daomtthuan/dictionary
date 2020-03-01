#ifndef _DICTIONARY_TYPE_INCLUDE_
#define _DICTIONARY_TYPE_INCLUDE_

#include "./hashtable.h"
#include "../ui/console.h"

//--------------------------------------------------

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
 * @param pronunciation - Pronunciation meaning of inserted Word
 * @param vietnamese - Vietnamese meaning of inserted Word
 */
void Dictionary_insert(Dictionary dictionary, const String english, const String pronunciation, const String vietnamese)
{
  if (HashTable_getBucket(dictionary, english) == NULL)
  {
    HashTable_insertElement(dictionary, Word_create(english, pronunciation, vietnamese));
    Console_message("Insert word successful.");
  }
  else
  {
    Console_message("Insert word failed. This word already exists.");
  }
}

/**
 * Delete Word
 *
 * @param dictionary - Dictionary
 * @param english - English meaning of Word
 */
void Dictionary_delete(Dictionary dictionary, const String english)
{
  if (HashTable_getBucket(dictionary, english) == NULL)
  {
    Console_message("Delete word failed. Word not found.");
  }
  else
  {
    HashTable_deleteElement(dictionary, english);
    Console_message("Delete word successful.");
  }
}

/**
 * Search Word
 *
 * @param dictionary - Dictionary
 * @param english - English meaning of Word
 */
void Dictionary_search(Dictionary dictionary, const String english)
{
  Bucket bucket = HashTable_getBucket(dictionary, english);
  if (bucket == NULL)
  {
    Console_message("Search word failed. Word not found.");
  }
  else
  {
    Console_searchResult(bucket->data);
  }
}

#endif