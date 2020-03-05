#include <conio.h>
#include "./includes/dictionary.h"
#include "./includes/history.h"

int main()
{
    bool loop = true;
    Dictionary dictionary = Dictionary_create();
    History history = History_create();
    char cursor;

    Dictionary_loadData(dictionary);
    while (loop)
    {
        bool loopHistory;
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
                Word result = Dictionary_search(dictionary, english);
                Console_showSearchResult(result);
                History_insert(history, english, result == NULL ? "" : result->vietnamese);

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
                if (strlen(english) * strlen(vietnamese) > 0)
                {
                    if (Dictionary_insert(dictionary, english, vietnamese))
                    {
                        printf("\n\tThêm từ mới thành công.\n\n");
                    }
                    else
                    {
                        printf("\n\tThêm từ mới không thành công. Từ này đã có trong tự điển.\n\n");
                    }
                }
                else
                {
                    printf("\n\tThêm từ mới không thành công. Từ tiếng Anh và nghĩa tiếng Việt không được để trống.\n\n");
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
                if (strlen(english) > 0)
                {
                    if (Dictionary_delete(dictionary, english))
                    {
                        printf("\n\tXoá từ thành công.\n\n");
                    }
                    else
                    {
                        printf("\n\tXoá từ không thành công. Từ này không có trong tự điển.\n\n");
                    }
                }
                else
                {
                    printf("\n\tXoá từ không thành công. Vui lòng nhập từ tiếng Anh cần xoá.\n\n");
                }

                String_destroy(english);

                printf("\tNhấn phím Enter để tiếp tục chức năng Xoá từ.\n\tNhấn phím khác để trở về màn hình danh sách chức năng.");
            } while (getch() == 13);
            break;

        case '4':
            loopHistory = true;
            CursorHistory cursor = History_getCursor(history);
            while (loopHistory)
            {
                Console_showBrand();
                printf("\tLỊCH SỬ TRA CỨU TỪ\n");
                printf("\t*********************************************\n\n");

                if (cursor != NULL)
                {
                    Console_showSearchResult(History_getData(cursor));
                    printf("\tDùng 2 phím: w cho cuộn lên và s cho cuộn xuống để xem lịch sử.\n\tNhấn phím bất kì khác để trở về màn hình danh sách chức năng.");

                    switch (getch())
                    {
                    case 'w':
                        if (History_getNext(cursor) != NULL)
                        {
                            cursor = History_getNext(cursor);
                        }
                        break;

                    case 's':
                        if (History_getPrevious(cursor) != NULL)
                        {
                            cursor = History_getPrevious(cursor);
                        }
                        break;

                    default:
                        loopHistory = false;
                        break;
                    }
                }
                else
                {
                    printf("\tLịch sử trống\n\n");
                    printf("\tNhấn phím bất kì để trở về màn hình danh sách chức năng.");
                    getch();
                    loopHistory = false;
                }
            }
            break;

        default:
            break;
        }
    }

    History_destroy(history);
    Dictionary_destroy(dictionary);
    return 0;
}
