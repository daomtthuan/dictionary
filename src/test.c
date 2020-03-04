#include "./includes/program/config.h"
#include "./includes/program/dictionary.h"

void write(ElementHashtable element, size_t index)
{
  printf("%d %s - %s\n", index, element->english, element->vietnamese);
}

int main()
{
  Dictionary dictionary = Dictionary_create();

  Dictionary_loadData(dictionary, CONFIG_DATA_FILE);

  Hashtable_forEach(dictionary, write);

  Dictionary_destroy(dictionary);
  return 0;
}
