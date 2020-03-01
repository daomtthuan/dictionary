#ifndef _NODE_TYPE_INCLUDE_
#define _NODE_TYPE_INCLUDE_

#include "./word.h"

//--------------------------------------------------

// Element type
typedef Word Element;

// Node struct
struct NodeStruct
{
  // Element
  Element data;

  // Next Node
  struct NodeStruct *next;
};

// Node type
typedef struct NodeStruct Node;

//--------------------------------------------------

/**
 * Get Key of Element
 *
 * @param element - Getted Element
 *
 * @return - Key of Element
 */
String Element_getKey(const Element element)
{
  return Word_getKey(element);
}

#endif
