#ifndef _DATA_INCLUDE_
#define _DATA_INCLUDE_

#include "./dictionary.h"

//--------------------------------------------------

// English File path
#define ENGLISH_FILE "../data/English.txt"

// Vietnamese File path
#define VIETNAMESE_FILE "../data/Vietnamese.txt"

// DataSystem struct
struct Datatruct
{
  // English meaning file
  FILE *english;

  // Vietnamese meaning file
  FILE *vietnamese;
};

// DataSystem type
typedef struct Datatruct *Data;

//--------------------------------------------------

/**
 * Create Data
 *
 * @return - new Data
 */
Data Data_create()
{
  Data dataSystem = (Data)malloc(sizeof(struct Datatruct));
  dataSystem->english = fopen(ENGLISH_FILE, "w+");
  dataSystem->vietnamese = fopen(VIETNAMESE_FILE, "w+");
  return dataSystem;
}

/**
 * Destroy Data
 *
 * @param dataSystem - Destroyed Data
 */
void Data_destroy(Data data)
{
  fclose(data->english);
  fclose(data->vietnamese);
  free(data->english);
  free(data->vietnamese);
  free(data);
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