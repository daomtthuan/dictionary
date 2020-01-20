#ifndef _HASH_DEFINE_
#define _HASH_DEFINE_

#include "String.h"

//--------------------------------------------------

// Mod of separate
#define MOD_SEPARATE 100

//--------------------------------------------------

// Hash key by "Separate" solution
size_t Hash_separate(size_t code, const size_t length)
{
  size_t result = 0;
  while (code > 0)
  {
    result += code % MOD_SEPARATE;
    code /= MOD_SEPARATE;
  }
  return result % length;
}

// Hash key
size_t Hash_execute(const String key, const size_t length)
{
  size_t index = 0, code = 0;
  // Convert key (string) to number - summ ascii code number
  while (index < strlen(key))
  {
    code += tolower(key[index]);
    index++;
  }
  return Hash_separate(code, length);
}

#endif
