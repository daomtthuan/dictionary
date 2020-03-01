#include <stdio.h>
#include <stdlib.h>

void main()
{
  FILE *englishFile;
  File char ch;

  englishFile = fopen("../data/data.txt", "r");
  if (englishFile == NULL)
  {
    printf("Cannot open file \n");
    exit(0);
  }

  ch = fgetc(englishFile);
  while (ch != EOF)
  {
    printf("%c", ch);
    ch = fgetc(englishFile);
  }

  fclose(englishFile);
}