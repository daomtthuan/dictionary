#include "./includes/linkedlist/linkedlist.h"

int main(void)
{
  Linkedlist list = Linkedlist_create();

  Linkedlist_insert(list, Word_create("Hello 1", "Xin chào 1"));
  Linkedlist_insert(list, Word_create("Hello 2", "Xin chào 2"));

  NodeLinkedlist P = list->first;
  while (P != NULL)
  {
    puts(P->data->english);
    puts(P->data->vietnamese);
    P = P->next;
  }

  Linkedlist_destroy(list);
  return 0;
}
