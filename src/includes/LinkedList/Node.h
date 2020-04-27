#ifndef _NODE_LINKEDLIST_INCLUDE_
#define _NODE_LINKEDLIST_INCLUDE_

#include "../Element.h"

//--------------------------------------------------

// Node Linked list struct
struct NodeLinkedListStruct
{
  // Element
  Word data;

  // Next Node
  struct NodeLinkedListStruct *next;

  // Previous Node
  struct NodeLinkedListStruct *previous;
};

// Node Linked list type
typedef struct NodeLinkedListStruct *NodeLinkedList;

//--------------------------------------------------

/**
 * Create Node Linked list
 *
 * @param element - Element data
 *
 * @return - New Node Linked list
 */
NodeLinkedList NodeLinkedList_Create(Word data)
{
  NodeLinkedList node = (NodeLinkedList)malloc(sizeof(struct NodeLinkedListStruct));
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
void NodeLinkedList_Destroy(NodeLinkedList node)
{
  Word_Destroy(node->data);
  free(node);
}

#endif
