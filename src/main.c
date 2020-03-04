#include "./includes/program/dictionary.h"

int main()
{
    bool loop = true;
    char english[256];
    Dictionary dictionary = Dictionary_create();
    char cursor;

    Dictionary_loadData(dictionary);

    Console_showWelcome();
    while (loop)
    {
        Console_showMenu();
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
            Console_showSearchResult(Dictionary_search(dictionary, gets(english)));
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

    Dictionary_destroy(dictionary);
    return 0;
}
