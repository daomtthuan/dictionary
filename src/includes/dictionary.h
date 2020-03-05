#ifndef _DICTIONARY_INCLUDE_
#define _DICTIONARY_INCLUDE_

#include "./hashtable/hashtable.h"
#include "./program/console.h"
#include "./program/config.h"

//--------------------------------------------------

// Dictionary type
typedef Hashtable Dictionary;

//--------------------------------------------------

/**
 * Create Dictionary
 *
 * @return New Dictionary
 */
Dictionary Dictionary_create()
{
  return Hashtable_create();
}

/**
 * Destroy Dictionary
 *
 * @param dictionary Destroyed Dictionary
 */
void Dictionary_destroy(Dictionary dictionary)
{
  Hashtable_destroy(dictionary);
}

//--------------------------------------------------

/**
 * Write data element in data file
 *
 * @param element - Each element
 * @param index - Index of each element
 */
void Dictionary_wirteData(Element element, size_t index)
{
  FILE *file = fopen(CONFIG_DATA_FILE, index == 0 ? "w" : "a");
  fputs(element->english, file);
  fputc('\n', file);

  fputs(element->vietnamese, file);
  fputc('\n', file);

  fclose(file);
  file = NULL;
}

/**
 * Insert Word
 *
 * @param dictionary - Dictionary
 * @param english - English meaning of inserted Word
 * @param vietnamese - Vietnamese meaning of inserted Word
 *
 * @return Insert result success or not
 */
bool Dictionary_insert(Dictionary dictionary, const String english, const String vietnamese)
{
  if (Hashtable_getNode(dictionary, english) == NULL)
  {
    if (Hashtable_insertElement(dictionary, Word_create(english, vietnamese)))
    {
      Hashtable_forEach(dictionary, Dictionary_wirteData);
      return true;
    }
  }

  return false;
}

/**
 * Delete Word
 *
 * @param dictionary - Dictionary
 * @param english - English meaning of Word
 *
 * @return Delete result success or not
 */
bool Dictionary_delete(Dictionary dictionary, const String english)
{
  if (Hashtable_getNode(dictionary, english) != NULL)
  {
    if (Hashtable_deleteElement(dictionary, english))
    {
      Hashtable_forEach(dictionary, Dictionary_wirteData);
      return true;
    }
  }

  return false;
}

/**
 * Load Word from data file
 *
 * @param dictionary - Dictionary
 */
void Dictionary_loadData(Dictionary dictionary)
{
  FILE *file = fopen(CONFIG_DATA_FILE, "r+");

  char cursor = fgetc(file);
  while (cursor != EOF)
  {
    int line = 0;
    String english = String_createEmpty();
    String vietnamese = String_createEmpty();

    while (line++ < 2)
    {
      while (cursor != '\n')
      {
        String_joinChar(line == 1 ? &english : &vietnamese, cursor);
        cursor = fgetc(file);
      }

      cursor = fgetc(file);
    }

    Hashtable_insertElement(dictionary, Word_create(english, vietnamese));
    String_destroy(english);
    String_destroy(vietnamese);
  }
  fclose(file);
}

/**
 * Search Word
 *
 * @param dictionary - Dictionary
 * @param english - English meaning of Word
 *
 * @return Search result found Word or NULL if not found
 */
Word Dictionary_search(Dictionary dictionary, const String english)
{
  NodeHashtable node = Hashtable_getNode(dictionary, english);
  if (node == NULL)
  {
    return NULL;
  }
  else
  {
    return node->data;
  }
}

#endif
