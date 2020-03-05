#ifndef _CONSOLE_PROGRAM_INCLUDE_
#define _CONSOLE_PROGRAM_INCLUDE_

#include "../word.h"

//--------------------------------------------------

/**
 * Show Brand
 */
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

/**
 * Show Menu
 */
void Console_showMenu()
{
  printf("\tDanh sách chức năng:\n");
  printf("\t\t0. Thoát chương trình.\n");
  printf("\t\t1. Tra cứu từ.\n");
  printf("\t\t2. Thêm từ mới.\n");
  printf("\t\t3. Xoá từ.\n");
  printf("\t\t4. Lịch sử tra cứu.");
}

/**
 * Show name Function
 */
void Console_showFunction(String name)
{
  Console_showBrand();
  printf("\t%s\n", name);
  printf("\t*********************************************\n\n");
}

/**
 * Show Search result
 */
void Console_showSearchResult(const Word word)
{
  if (word != NULL)
  {
    printf("\tTiếng Anh: %s\n", word->english);
    printf("\tTiếng Việt: %s\n\n", word->vietnamese);
  }
  else
  {
    printf("\tTra từ không thành công. Không tìm thấy từ.\n\n");
  }
}

#endif
