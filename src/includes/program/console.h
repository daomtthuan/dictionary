#ifndef _CONSOLE_PROGRAM_INCLUDE_
#define _CONSOLE_PROGRAM_INCLUDE_

#include "../word.h"

//--------------------------------------------------
void Console_showBrand()
{
  system("cls");
  printf("\n\t*********************************************\n");
  printf("\t*                                           *\n");
  printf("\t*      CHƯƠNG TRÌNH TỰ ĐIỂN ANH - VIỆT      *\n");
  printf("\t*                                           *\n");
  printf("\t*      Họ và tên: Đào Minh Trung Thuận      *\n");
  printf("\t*      Mã sinh viên: B1704855               *\n");
  printf("\t*                                           *\n");
  printf("\t*********************************************\n\n");
}

void Console_showMenu()
{
  printf("\tDanh sách chức năng:\n");
  printf("\t\t0. Thoát chương trình.\n");
  printf("\t\t1. Tra cứu tự điển.\n");
  printf("\t\t2. Thêm từ mới vào tự điển.\n");
  printf("\t\t3. Xoá từ khỏi tự điển.\n");
  printf("\t\t4. Lịch sử từ đã tra cứu.\n\n");
  printf("\tChọn chức năng: ");
}

void Console_showFunction(String name)
{
  Console_showBrand();
  printf("\t%s\n", name);
  printf("\tNhập ký tự ~ để trở về màn hình danh sách chức năng.\n\n");
  printf("\t*********************************************\n\n");
}

void Console_showSearchResult(const Word word)
{
  if (word != NULL)
  {
    printf("\n\tTra từ thành công.\n");
    printf("\t\tTiếng Anh: %s\n", word->english);
    printf("\t\tTiếng Việt: %s\n\n", word->vietnamese);
  }
  else
  {
    printf("\n\tTra từ không thành công. Không tìm thấy từ.\n\n");
  }
}

#endif
