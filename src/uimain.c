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
  char *stringy = "oye si";
  char *string = copy_str(stringy, string_length(stringy));
  printf("%s\n",string);
  char **token = tokenize("hello world string");
  printf("%s\n",token[0]);
  printf("%s\n",token[1]);
  printf("%s\n",token[2]);
  print_tokens(token);
  free_tokens(token);
  
  while (1)
  {
    printf("$");
    fgets(input, 100, stdin);
    printf("%s\n",input);
  }
}
