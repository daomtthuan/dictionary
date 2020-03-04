#ifndef _NODE_HASHTABLE_INCLUDE_
#define _NODE_HASHTABLE_INCLUDE_

#include "../types/word.h"

//--------------------------------------------------

// Element type
typedef Word ElementHashtable;

// Node struct
struct NodeHashtableStruct
{
  // Element
  ElementHashtable data;

  // Next Node
  struct NodeHashtableStruct *next;
};

// Node type
typedef struct NodeHashtableStruct NodeHashtable;

//--------------------------------------------------

/**
 * Get Key of Element
 *
 * @param element - Getted Element
 *
 * @return - Key of Element
 */
String ElementHashtable_getKey(const ElementHashtable element)
{
  return element->english;
}

#endif
