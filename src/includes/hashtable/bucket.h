#ifndef _BUCKET_HASHTABLE_INCLUDE_
#define _BUCKET_HASHTABLE_INCLUDE_

#include "./node.h"

//--------------------------------------------------

// Bucket type
typedef NodeHashtable *BucketHashtable;

//--------------------------------------------------

/**
 * Create Bucket
 *
 * @param element - Element data
 *
 * @return - New Bucket
 */
BucketHashtable BucketHashtable_create(const ElementHashtable data, const BucketHashtable nextBucket)
{
  BucketHashtable bucket = (BucketHashtable)malloc(sizeof(NodeHashtable));
  bucket->data = data;
  bucket->next = nextBucket;
  return bucket;
}

/**
 * Destroy Bucket
 *
 * @param bucket - Destroyed Bucket
 */
void BucketHashtable_destroy(BucketHashtable bucket)
{
  Word_destroy(bucket->data);
  free(bucket);
}

#endif
