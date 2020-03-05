#include "./includes/dictionary.h"

int main()
{
    bool loop = true;
    Dictionary dictionary = Dictionary_create();
    char cursor;

    Dictionary_loadData(dictionary);
    while (loop)
    {
        Console_showBrand();
        Console_showMenu();

        fflush(stdin);
        switch (getchar())
        {
        case '0':
            loop = false;
            Console_showBrand();
            printf("\tTạm biệt!");
            fflush(stdin);
            getchar();
            break;

        case '1':
            while (true)
            {
                Console_showFunction("TRA CỨU TỰ ĐIỂN");
                printf("\tNhập từ tiếng Anh muốn tra cứu: ");
                String english = String_input();
                if (english[0] == '~')
                {
                    String_destroy(english);
                    break;
                }
                else
                {
                    Console_showSearchResult(Dictionary_search(dictionary, english));
                    String_destroy(english);

                    printf("\tNhấn Enter để tiếp tục.");
                    fflush(stdin);
                    getchar();
                }
            }
            break;

        case '2':
            while (true)
            {
                Console_showFunction("THÊM TỪ MỚI");

                printf("\n\tNhập từ mới tiếng Anh: ");
                String english = String_input();

                if (english[0] == '~')
                {
                    String_destroy(english);
                    break;
                }
                else
                {
                    printf("\tNhập nghĩa tiếng Việt: ");
                    String vietnamese = String_input();

                    if (Dictionary_insert(dictionary, english, vietnamese))
                    {
                        printf("\n\tThêm từ mới thành công.\n\n");
                    }
                    else
                    {
                        printf("\n\tThêm từ mới không thành công. Từ này đã có trong tự điển.\n\n");
                    }

                    String_destroy(english);
                    String_destroy(vietnamese);

                    printf("\tNhấn Enter để tiếp tục.");
                    fflush(stdin);
                    getchar();
                }
            }

            break;

        case '3':
            while (true)
            {
                Console_showFunction("XOÁ TỪ");

                printf("\n\tNhập từ tiếng Anh cần xoá: ");
                String english = String_input();

                if (english[0] == '~')
                {
                    String_destroy(english);
                    break;
                }
                else
                {
                    if (Dictionary_delete(dictionary, english))
                    {
                        printf("\n\tXoá từ thành công.\n\n");
                    }
                    else
                    {
                        printf("\n\tXoá từ không thành công. Từ này không có trong tự điển.\n\n");
                    }

                    String_destroy(english);

                    printf("\tNhấn Enter để tiếp tục.");
                    fflush(stdin);
                    getchar();
                }
            }
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
