#ifndef _HASHTABLE_INCLUDE_
#define _HASHTABLE_INCLUDE_

#include "word.h"
#include "hash.h"

//--------------------------------------------------

// Length of Hash Table
#define LENGTH_HASHTABLE 100

// Element type
typedef Word Element;

// Node struct
struct NodeStruct
{
  // Element
  Element data;

  // Next Node
  struct NodeStruct *next;
};

// Node
typedef struct NodeStruct Node;

//Bucket
typedef Node *Bucket;

// Hash Table
typedef Bucket *HashTable;

//--------------------------------------------------

// Create Hash Table
HashTable HashTable_create()
{
  HashTable hashTable = (HashTable)malloc(sizeof(Bucket) * LENGTH_HASHTABLE);
  size_t index = 0;
  while (index < LENGTH_HASHTABLE)
  {
    hashTable[index] = NULL;
    index++;
  }
  return hashTable;
}

// Destroy Bucket
void Bucket_destroy(Bucket bucket)
{
  Word_destroy(bucket->data);
  free(bucket);
}

// Destroy Hash Table
void HashTable_destroy(HashTable hashTable)
{
  size_t index = 0;
  while (index < LENGTH_HASHTABLE)
  {
    while (hashTable[index] != NULL)
    {
      Bucket bucket = hashTable[index]->next;
      Bucket_destroy(hashTable[index]);
      hashTable[index] = bucket;
    }
    index++;
  }

  free(hashTable);
}

//--------------------------------------------------

// Get Key from Element
String Element_getKey(const Element element)
{
  return Word_getEnglsh(element);
}

// Get Bucket by Key
Bucket HashTable_getBucket(const HashTable hashTable, const String key)
{
  Bucket bucket = hashTable[Hash_execute(key, LENGTH_HASHTABLE)];
  while (bucket != NULL)
  {
    if (String_isEqualIgnoreCase(key, Element_getKey(bucket->data)))
    {
      return bucket;
    }
    else
    {
      bucket = bucket->next;
    }
  }
  return bucket;
}

// Insert Element
void HashTable_insert(HashTable hashTable, const Element element)
{
  size_t index = Hash_execute(Element_getKey(element), LENGTH_HASHTABLE);
  Bucket currentBucket = hashTable[index];
  hashTable[index] = (Bucket)malloc(sizeof(Node));
  hashTable[index]->data = element;
  hashTable[index]->next = currentBucket;
}

// Delete Element
void HashTable_delete(HashTable hashTable, const String key)
{
  size_t index = Hash_execute(key, LENGTH_HASHTABLE);
  if (hashTable[index] != NULL)
  {
    Bucket currentBucket = hashTable[index];
    if (String_isEqualIgnoreCase(key, Element_getKey(currentBucket->data)))
    {
      hashTable[index] = hashTable[index]->next;
      Bucket_destroy(currentBucket);
    }
    else
    {
      bool deleted = false;
      while (currentBucket->next != NULL && !deleted)
      {
        if (String_isEqualIgnoreCase(key, Element_getKey(currentBucket->next->data)))
        {
          Bucket nextBucket = currentBucket->next;
          currentBucket->next = nextBucket->next;
          Bucket_destroy(nextBucket);
          deleted = true;
        }
        else
        {
          currentBucket = currentBucket->next;
        }
      }
    }
  }
}

#endif
