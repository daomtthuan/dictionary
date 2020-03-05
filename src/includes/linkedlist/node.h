#ifndef _NODE_LINKEDLIST_INCLUDE_
#define _NODE_LINKEDLIST_INCLUDE_

#include "../element.h"

//--------------------------------------------------

// Node Linked list struct
struct NodeLinkedlistStruct
{
  // Element
  Word data;

  // Next Node
  struct NodeLinkedlistStruct *next;

  // Previous Node
  struct NodeLinkedlistStruct *previous;
};

// Node Linked list type
typedef struct NodeLinkedlistStruct *NodeLinkedlist;

//--------------------------------------------------

/**
 * Create Node Linked list
 *
 * @param element - Element data
 *
 * @return - New Node Linked list
 */
NodeLinkedlist NodeLinkedlist_create(Word data)
{
  NodeLinkedlist node = (NodeLinkedlist)malloc(sizeof(struct NodeLinkedlistStruct));
  node->data = data;
  node->next = NULL;
  node->previous = NULL;
  return node;
}

/**
 * Destroy Node Linked list
 *
 * @param node - Destroyed node
 */
void NodeLinkedlist_destroy(NodeLinkedlist node)
{
  Word_destroy(node->data);
  free(node);
}

#endif
