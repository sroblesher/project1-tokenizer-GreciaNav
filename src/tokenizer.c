#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if ((c == '\t' || c == ' ') && c != 0) {
    return 1; // Returns true if char is either tab or space
  }
  return 0;
}

int non_space_char(char c)
{
  if ((c != '\t' && c != ' ') && c != 0) {
    return 1; // Returns true if char is not a space char
  }
  return 0;
}

char *word_start(char *str)
{
  int i;
  for (i = 0; *(str+i) != '\0'; i++) {
    if (non_space_char(*(str+i))) { // Checks that char is not space
      return str+i;
    }
  }
  return str+i;
}

char *word_terminator(char *word)
{
  int i;
  for (i = 0; *(word+i) != '\0'; i++) {
    if (space_char(*(word+i))) { // Checks that char is space
      return word+i;
    }
  }
  return word+i;
}

int count_words(char *str)
{
  int wordCount = 0;
  char *p = word_start(str);
    while (*p != '\0') {
      if (non_space_char(*p)) {
	wordCount += 1; // Adds 1 to count if it goes to a word
      }
      p = word_terminator(p); // Goes to end of word
      p = word_start(p); // Goes to beggining of next word
    }
  return wordCount;
}

char *copy_str(char *inStr, short len)
{
  char *scopy = malloc((len+1) * sizeof(char));
  int i;
  for (i = 0; i < len; i++) {
    scopy[i] = inStr[i]; // Copying contents of inStr into scopy
  }
  scopy[i] = '\0'; // Making last value in scopy '\0'
  return scopy;
}

char **tokenize(char* str)
{
  int numWords = count_words(str);
  char **tokens = malloc((numWords+1) * sizeof(char *));
  char *p = str;
  int i;
  for (i = 0; i < numWords; i++) {
    p = word_start(p); // Go to next word
    int length = word_length(p);
    tokens[i] = copy_str(p, length); // Copying up to the end of the current word
    p = word_terminator(p); // Go to end of the word
  }
  tokens[i] = 0; // Make last element in tokens null
  return tokens;
}

void print_tokens(char **tokens)
{
  int i;
  for (i = 0; tokens[i] != 0; i++) {
    printf("%s ",tokens[i]); // Prints current word in tokens
  }
}

void free_tokens(char **tokens)
{
  int i;
  for (i = 0; tokens[i] != 0; i++) {
    free(tokens[i]); // Free each word in tokens
  }
  free(tokens); // Freeing tokens
}

short string_length(char *str)
{
  short length = 0;
  int i;
  for (i = 0; *(str+i) != '\0'; i++) {
    length += 1; // Adds one for every character that is not the terminator symbol
  }
  return length;
}


int word_length(char *str)
{
  int length = 0;
  int i;
  for (i = 0; *(str+i) != '\0'; i++) { // Go through string before seeing terminator symbol
    if (non_space_char(*(str+i))) {
      length += 1; // Add one to length since cur char is not a space char
    }
    else {
      break; // Found a space, finished counting current word
    }
  }
  return length;
}
