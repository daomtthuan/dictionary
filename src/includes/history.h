#ifndef _HISTORY_INCLUDE_
#define _HISTORY_INCLUDE_

#include "./linkedlist/linkedlist.h"

//--------------------------------------------------

// History type
typedef Linkedlist History;

// CursorHistory type
typedef NodeLinkedlist CursorHistory;

//--------------------------------------------------

/**
 * Create History
 *
 * @return New History
 */
History History_create()
{
  return Linkedlist_create();
}

/**
 * Destroy History
 *
 * @param history Destroyed History
 */
void History_destroy(History history)
{
  Linkedlist_destroy(history);
}

//--------------------------------------------------

/**
 * Insert element into History
 *
 * @param history History
 * @param english English word
 * @param vietnamese Vietnamese meaning
 */
void History_insert(History history, String english, String vietnamese)
{
  Linkedlist_insert(history, Word_create(english, vietnamese));
}

//--------------------------------------------------

/**
 * Get data at the cursor history
 *
 * @param cursor Cursor History
 *
 * @return Word at cursor history
 */
Word History_getData(CursorHistory cursor)
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
CursorHistory History_getCursor(History history)
{
  return history->first;
}

/**
 * Get next at the cursor history
 *
 * @param cursor Cursor History
 *
 * @return The next at Cursor History
 */
CursorHistory History_getNext(CursorHistory cursor)
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
CursorHistory History_getPrevious(CursorHistory cursor)
{
  return cursor->previous;
}

#endif
