#include "../define/Dictionary.h"
#include <stdio.h>

int main()
{
  Word word1, word2;
  Word_create(&word1, "English", "Tieng anh");
  Word_create(&word2, "Apple", "Qua tao");

  Dictionary dictionary;
  Dictionary_create(&dictionary);
  Dictionary_insert(&dictionary, word1);
  Dictionary_insert(&dictionary, word2);

  printf("%s\n", Dictionary_get(dictionary, word1.english));
  printf("%s\n", Dictionary_get(dictionary, word2.english));

  Dictionary_destroy(&dictionary);

  Word_destroy(&word1);
  Word_destroy(&word2);

  return 0;
}
