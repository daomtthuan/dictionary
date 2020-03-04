#ifndef _HASHTABLE_INCLUDE_
#define _HASHTABLE_INCLUDE_

#include "./solution.h"

//--------------------------------------------------

// Length of Hash Table
#define LENGTH_HASHTABLE 100

// Hashtable type
typedef BucketHashtable *Hashtable;

//--------------------------------------------------

/**
 * Create Hashtable
 *
 * @return - New Hashtable with null Buckets
 */
Hashtable Hashtable_create()
{
  Hashtable hashTable = (Hashtable)malloc(sizeof(BucketHashtable) * LENGTH_HASHTABLE);
  size_t index = 0;
  while (index < LENGTH_HASHTABLE)
  {
    hashTable[index] = NULL;
    index++;
  }
  return hashTable;
}

/**
 * Destroy Hashtable
 *
 * @param hashTable - Destroyed HastaTable
 */
void Hashtable_destroy(Hashtable hashTable)
{
  size_t index = 0;
  while (index < LENGTH_HASHTABLE)
  {
    while (hashTable[index] != NULL)
    {
      BucketHashtable bucket = hashTable[index]->next;
      Bucket_destroy(hashTable[index]);
      hashTable[index] = bucket;
    }
    index++;
  }

  free(hashTable);
  hashTable = NULL;
}

//--------------------------------------------------

/**
 * Get Bucket by Key
 *
 * @param hashTable - Getted Hashtable
 * @param key - Compared key
 *
 * @return Bucket in Hashtable
 */
BucketHashtable Hashtable_getBucket(const Hashtable hashTable, const String key)
{
  BucketHashtable bucket = hashTable[HashSolution_executeString(key, LENGTH_HASHTABLE)];
  while (bucket != NULL)
  {
    if (String_isEqualIgnoreCase(key, ElementHashtable_getKey(bucket->data)))
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
 * @param hashTable - Hashtable
 * @param element - Inserted Element
 */
void Hashtable_insertElement(Hashtable hashTable, const ElementHashtable element)
{
  size_t index = HashSolution_executeString(ElementHashtable_getKey(element), LENGTH_HASHTABLE);
  BucketHashtable currentBucket = hashTable[index];
  hashTable[index] = Bucket_create(element, currentBucket);
}

/**
 * Delete Element by key
 *
 * @param hashTable - Hashtable
 * @param key - Key of deleted Element
 */
void Hashtable_deleteElement(Hashtable hashTable, const String key)
{
  size_t index = HashSolution_executeString(key, LENGTH_HASHTABLE);
  if (hashTable[index] != NULL)
  {
    BucketHashtable currentBucket = hashTable[index];
    if (String_isEqualIgnoreCase(key, ElementHashtable_getKey(currentBucket->data)))
    {
      hashTable[index] = hashTable[index]->next;
      Bucket_destroy(currentBucket);
    }
    else
    {
      bool deleted = false;
      while (currentBucket->next != NULL && !deleted)
      {
        if (String_isEqualIgnoreCase(key, ElementHashtable_getKey(currentBucket->next->data)))
        {
          BucketHashtable nextBucket = currentBucket->next;
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
