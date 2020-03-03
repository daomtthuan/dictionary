#ifndef _HASHTABLE_TYPE_INCLUDE_
#define _HASHTABLE_TYPE_INCLUDE_

#include "hash.h"

//--------------------------------------------------

// Length of Hash Table
#define LENGTH_HASHTABLE 100

// HashTable type
typedef Bucket *HashTable;

//--------------------------------------------------

/**
 * Create HashTable
 *
 * @return - New HashTable with null Buckets
 */
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

/**
 * Destroy HashTable
 *
 * @param hashTable - Destroyed HastaTable
 */
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

/**
 * Get Bucket by Key
 *
 * @param hashTable - Getted HashTable
 * @param key - Compared key
 *
 * @return Bucket in HashTable
 */
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
  return NULL;
}

/**
 * Insert Element
 *
 * @param hashTable - HashTable
 * @param element - Inserted Element
 */
void HashTable_insertElement(HashTable hashTable, const Element element)
{
  size_t index = Hash_execute(Element_getKey(element), LENGTH_HASHTABLE);
  Bucket currentBucket = hashTable[index];
  hashTable[index] = Bucket_create(element, currentBucket);
}

/**
 * Delete Element by key
 *
 * @param hashTable - HashTable
 * @param key - Key of deleted Element
 */
void HashTable_deleteElement(HashTable hashTable, const String key)
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
