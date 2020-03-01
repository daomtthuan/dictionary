#ifndef _DATA_SYSTEM_INCLUDE_
#define _DATA_SYSTEM_INCLUDE_

#include "./dictionary.h"

//--------------------------------------------------

// English File path
#define ENGLISH_FILE "../data/English.txt"

// Vietnamese File path
#define VIETNAMESE_FILE "../data/Vietnamese.txt"

// DataSystem struct
struct DataSystemtruct
{
  // English meaning file
  FILE *english;

  // Vietnamese meaning file
  FILE *vietnamese;
};

// DataSystem type
typedef struct DataSystemtruct *DataSystem;

//--------------------------------------------------

/**
 * Create DataSystem
 *
 * @return - new DataSystem
 */
DataSystem DataSystem_create()
{
  DataSystem dataSystem = (DataSystem)malloc(sizeof(struct DataSystemtruct));
  dataSystem->english = fopen(ENGLISH_FILE, "w+");
  dataSystem->vietnamese = fopen(VIETNAMESE_FILE, "w+");
  return dataSystem;
}

/**
 * Destroy DataSystem
 *
 * @param dataSystem - Destroyed DataSystem
 */
void DataSystem_destroy(DataSystem dataSystem)
{
  fclose(dataSystem->english);
  fclose(dataSystem->vietnamese);
  free(dataSystem->english);
  free(dataSystem->vietnamese);
  free(dataSystem);
}

// /**
//  * Load data file into Dictionary
//  *
//  * @param dictionary - dictionary
//  * @param dataSystem - Loaded DataSystem
//  */
// void DataSystem_load(Dictionary dictionary, DataSystem dataSystem)
// {
//   fp = fopen(filename, "r");
//   if (fp == NULL)
//   {
//     printf("Could not open file %s", filename);
//     return 1;
//   }
//   while (fgets(str, MAXCHAR, fp) != NULL)
//     printf("%s", str);
//   fclose(fp);
//   return 0;
// }

#endif