#include <conio.h>

#include "./includes/Dictionary.h"
#include "./includes/History.h"

/**
 * Main Program
 */
int main() {
  Console_ShowTitle();
  Console_ShowText("Đang khởi tạo...");

  char cursor;
  bool selectFunction = true;
  bool changed = false;
  bool inHistoryFunction = false;
  bool selectExitOption = false;
  Dictionary dictionary = Dictionary_Create();
  History history = History_Create();

  Console_ShowText("Đang nạp dữ liệu...");
  Dictionary_LoadData(dictionary);

  Console_ShowMenu();

  while (selectFunction) {
    switch (getch()) {
      case '1':
        do {
          Console_ShowFunction("TRA CỨU TỪ");
          Console_Input("Nhập từ tiếng Anh muốn tra cứu");
          String english = String_Input();

          Console_ShowFunction("TRA CỨU TỪ");
          if (strlen(english) > 0) {
            Word result = Dictionary_Search(dictionary, english);
            Console_ShowSearchResult(result);
            History_Insert(history, english, result == NULL ? "" : result->vietnamese);
          } else {

            Console_ShowText("Tra cứu từ không thành công.");
            Console_ShowText("Từ tiếng Anh không được để trống.");
          }
          
          String_Destroy(english);

          Console_BreakLine();
          Console_ShowText("Nhấn phím Enter để tiếp tục chức năng Tra cứu từ.");
          Console_ShowText("Nhấn phím khác để trở về màn hình danh sách chức năng.");
        } while (getch() == 13);

        Console_ShowMenu();
        break;

      case '2':
        do {
          Console_ShowFunction("THÊM TỪ");

          Console_Input("Nhập từ tiếng Anh");
          String english = String_Input();

          Console_Input("Nhập nghĩa tiếng Việt");
          String vietnamese = String_Input();

          Console_ShowFunction("THÊM TỪ");
          if (strlen(english) * strlen(vietnamese) > 0) {
            if (Dictionary_Insert(dictionary, english, vietnamese)) {
              changed = true;
              Console_ShowText("Thêm từ thành công.");
            } else {
              Console_ShowText("Thêm từ không thành công.");
              Console_ShowText("Từ này đã có trong tự điển.");
            }
          } else {
            Console_ShowText("Thêm từ không thành công.");
            Console_ShowText("Từ tiếng Anh và nghĩa tiếng Việt không được để trống.");
          }

          String_Destroy(english);
          String_Destroy(vietnamese);

          Console_BreakLine();
          Console_ShowText("Nhấn phím Enter để tiếp tục chức năng Thêm từ.");
          Console_ShowText("Nhấn phím khác để trở về màn hình danh sách chức năng.");
        } while (getch() == 13);

        Console_ShowMenu();
        break;

      case '3':
        do {
          Console_ShowFunction("SỬA TỪ");

          Console_Input("Nhập từ tiếng Anh");
          String english = String_Input();

          Console_Input("Nhập nghĩa tiếng Việt");
          String vietnamese = String_Input();

          Console_ShowFunction("SỬA TỪ");
          if (strlen(english) * strlen(vietnamese) > 0) {
            if (Dictionary_Edit(dictionary, english, vietnamese)) {
              changed = true;
              Console_ShowText("Sửa từ thành công.");
            } else {
              Console_ShowText("Sửa từ không thành công.");
              Console_ShowText("Từ này không có trong tự điển.");
            }
          } else {
            Console_ShowText("Sửa từ không thành công.");
            Console_ShowText("Từ tiếng Anh và nghĩa tiếng Việt không được để trống.");
          }

          String_Destroy(english);
          String_Destroy(vietnamese);

          Console_BreakLine();
          Console_ShowText("Nhấn phím Enter để tiếp tục chức năng Sửa từ.");
          Console_ShowText("Nhấn phím khác để trở về màn hình danh sách chức năng.");
        } while (getch() == 13);

        Console_ShowMenu();
        break;

      case '4':
        do {
          Console_ShowFunction("XOÁ TỪ");

          Console_Input("Nhập từ tiếng Anh cần xoá");
          String english = String_Input();

          Console_ShowFunction("XOÁ TỪ");
          if (strlen(english) > 0) {
            if (Dictionary_Delete(dictionary, english)) {
              changed = true;
              Console_ShowText("Xoá từ thành công.");
            } else {
              Console_ShowText("Xoá từ không thành công.");
              Console_ShowText("Từ này không có trong tự điển.");
            }
          } else {
            Console_ShowText("Xoá từ không thành công.");
            Console_ShowText("Từ tiếng Anh không được để trống.");
          }

          String_Destroy(english);

          Console_BreakLine();
          Console_ShowText("Nhấn phím Enter để tiếp tục chức năng Xoá từ.");
          Console_ShowText("Nhấn phím khác để trở về màn hình danh sách chức năng.");
        } while (getch() == 13);

        Console_ShowMenu();
        break;

      case '5':
        inHistoryFunction = true;
        CursorHistory cursor = History_GetCursor(history);
        while (inHistoryFunction) {
          Console_ShowFunction("LỊCH SỬ TRA CỨU TỪ");

          if (cursor != NULL) {
            Console_ShowSearchResult(History_GetData(cursor));
            Console_ShowText("Dùng 2 phím mũi tên cuộn lên và xuống để xem lịch sử.");
            Console_ShowText("Nhấn phím khác để trở về màn hình danh sách chức năng.");

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
                inHistoryFunction = false;
                break;
            }
          } else {
            inHistoryFunction = false;
            Console_ShowText("Lịch sử trống.");
            Console_BreakLine();
            Console_ShowText("Nhấn phím bất kỳ để trở về màn hình danh sách chức năng.");
            getch();
          }
        }

        Console_ShowMenu();
        break;

      case '0':
        if (changed) {
          Console_ShowExitMenu();
          selectExitOption = true;
          while (selectExitOption) {
            switch (getch()) {
              case '1':
                Console_ShowTitle();
                Console_ShowText("Đang lưu dữ liệu...");
                Dictionary_SaveData(dictionary);

                selectFunction = false;
                selectExitOption = false;
                break;

              case '2':
                selectExitOption = false;
                Console_ShowMenu();
                break;

              case '0':
                selectFunction = false;
                selectExitOption = false;
                break;
            }
          }
        } else {
          selectFunction = false;
        }
        break;
    }
  }

  Console_ShowTitle();
  Console_ShowText("Đang thu gom, dọn dẹp dữ liệu...");
  History_Destroy(history);
  Dictionary_Destroy(dictionary);

  Console_ShowTitle();
  Console_ShowText("Tạm biệt.");
  return 0;
}
