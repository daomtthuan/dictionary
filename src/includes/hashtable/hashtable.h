#ifndef _HASHTABLE_INCLUDE_
#define _HASHTABLE_INCLUDE_

#include "./solution.h"

//--------------------------------------------------

// Length of Hash Table
#define LENGTH_HASHTABLE 100

// Hashtable type
typedef NodeHashtable *Hashtable;

//--------------------------------------------------

/**
 * Create Hashtable
 *
 * @return - New Hashtable with null Nodes bucket
 */
Hashtable Hashtable_create()
{
  Hashtable hashtable = (Hashtable)malloc(sizeof(NodeHashtable) * LENGTH_HASHTABLE);
  size_t index = 0;
  while (index < LENGTH_HASHTABLE)
  {
    hashtable[index] = NULL;
    index++;
  }
  return hashtable;
}

/**
 * Destroy Hashtable
 *
 * @param hashtable - Destroyed HastaTable
 */
void Hashtable_destroy(Hashtable hashtable)
{
  size_t index = 0;
  while (index < LENGTH_HASHTABLE)
  {
    while (hashtable[index] != NULL)
    {
      NodeHashtable node = hashtable[index]->next;
      NodeHashtable_destroy(hashtable[index]);
      hashtable[index] = node;
    }
    index++;
  }
  free(hashtable);
}

//--------------------------------------------------

/**
 * Get Node by Key
 *
 * @param hashtable - Getted Hashtable
 * @param key - Compared key
 *
 * @return Node in Hashtable
 */
NodeHashtable Hashtable_getNode(const Hashtable hashtable, const String key)
{
  NodeHashtable node = hashtable[HashSolution_executeString(key, LENGTH_HASHTABLE)];
  while (node != NULL)
  {
    if (String_isEqualIgnoreCase(key, Element_getKey(node->data)))
    {
      return node;
    }
    else
    {
      node = node->next;
    }
  }
  return NULL;
}

/**
 * Insert Element
 *
 * @param hashtable - Hashtable
 * @param element - Inserted Element
 *
 * @return Bool result of success or not
 */
bool Hashtable_insertElement(Hashtable hashtable, const Element element)
{
  size_t index = HashSolution_executeString(Element_getKey(element), LENGTH_HASHTABLE);
  NodeHashtable currentNode = hashtable[index];
  hashtable[index] = NodeHashtable_create(element, currentNode);
  return true;
}

/**
 * Delete Element by key
 *
 * @param hashtable - Hashtable
 * @param key - Key of deleted Element
 *
 * @return Bool result of success or not
 */
bool Hashtable_deleteElement(Hashtable hashtable, const String key)
{
  size_t index = HashSolution_executeString(key, LENGTH_HASHTABLE);
  if (hashtable[index] != NULL)
  {
    NodeHashtable currentNode = hashtable[index];
    if (String_isEqualIgnoreCase(key, Element_getKey(currentNode->data)))
    {
      hashtable[index] = hashtable[index]->next;
      NodeHashtable_destroy(currentNode);
      return true;
    }
    else
    {
      bool deleted = false;
      while (currentNode->next != NULL && !deleted)
      {
        if (String_isEqualIgnoreCase(key, Element_getKey(currentNode->next->data)))
        {
          NodeHashtable nextNode = currentNode->next;
          currentNode->next = nextNode->next;
          NodeHashtable_destroy(nextNode);
          deleted = true;
        }
        else
        {
          currentNode = currentNode->next;
        }
      }
      return deleted;
    }
  }
  return false;
}

/**
 * For each Element with do action
 *
 * @param hashtable - Hashtable
 * @param action - Action do with each Element - Function with 2 args is element and index of element
 *
 * --- @param _element - Element in action
 * --- @param _index - Index element in action
 */
void Hashtable_forEach(const Hashtable hashtable, void (*action)(Element _element, size_t _index))
{
  NodeHashtable node;
  size_t indexBucket = 0;
  size_t index = 0;
  while (indexBucket < LENGTH_HASHTABLE)
  {
    node = hashtable[indexBucket++];
    while (node != NULL)
    {
      action(node->data, index++);
      node = node->next;
    }
  }
}

#endif
