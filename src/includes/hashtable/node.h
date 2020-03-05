#ifndef _NODE_HASHTABLE_INCLUDE_
#define _NODE_HASHTABLE_INCLUDE_

#include "../element.h"

//--------------------------------------------------

// Node Hash Table struct
struct NodeHashtableStruct
{
  // Element
  Element data;

  // Next Node
  struct NodeHashtableStruct *next;
};

// Node Hash table type
typedef struct NodeHashtableStruct NodeHashtable;

//--------------------------------------------------

/**
 * Create Node Hash table
 *
 * @param element - Element data
 *
 * @return - New Node Hash table
 */
BucketHashtable BucketHashtable_create(const Element data, const BucketHashtable nextBucket)
{
  BucketHashtable bucket = (BucketHashtable)malloc(sizeof(NodeHashtable));
  bucket->data = data;
  bucket->next = nextBucket;
  return bucket;
}

/**
 * Destroy Node Hash table
 *
 * @param node - Destroyed Node
 */
void BucketHashtable_destroy(BucketHashtable bucket)
{
  Word_destroy(bucket->data);
  free(bucket);
}

#endif
