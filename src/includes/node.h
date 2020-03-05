#ifndef _NODE_INCLUDE_
#define _NODE_INCLUDE_

#include "./element.h"

//--------------------------------------------------

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

#endif
