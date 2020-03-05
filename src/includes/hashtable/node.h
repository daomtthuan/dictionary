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
typedef struct NodeHashtableStruct *NodeHashtable;

//--------------------------------------------------

/**
 * Create Node Hash table
 *
 * @param element - Element data
 * @param nextNode - Next node
 *
 * @return - New Node Hash table
 */
NodeHashtable NodeHashtable_create(const Element data, const NodeHashtable nextNode)
{
  NodeHashtable node = (NodeHashtable)malloc(sizeof(struct NodeHashtableStruct));
  node->data = data;
  node->next = nextNode;
  return node;
}

/**
 * Destroy Node Hash table
 *
 * @param node - Destroyed Node
 */
void NodeHashtable_destroy(NodeHashtable node)
{
  Word_destroy(node->data);
  free(node);
}

#endif
