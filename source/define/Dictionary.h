#ifndef _DICTIONARY_DEFINE_
#define _DICTIONARY_DEFINE_

#include "HashTable.h"
#include "String.h"
#include "Word.h"
#include <stdlib.h>

//--------------------------------------------------

// Dictionary
typedef HashTable Dictionary;

//--------------------------------------------------

// Create Dictionary
void Dictionary_create(Dictionary *dictionary)
{
  HashTable_create(dictionary);
}

// Destroy Dictionary
void Dictionary_destroy(Dictionary *dictionary)
{
  HashTable_destroy(dictionary);
}

// Insert Word
void Dictionary_insert(Dictionary *dictionary, Word word)
{
  HashTable_insert(dictionary, word);
}

// Get Vietnamese from English Word
String Dictionary_get(Dictionary dictionary, String english)
{
  Node *node = HashTable_get(dictionary, english);
  if (node == NULL)
  {
    return "\0";
  }
  else
  {
    return node->data.vietnamese;
  }
}

#endif