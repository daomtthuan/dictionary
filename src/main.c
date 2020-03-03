#include "./includes/dictionary.h"

int main()
{
    bool loop = true;
    String word = String_create();
    Dictionary dictionary = Dictionary_create();
    Dictionary_loadData(dictionary);

    Program_welcome();
    while (loop)
    {
        Program_showMenu();
        fflush(stdin);
        switch (getchar())
        {
        case '0':
            loop = false;
            printf("\n Tạm biệt!");
            break;

        case '1':
            printf("\n Nhập từ muốn tra cứu: ");
            fflush(stdin);
            Program_searchResult(Dictionary_search(dictionary, gets(word)));
            break;

        case '2':

            break;

        case '3':

            break;

        case '4':

            break;

        default:
            break;
        }
    }

    String_destroy(word);
    Dictionary_destroy(dictionary);
    return 0;
}
