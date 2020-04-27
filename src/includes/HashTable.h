#ifndef _HASHTABLE_INCLUDE_
#define _HASHTABLE_INCLUDE_

#include "./HashTable/Solution.h"

//--------------------------------------------------

// Length of Hash Table
#define LENGTH_HASHTABLE 100

// Hash Table type
typedef NodeHashTable *HashTable;

//--------------------------------------------------

/**
 * Create Hash Table
 *
 * @return - New Hash Table with null Nodes bucket
 */
HashTable HashTable_Create()
{
  HashTable hashtable = (HashTable)malloc(sizeof(NodeHashTable) * LENGTH_HASHTABLE);
  size_t index = 0;
  while (index < LENGTH_HASHTABLE)
  {
    hashtable[index] = NULL;
    index++;
  }
  return hashtable;
}

/**
 * Destroy Hash Table
 *
 * @param hashtable - Destroyed HastaTable
 */
void HashTable_Destroy(HashTable hashtable)
{
  size_t index = 0;
  while (index < LENGTH_HASHTABLE)
  {
    while (hashtable[index] != NULL)
    {
      NodeHashTable node = hashtable[index]->next;
      NodeHashTable_Destroy(hashtable[index]);
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
 * @param hashtable - Getted Hash Table
 * @param key - Compared key
 *
 * @return Node in Hash Table
 */
NodeHashTable HashTable_GetNode(const HashTable hashtable, const String key)
{
  NodeHashTable node = hashtable[HashSolution_HashString(key, LENGTH_HASHTABLE)];
  while (node != NULL)
  {
    if (String_IsEqualIgnoreCase(key, Element_GetKey(node->data)))
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
 * @param hashtable - Hash Table
 * @param element - Inserted Element
 *
 * @return Bool result of success or not
 */
bool HashTable_Insert(HashTable hashtable, const Element element)
{
  size_t index = HashSolution_HashString(Element_GetKey(element), LENGTH_HASHTABLE);
  NodeHashTable currentNode = hashtable[index];
  hashtable[index] = NodeHashTable_Create(element, currentNode);
  return true;
}

/**
 * Delete Element by key
 *
 * @param hashtable - Hash Table
 * @param key - Key of deleted Element
 *
 * @return Bool result of success or not
 */
bool HashTable_Delete(HashTable hashtable, const String key)
{
  size_t index = HashSolution_HashString(key, LENGTH_HASHTABLE);
  if (hashtable[index] != NULL)
  {
    NodeHashTable currentNode = hashtable[index];
    if (String_IsEqualIgnoreCase(key, Element_GetKey(currentNode->data)))
    {
      hashtable[index] = hashtable[index]->next;
      NodeHashTable_Destroy(currentNode);
      return true;
    }
    else
    {
      bool deleted = false;
      while (currentNode->next != NULL && !deleted)
      {
        if (String_IsEqualIgnoreCase(key, Element_GetKey(currentNode->next->data)))
        {
          NodeHashTable nextNode = currentNode->next;
          currentNode->next = nextNode->next;
          NodeHashTable_Destroy(nextNode);
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
 * @param hashtable - Hash Table
 * @param action - Action do with each Element - Function with 2 args is element and index of element
 *
 * --- @param _element - Element in action
 * --- @param _index - Index element in action
 */
void HashTable_ForEach(const HashTable hashtable, void (*action)(Element _element, size_t _index))
{
  NodeHashTable node;
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
