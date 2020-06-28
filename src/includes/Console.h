#ifndef _CONSOLE_PROGRAM_INCLUDE_
#define _CONSOLE_PROGRAM_INCLUDE_

#include "./Word.h"

//--------------------------------------------------

/**
 * Show title
 */
void Console_ShowTitle() {
  system("cls");
  printf("\n  *********************************************\n");
  printf("  *                                           *\n");
  printf("  *      CHƯƠNG TRÌNH TỰ ĐIỂN ANH - VIỆT      *\n");
  printf("  *                                           *\n");
  printf("  *      Họ và tên: Đào Minh Trung Thuận      *\n");
  printf("  *      Mã sinh viên: B1704855               *\n");
  printf("  *                                           *\n");
  printf("  *********************************************\n\n");
}

/**
 * Show text
 *
 * @param text - Shown text
 */
void Console_ShowText(String text) {
  printf("  %s\n", text);
}

/**
 * Show text for input
 *
 * @param text - Shown text
 */
void Console_Input(String text) {
  printf("  %s: ", text);
}

/**
 * Break line
 *
 */
void Console_BreakLine() {
  printf("\n");
}

/**
 * Show main Menu
 *
 */
void Console_ShowMenu() {
  Console_ShowTitle();
  printf("  Danh sách chức năng:\n");
  printf("    1. Tra cứu từ.\n");
  printf("    2. Thêm từ.\n");
  printf("    3. Sửa từ.\n");
  printf("    4. Xoá từ.\n");
  printf("    5. Lịch sử tra cứu.\n");
  printf("    ----------------------\n");
  printf("    0. Thoát chương trình.\n");
}

/**
 * Show exit Menu
 *
 */
void Console_ShowExitMenu() {
  Console_ShowTitle();
  printf("  Dữ liệu từ điển có sự thay đổi, lưu dữ liệu trước khi thoát?\n");
  printf("    1. Lưu dữ liệu.\n");
  printf("    2. Trở về màn hình danh sách chức năng.\n");
  printf("    ---------------------------------------\n");
  printf("    0. Không lưu dữ liệu.\n");
}

/**
 * Show name Function
 *
 * @param name - Name of function
 */
void Console_ShowFunction(String name) {
  Console_ShowTitle();
  printf("  %s\n", name);
  printf("  *********************************************\n\n");
}

/**
 * Show Search result
 *
 * @param word - Result word
 */
void Console_ShowSearchResult(const Word word) {
  if (word != NULL) {
    printf("  Tiếng Anh: %s\n", word->english);
    printf("  Tiếng Việt: %s\n", word->vietnamese);
  } else {
    printf("  Tra từ không thành công.\n  Không tìm thấy từ.\n");
  }
}

#endif
