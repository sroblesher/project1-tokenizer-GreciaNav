#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main()
{
  char input[100];
  
  printf("%c\n",*(word_start("hello world")));
  char *p = word_terminator("hello world");
  printf("%c\n",*(word_start(p)));
  int x = count_words("  hello world");
  printf("%d\n",x);
  
  while (1){
    printf("$");
    fgets(input, 100, stdin);
    printf("%s\n",input);
  }
}
