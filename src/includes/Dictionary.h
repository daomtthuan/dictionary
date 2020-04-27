#ifndef _DICTIONARY_INCLUDE_
#define _DICTIONARY_INCLUDE_

#include "./HashTable.h"
#include "./Console.h"
#include "./Config.h"

//--------------------------------------------------

// Dictionary type
typedef HashTable Dictionary;

//--------------------------------------------------

/**
 * Create Dictionary
 *
 * @return New Dictionary
 */
Dictionary Dictionary_Create()
{
  return HashTable_Create();
}

/**
 * Destroy Dictionary
 *
 * @param dictionary Destroyed Dictionary
 */
void Dictionary_Destroy(Dictionary dictionary)
{
  HashTable_Destroy(dictionary);
}

//--------------------------------------------------

/**
 * Write data element in data file
 *
 * @param element - Each element
 * @param index - Index of each element
 */
void Dictionary_WirteData(Element element, size_t index)
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
bool Dictionary_Insert(Dictionary dictionary, const String english, const String vietnamese)
{
  if (HashTable_GetNode(dictionary, english) == NULL)
  {
    if (HashTable_Insert(dictionary, Word_Create(english, vietnamese)))
    {
      HashTable_ForEach(dictionary, Dictionary_WirteData);
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
bool Dictionary_Delete(Dictionary dictionary, const String english)
{
  if (HashTable_GetNode(dictionary, english) != NULL)
  {
    if (HashTable_Delete(dictionary, english))
    {
      HashTable_ForEach(dictionary, Dictionary_WirteData);
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
void Dictionary_LoadData(Dictionary dictionary)
{
  FILE *file = fopen(CONFIG_DATA_FILE, "r+");

  char cursor = fgetc(file);
  while (cursor != EOF)
  {
    int line = 0;
    String english = String_CreateEmpty();
    String vietnamese = String_CreateEmpty();

    while (line++ < 2)
    {
      while (cursor != '\n')
      {
        String_Push(line == 1 ? &english : &vietnamese, cursor);
        cursor = fgetc(file);
      }

      cursor = fgetc(file);
    }

    HashTable_Insert(dictionary, Word_Create(english, vietnamese));
    String_Destroy(english);
    String_Destroy(vietnamese);
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
Word Dictionary_Search(Dictionary dictionary, const String english)
{
  NodeHashTable node = HashTable_GetNode(dictionary, english);
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
