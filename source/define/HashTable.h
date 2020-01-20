#ifndef _HASHTABLE_DEFINE_
#define _HASHTABLE_DEFINE_

#include "Hash.h"
#include "String.h"
#include "Word.h"
#include <stdbool.h>
#include <stdlib.h>

//--------------------------------------------------

// Length of Hash Table
#define LENGTH_HASHTABLE 100

// Element type
typedef Word ElementType;

// Node struct
struct NodeStruct
{
  ElementType data;
  struct NodeStruct *next;
};

// Node
typedef struct NodeStruct Node;

// Hash Table
typedef Node *HashTable[LENGTH_HASHTABLE];

//--------------------------------------------------

// Create Hash Table
void HashTable_create(HashTable *hashTable)
{
  size_t index = 0;
  while (index < LENGTH_HASHTABLE)
  {
    (*hashTable)[index] = NULL;
    index++;
  }
}

// Destroy Hash Table
void HashTable_destroy(HashTable *hashTable)
{
  size_t index = 0;
  while (index < LENGTH_HASHTABLE)
  {
    while ((*hashTable)[index] != NULL)
    {
      Node *nextPosition = ((*hashTable)[index])->next;
      free((*hashTable)[index]);
      (*hashTable)[index] = nextPosition;
    }
    index++;
  }
}

// Get Key from Element
String HashTable_key(ElementType element)
{
  return element.english;
}

// Check Element has existed or not
bool HashTable_isContain(HashTable hashTable, ElementType element)
{
  Node *position = hashTable[Hash_execute(HashTable_key(element), LENGTH_HASHTABLE)];
  while (position != NULL)
  {
    if (Word_isEqual(element, position->data))
    {
      return true;
    }
    else
    {
      position = position->next;
    }
  }
  return false;
}

// Get Node by Key
Node *HashTable_get(HashTable hashTable, String key)
{
  Node *position = hashTable[Hash_execute(key, LENGTH_HASHTABLE)];
  while (position != NULL)
  {
    if (String_isEqual(key, HashTable_key(position->data)))
    {
      return position;
    }
    else
    {
      position = position->next;
    }
  }
  return position;
}

// Insert Element
void HashTable_insert(HashTable *hashTable, ElementType element)
{
  size_t index = Hash_execute(HashTable_key(element), LENGTH_HASHTABLE);
  Node *currentPosition = (*hashTable)[index];
  (*hashTable)[index] = (Node *)malloc(sizeof(Node));
  ((*hashTable)[index])->data = element;
  ((*hashTable)[index])->next = currentPosition;
}

#endif
