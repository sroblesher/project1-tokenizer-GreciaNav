#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

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
  printf("%s\n",token[3]);
  print_tokens(token);
  free_tokens(token);

  List *l = init_history();
  add_history(l, "Sonikkuu");
  add_history(l, "jojo");
  add_history(l, "oye si");
  print_history(l);
  printf("%s\n",get_history(l,3));
  printf("%s\n",get_history(l,4));
  free_history(l);
  print_history(l);
  while (1)
  {
    printf("$");
    fgets(input, 100, stdin);
    printf("%s\n",input);
  }
}
