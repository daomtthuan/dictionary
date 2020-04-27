#ifndef _NODE_HASHTABLE_INCLUDE_
#define _NODE_HASHTABLE_INCLUDE_

#include "../Element.h"

//--------------------------------------------------

// Node Hash Table struct
struct NodeHashTableStruct
{
  // Element
  Element data;

  // Next Node
  struct NodeHashTableStruct *next;
};

// Node Hash table type
typedef struct NodeHashTableStruct *NodeHashTable;

//--------------------------------------------------

/**
 * Create Node Hash table
 *
 * @param element - Element data
 * @param nextNode - Next node
 *
 * @return - New Node Hash table
 */
NodeHashTable NodeHashTable_Create(const Element data, const NodeHashTable nextNode)
{
  NodeHashTable node = (NodeHashTable)malloc(sizeof(struct NodeHashTableStruct));
  node->data = data;
  node->next = nextNode;
  return node;
}

/**
 * Destroy Node Hash table
 *
 * @param node - Destroyed Node
 */
void NodeHashTable_Destroy(NodeHashTable node)
{
  Word_Destroy(node->data);
  free(node);
}

#endif
