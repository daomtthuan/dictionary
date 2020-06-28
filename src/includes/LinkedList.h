#ifndef _LINKEDLIST_INCLUDE_
#define _LINKEDLIST_INCLUDE_

#include "./LinkedList/Node.h"

//--------------------------------------------------

// Linked list struct
struct LinkedListStruct {
  // Header cursor node
  NodeLinkedList head;

  // Last cursor node
  NodeLinkedList tail;
};

// Linked list type
typedef struct LinkedListStruct *LinkedList;

//--------------------------------------------------

/**
 * Create Linked list
 *
 * @return - New Linked list
 */
LinkedList LinkedList_Create() {
  LinkedList list = (LinkedList)malloc(sizeof(struct LinkedListStruct));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

/**
 * Destroy Linked list
 *
 * @param list - Destroyed Linked list
 */
void LinkedList_Destroy(LinkedList list) {
  while (list->head != NULL) {
    NodeLinkedList node = list->head;
    list->head = list->head->next;
    NodeLinkedList_Destroy(node);
  }
  free(list);
}

//--------------------------------------------------

/**
 * Insert data into Linked list
 *
 * @param element - Data
 */
void LinkedList_Insert(LinkedList list, Word data) {
  NodeLinkedList node = NodeLinkedList_Create(data);
  if (list->head == NULL) {
    list->head = node;
    list->tail = node;
  } else {
    node->next = list->head;
    list->head->previous = node;
    list->head = node;
  }
}

#endif
