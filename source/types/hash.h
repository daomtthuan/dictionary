#ifndef _HASH_TYPE_INCLUDE_
#define _HASH_TYPE_INCLUDE_

#include "./bucket.h"

//--------------------------------------------------

// Mod of separate
#define MOD_SEPARATE 100

//--------------------------------------------------

/**
 * Hash code number to index of Bucket by "Separate" solution
 *
 * @param code number code
 * @param length length pf HashTable
 *
 * @return the index of Bucket in HashTable
 */
size_t Hash_separate(size_t code, size_t length)
{
  size_t result = 0;
  while (code > 0)
  {
    result += code % MOD_SEPARATE;
    code /= MOD_SEPARATE;
  }
  return result % length;
}

/**
 * Hash key element to index of Bucket in HashTable
 *
 * @param key Key of Element
 * @param length length pf HashTable
 *
 * @return the index of Bucket in HashTable
 */
size_t Hash_execute(const String key, size_t length)
{
  size_t index = 0, code = 0;
  // Convert key (string) to ncode umber by "sum ascii code number" solution
  while (index < strlen(key))
  {
    code += tolower(key[index]);
    index++;
  }
  return Hash_separate(code, length);
}

#endif
