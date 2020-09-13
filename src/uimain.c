#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main()
{
  char input[500];

  
  printf("%c\n",*(word_start("hello world")));
  char *p = word_terminator("hello world");
  printf("%c\n", *(word_start(p)));
  printf("%d",count_words("  hello world"));
  
  while (1){
    printf("$");
    scanf("%s", input, 500);
    printf("%s\n",input);
  }
}
