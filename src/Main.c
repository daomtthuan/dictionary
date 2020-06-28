#include <conio.h>

#include "./includes/Dictionary.h"
#include "./includes/History.h"

int main() {
  bool loop = true;
  Dictionary dictionary = Dictionary_Create();
  History history = History_Create();
  char cursor;

  Dictionary_LoadData(dictionary);
  while (loop) {
    bool loopHistory;
    Console_ShowTitle();
    Console_ShowMenu();

    switch (getch()) {
      case '0':
        loop = false;
        Console_ShowTitle();
        printf("\tTạm biệt!");
        getch();
        break;

      case '1':
        do {
          Console_ShowFunction("TRA CỨU TỪ");
          printf("\tNhập từ tiếng Anh muốn tra cứu: ");
          String english = String_Input();

          Console_ShowFunction("TRA CỨU TỪ");
          Word result = Dictionary_Search(dictionary, english);
          Console_ShowSearchResult(result);
          History_Insert(history, english, result == NULL ? "" : result->vietnamese);

          String_Destroy(english);

          printf("\tNhấn phím Enter để tiếp tục chức năng Tra cứu từ.\n\tNhấn phím khác để trở về màn hình danh sách chức năng.");
        } while (getch() == 13);
        break;

      case '2':
        do {
          Console_ShowFunction("THÊM TỪ MỚI");

          printf("\n\tNhập từ mới tiếng Anh: ");
          String english = String_Input();

          printf("\tNhập nghĩa tiếng Việt: ");
          String vietnamese = String_Input();

          Console_ShowFunction("THÊM TỪ MỚI");
          if (strlen(english) * strlen(vietnamese) > 0) {
            if (Dictionary_Insert(dictionary, english, vietnamese)) {
              printf("\n\tThêm từ mới thành công.\n\n");
            } else {
              printf("\n\tThêm từ mới không thành công. Từ này đã có trong tự điển.\n\n");
            }
          } else {
            printf("\n\tThêm từ mới không thành công. Từ tiếng Anh và nghĩa tiếng Việt không được để trống.\n\n");
          }

          String_Destroy(english);
          String_Destroy(vietnamese);

          printf("\tNhấn phím Enter để tiếp tục chức năng Thêm từ mới.\n\tNhấn phím khác để trở về màn hình danh sách chức năng.");
        } while (getch() == 13);
        break;

      case '3':
        do {
          Console_ShowFunction("XOÁ TỪ");

          printf("\n\tNhập từ tiếng Anh cần xoá: ");
          String english = String_Input();

          Console_ShowFunction("XOÁ TỪ");
          if (strlen(english) > 0) {
            if (Dictionary_Delete(dictionary, english)) {
              printf("\n\tXoá từ thành công.\n\n");
            } else {
              printf("\n\tXoá từ không thành công. Từ này không có trong tự điển.\n\n");
            }
          } else {
            printf("\n\tXoá từ không thành công. Vui lòng nhập từ tiếng Anh cần xoá.\n\n");
          }

          String_Destroy(english);

          printf("\tNhấn phím Enter để tiếp tục chức năng Xoá từ.\n\tNhấn phím khác để trở về màn hình danh sách chức năng.");
        } while (getch() == 13);
        break;

      case '4':
        loopHistory = true;
        CursorHistory cursor = History_GetCursor(history);
        while (loopHistory) {
          Console_ShowTitle();
          printf("\tLỊCH SỬ TRA CỨU TỪ\n");
          printf("\t*********************************************\n\n");

          if (cursor != NULL) {
            Console_ShowSearchResult(History_GetData(cursor));
            printf("\tDùng 2 phím mũi tên cuộn lên và xuống để xem lịch sử.\n\tNhấn phím khác để trở về màn hình danh sách chức năng.");

            switch (getch()) {
              case 224:
                switch (getch()) {
                  case 72:
                    if (History_Next(cursor) != NULL) {
                      cursor = History_Next(cursor);
                    }
                    break;

                  case 80:
                    if (History_Previous(cursor) != NULL) {
                      cursor = History_Previous(cursor);
                    }
                    break;
                }
                break;

              default:
                loopHistory = false;
                break;
            }
          } else {
            printf("\tLịch sử trống\n\n");
            printf("\tNhấn phím bất kì để trở về màn hình danh sách chức năng.");
            getch();
            loopHistory = false;
          }
        }
        break;
    }
  }

  History_Destroy(history);
  Dictionary_Destroy(dictionary);
  return 0;
}
