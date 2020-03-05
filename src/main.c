#include <conio.h>
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

        switch (getch())
        {
        case '0':
            loop = false;
            Console_showBrand();
            printf("\tTạm biệt!");
            getch();
            break;

        case '1':
            do
            {
                Console_showFunction("TRA CỨU TỪ");
                printf("\tNhập từ tiếng Anh muốn tra cứu: ");
                String english = String_input();

                Console_showFunction("TRA CỨU TỪ");
                Console_showSearchResult(Dictionary_search(dictionary, english));
                String_destroy(english);

                printf("\tNhấn phím Enter để tiếp tục chức năng Tra cứu từ.\n\tNhấn phím khác để trở về màn hình danh sách chức năng.");
            } while (getch() == 13);
            break;

        case '2':
            do
            {
                Console_showFunction("THÊM TỪ MỚI");

                printf("\n\tNhập từ mới tiếng Anh: ");
                String english = String_input();

                printf("\tNhập nghĩa tiếng Việt: ");
                String vietnamese = String_input();

                Console_showFunction("THÊM TỪ MỚI");
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

                printf("\tNhấn phím Enter để tiếp tục chức năng Thêm từ mới.\n\tNhấn phím khác để trở về màn hình danh sách chức năng.");
            } while (getch() == 13);
            break;

        case '3':
            do
            {
                Console_showFunction("XOÁ TỪ");

                printf("\n\tNhập từ tiếng Anh cần xoá: ");
                String english = String_input();

                Console_showFunction("XOÁ TỪ");
                if (Dictionary_delete(dictionary, english))
                {
                    printf("\n\tXoá từ thành công.\n\n");
                }
                else
                {
                    printf("\n\tXoá từ không thành công. Từ này không có trong tự điển.\n\n");
                }

                String_destroy(english);

                printf("\tNhấn phím Enter để tiếp tục chức năng Xoá từ.\n\tNhấn phím khác để trở về màn hình danh sách chức năng.");
            } while (getch() == 13);
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
