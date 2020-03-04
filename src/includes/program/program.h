#ifndef _PROGRAM_INCLUDE_
#define _PROGRAM_INCLUDE_

#include "../types/word.h"

//--------------------------------------------------

void Program_showMenu()
{
  printf(" Danh sách chức năng:\n");
  printf("     0. Thoát chương trình.\n");
  printf("     1. Tra cứu tự điển.\n");
  printf("     2. Thêm từ mới vào tự điển.\n");
  printf("     3. Xoá từ khỏi tự điển.\n");
  printf("     4. Lịch sử từ đã tra cứu.\n\n");
  printf(" Chọn chức năng: ");
}

void Program_welcome()
{
  printf("\n      *********************************************\n");
  printf("      *                                           *\n");
  printf("      *      CHƯƠNG TRÌNH TỰ ĐIỂN ANH - VIỆT      *\n");
  printf("      *                                           *\n");
  printf("      *      Họ và tên: Đào Minh Trung Thuận      *\n");
  printf("      *      Mã sinh viên: B1704855               *\n");
  printf("      *                                           *\n");
  printf("      *********************************************\n\n");
}

void Program_searchResult(const Word word)
{
  if (word != NULL)
  {
    printf("\n Tra từ thành công.\n");
    printf("     Tiếng Anh: %s\n", Word_getEnglsh(word));
    printf("     Tiếng Việt: %s\n\n", Word_getVietnamese(word));
  }
  else
  {
    printf("\n Tra từ không thành công. Không tìm thấy từ.\n\n");
  }
}

#endif
