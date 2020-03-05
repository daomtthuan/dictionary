#ifndef _SOLUTION_HASHTABLE_INCLUDE_
#define _SOLUTION_HASHTABLE_INCLUDE_

#include "./bucket.h"

//--------------------------------------------------

// Mod of separate
#define HASH_SOLUTION_MOD_SEPARATE 100

//--------------------------------------------------

/**
 * Hash code number to index of Bucket by "Separate" solution
 *
 * @param code number code
 * @param length length pf Hashtable
 *
 * @return the index of Bucket in Hashtable
 */
size_t HashSolution_executeNumber(size_t code, size_t length)
{
  size_t result = 0;
  while (code > 0)
  {
    result += code % HASH_SOLUTION_MOD_SEPARATE;
    code /= HASH_SOLUTION_MOD_SEPARATE;
  }
  return result % length;
}

/**
 * Hash key element to index of Bucket in Hashtable
 *
 * @param key Key of Element
 * @param length length pf Hashtable
 *
 * @return the index of Bucket in Hashtable
 */
size_t HashSolution_executeString(const String key, size_t length)
{
  size_t index = 0, code = 0;
  // Convert key (string) to ncode umber by "sum ascii code number" solution
  while (index < strlen(key))
  {
    code += tolower(key[index]);
    index++;
  }
  return HashSolution_executeNumber(code, length);
}

#endif
