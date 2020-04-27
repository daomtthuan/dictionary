#ifndef _HISTORY_INCLUDE_
#define _HISTORY_INCLUDE_

#include "./LinkedList.h"

//--------------------------------------------------

// History type
typedef LinkedList History;

// CursorHistory type
typedef NodeLinkedList CursorHistory;

//--------------------------------------------------

/**
 * Create History
 *
 * @return New History
 */
History History_Create()
{
  return LinkedList_Create();
}

/**
 * Destroy History
 *
 * @param history Destroyed History
 */
void History_Destroy(History history)
{
  LinkedList_Destroy(history);
}

//--------------------------------------------------

/**
 * Insert element into History
 *
 * @param history History
 * @param english English word
 * @param vietnamese Vietnamese meaning
 */
void History_Insert(History history, String english, String vietnamese)
{
  LinkedList_Insert(history, Word_Create(english, vietnamese));
}

//--------------------------------------------------

/**
 * Get data at the cursor history
 *
 * @param cursor Cursor History
 *
 * @return Word at cursor history
 */
Word History_GetData(CursorHistory cursor)
{
  return cursor->data;
}

/**
 * Get Cursor History
 *
 * @param history History
 *
 * @return Cursor History
 */
CursorHistory History_GetCursor(History history)
{
  return history->head;
}

/**
 * Get next at the cursor history
 *
 * @param cursor Cursor History
 *
 * @return The next at Cursor History
 */
CursorHistory History_Next(CursorHistory cursor)
{
  return cursor->next;
}

/**
 * Get previous at the cursor history
 *
 * @param cursor Cursor History
 *
 * @return The previous at Cursor History
 */
CursorHistory History_Previous(CursorHistory cursor)
{
  return cursor->previous;
}

#endif
