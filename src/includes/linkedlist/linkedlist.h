#ifndef _LINKEDLIST_INCLUDE_
#define _LINKEDLIST_INCLUDE_

#include "./node.h"

//--------------------------------------------------

// Linked list struct
struct LinkedlistStruct
{
  // Firt cursor node
  NodeLinkedlist first;

  // Last cursor node
  NodeLinkedlist last;
};

// Linked list type
typedef struct LinkedlistStruct *Linkedlist;

//--------------------------------------------------

/**
 * Create Linked list
 *
 * @return - New Linked list
 */
Linkedlist Linkedlist_create()
{
  Linkedlist list = (Linkedlist)malloc(sizeof(struct LinkedlistStruct));
  list->first = NULL;
  list->last = NULL;
  return list;
}

/**
 * Destroy Linked list
 *
 * @param list - Destroyed Linked list
 */
void Linkedlist_destroy(Linkedlist list)
{
  while (list->first != NULL)
  {
    NodeLinkedlist node = list->first;
    list->first = list->first->next;
    free(node);
  }
  free(list);
}

//--------------------------------------------------

/**
 * Insert data into Linked list
 *
 * @param element - Data
 */
void Linkedlist_insert(Linkedlist list, Element element)
{
  NodeLinkedlist node = NodeLinkedlist_create(element);
  if (list->first == NULL)
  {
    list->first = node;
    list->last = node;
  }
  else
  {
    node->next = list->first;
    list->first->previous = node;
    list->first = node;
  }
}

#endif
