#ifndef _DICTIONARY_INCLUDE_
#define _DICTIONARY_INCLUDE_

#include "./Config.h"
#include "./Console.h"
#include "./HashTable.h"

//--------------------------------------------------

// Dictionary type
typedef HashTable Dictionary;

//--------------------------------------------------

/**
 * Create Dictionary
 *
 * @return New Dictionary
 */
Dictionary Dictionary_Create() {
  return HashTable_Create();
}

/**
 * Destroy Dictionary
 *
 * @param dictionary Destroyed Dictionary
 */
void Dictionary_Destroy(Dictionary dictionary) {
  HashTable_Destroy(dictionary);
}

//--------------------------------------------------

/**
 * Write word data in data file
 *
 * @param word - Each word
 * @param index - Index of each word
 */
void Dictionary_WirteData(Word word, size_t index) {
  FILE *file = fopen(CONFIG_DATA_FILE, index == 0 ? "w" : "a");

  fputs(word->english, file);
  fputc('\n', file);

  fputs(word->vietnamese, file);
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
bool Dictionary_Insert(Dictionary dictionary, const String english, const String vietnamese) {
  if (HashTable_GetNode(dictionary, english) == NULL) {
    return HashTable_Insert(dictionary, Word_Create(english, vietnamese));
  }

  return false;
}

/**
 * Edit Word
 *
 * @param dictionary - Dictionary
 * @param english - English meaning of edited Word
 * @param vietnamese - Vietnamese meaning of edited Word
 *
 * @return Edit result success or not
 */
bool Dictionary_Edit(Dictionary dictionary, const String english, const String vietnamese) {
  if (HashTable_GetNode(dictionary, english) != NULL) {
    HashTable_Delete(dictionary, english);
    return HashTable_Insert(dictionary, Word_Create(english, vietnamese));
  }

  return false;
}

/**
 * Delete Word
 *
 * @param dictionary - Dictionary
 * @param english - English meaning of deleted Word
 *
 * @return Delete result success or not
 */
bool Dictionary_Delete(Dictionary dictionary, const String english) {
  if (HashTable_GetNode(dictionary, english) != NULL) {
    return HashTable_Delete(dictionary, english);
  }

  return false;
}

/**
 * Save Word into data file
 *
 * @param dictionary - Dictionary
 */
void Dictionary_SaveData(Dictionary dictionary) {
  HashTable_ForEach(dictionary, Dictionary_WirteData);
}

/**
 * Load Word from data file
 *
 * @param dictionary - Dictionary
 */
void Dictionary_LoadData(Dictionary dictionary) {
  FILE *file = fopen(CONFIG_DATA_FILE, "r");

  if (file != NULL) {
    char cursor = fgetc(file);
    while (cursor != EOF) {
      int line = 0;
      String english = String_CreateEmpty();
      String vietnamese = String_CreateEmpty();

      while (line++ < 2) {
        while (cursor != '\n') {
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
    file = NULL;
  }
}

/**
 * Search Word
 *
 * @param dictionary - Dictionary
 * @param english - English meaning of Word
 *
 * @return Search result found Word or NULL if not found
 */
Word Dictionary_Search(Dictionary dictionary, const String english) {
  NodeHashTable node = HashTable_GetNode(dictionary, english);
  if (node == NULL) {
    return NULL;
  } else {
    return node->data;
  }
}

#endif
