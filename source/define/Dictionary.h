#ifndef _DICTIONARY_DEFINE_
#define _DICTIONARY_DEFINE_

#include "Console.h"
#include "HashTable.h"

//--------------------------------------------------

// Dictionary
typedef HashTable Dictionary;

//--------------------------------------------------

// Create Dictionary
Dictionary Dictionary_create()
{
  return HashTable_create();
}

// Destroy Dictionary
void Dictionary_destroy(Dictionary dictionary)
{
  HashTable_destroy(dictionary);
}

// Insert Word
void Dictionary_insert(Dictionary dictionary, const String english, const String pronunciation, const String vietnamese)
{
  if (HashTable_getBucket(dictionary, english) == NULL)
  {
    HashTable_insert(dictionary, Word_create(english, pronunciation, vietnamese));
    Console_message("Insert word successful.");
  }
  else
  {
    Console_message("Insert word failed. This word already exists.");
  }
}

// Delete Word
void Dictionary_delete(Dictionary dictionary, const String english)
{
  if (HashTable_getBucket(dictionary, english) == NULL)
  {
    Console_message("Delete word failed. Word not found.");
  }
  else
  {
    HashTable_delete(dictionary, english);
    Console_message("Delete word successful.");
  }
}

// Search Word
void Dictionary_search(Dictionary dictionary, const String english)
{
  Bucket bucket = HashTable_getBucket(dictionary, english);
  if (bucket == NULL)
  {
    Console_message("Word not found.");
  }
  else
  {
    Console_result(bucket->data);
  }
}

#endif