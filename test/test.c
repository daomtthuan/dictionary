#include "../source/includes/types/dictionary.h"

int main()
{
  Dictionary dictionary = Dictionary_create();
  Dictionary_insert(dictionary, "English", "", "Tieng anh 1");
  Dictionary_insert(dictionary, "nglish", "", "Tieng anh 2");

  Dictionary_search(dictionary, "English");
  Dictionary_search(dictionary, "sad");
  Dictionary_search(dictionary, "NgLish");

  Dictionary_destroy(dictionary);
  getchar();
  return 0;
}
