#ifndef _BUCKET_TYPE_INCLUDE_
#define _BUCKET_TYPE_INCLUDE_

#include "./node.h"

//--------------------------------------------------

// Bucket type
typedef Node *Bucket;

//--------------------------------------------------

/**
 * Create Bucket
 *
 * @param element - Element data
 *
 * @return - New Bucket
 */
Bucket Bucket_create(const Element data, const Bucket nextBucket)
{
  Bucket bucket = (Bucket)malloc(sizeof(Node));
  bucket->data = data;
  bucket->next = nextBucket;
  return bucket;
}

/**
 * Destroy Bucket
 *
 * @param bucket - Destroyed Bucket
 */
void Bucket_destroy(Bucket bucket)
{
  Word_destroy(bucket->data);
  free(bucket);
}

#endif
