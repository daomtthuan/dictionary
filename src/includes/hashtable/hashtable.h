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
  Hashtable hashtable = (Hashtable)malloc(sizeof(BucketHashtable) * LENGTH_HASHTABLE);
  size_t index = 0;
  while (index < LENGTH_HASHTABLE)
  {
    hashtable[index] = NULL;
    index++;
  }
  return hashtable;
}

/**
 * Destroy Hashtable
 *
 * @param hashtable - Destroyed HastaTable
 */
void Hashtable_destroy(Hashtable hashtable)
{
  size_t index = 0;
  while (index < LENGTH_HASHTABLE)
  {
    while (hashtable[index] != NULL)
    {
      BucketHashtable bucket = hashtable[index]->next;
      BucketHashtable_destroy(hashtable[index]);
      hashtable[index] = bucket;
    }
    index++;
  }
  free(hashtable);
}

//--------------------------------------------------

/**
 * Get Bucket by Key
 *
 * @param hashtable - Getted Hashtable
 * @param key - Compared key
 *
 * @return Bucket in Hashtable
 */
BucketHashtable Hashtable_getBucket(const Hashtable hashtable, const String key)
{
  BucketHashtable bucket = hashtable[HashSolution_executeString(key, LENGTH_HASHTABLE)];
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
 * @param hashtable - Hashtable
 * @param element - Inserted Element
 *
 * @return Bool result of success or not
 */
bool Hashtable_insertElement(Hashtable hashtable, const Element element)
{
  size_t index = HashSolution_executeString(Element_getKey(element), LENGTH_HASHTABLE);
  BucketHashtable currentBucket = hashtable[index];
  hashtable[index] = BucketHashtable_create(element, currentBucket);
  return true;
}

/**
 * Delete Element by key
 *
 * @param hashtable - Hashtable
 * @param key - Key of deleted Element
 *
 * @return Bool result of success or not
 */
bool Hashtable_deleteElement(Hashtable hashtable, const String key)
{
  size_t index = HashSolution_executeString(key, LENGTH_HASHTABLE);
  if (hashtable[index] != NULL)
  {
    BucketHashtable currentBucket = hashtable[index];
    if (String_isEqualIgnoreCase(key, Element_getKey(currentBucket->data)))
    {
      hashtable[index] = hashtable[index]->next;
      BucketHashtable_destroy(currentBucket);
      return true;
    }
    else
    {
      bool deleted = false;
      while (currentBucket->next != NULL && !deleted)
      {
        if (String_isEqualIgnoreCase(key, Element_getKey(currentBucket->next->data)))
        {
          BucketHashtable nextBucket = currentBucket->next;
          currentBucket->next = nextBucket->next;
          BucketHashtable_destroy(nextBucket);
          deleted = true;
        }
        else
        {
          currentBucket = currentBucket->next;
        }
      }
      return deleted;
    }
  }
  return false;
}

/**
 * For each Element with do action
 *
 * @param hashtable - Hashtable
 * @param action - Action do with each Element - Function with 2 args is element and index of element
 *
 * --- @param _element - Element in action
 * --- @param _index - Index element in action
 */
void Hashtable_forEach(const Hashtable hashtable, void (*action)(Element _element, size_t _index))
{
  BucketHashtable bucket;
  size_t indexBucket = 0;
  size_t index = 0;
  while (indexBucket < LENGTH_HASHTABLE)
  {
    bucket = hashtable[indexBucket++];
    while (bucket != NULL)
    {
      action(bucket->data, index++);
      bucket = bucket->next;
    }
  }
}

#endif
