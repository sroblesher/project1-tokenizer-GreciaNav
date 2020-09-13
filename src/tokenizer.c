#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if ((c == '\t' || c == ' ') && c != 0)
  {
    return 1; //Returns true if char is either tab or space
  }
  return 0;
}

int non_space_char(char c)
{
  if ((c != '\t' && c != ' ') && c != 0)
  {
    return 1; //Returns true if char is not a space char
  }
  return 0;
}

char *word_start(char *str)
{
  for (int i = 0; *(str+i) != '\0'; i++){
    if (non_space_char(*(str+i))) //Checks that char is not space
    {
      return str+i;
    }
  }
  return 0;
}


char *word_terminator(char *word)
{
  for (int i = 0; *(word+i) != '\0'; i++){
    if (space_char(*(word+i))) //Checks that char is space
    {
      return word+i;
    }
  }
  return 0;
}

int count_words(char *str)
{
  int wordCount = 0;
  return wordCount;
}

/*
char *copy_str(char *inStr, short len)
{
  return 0;
}


char **tokenize(char* str)
{
  return 0;
}


void print_tokens(char **tokens)
{

}

void free_tokens(char **tokens)
{

}
*/
