#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

void token_to_history(List *history, char **tokens);

int main()
{
  char input[100];
  List *history = init_history();

  while (1) {
    printf("\nPlease do one of the following:\n");
    printf("1.Input 'q' to quit\n 2.Input 'i' to input a sentence\n 3.Input '!' followed by a sequence number to recall a certain history.\n4. Input 'h' to view all histories\n"); 
    printf("$");
    fgets(input, 100, stdin);
    
    if (input[0] == 'q') { // Option to quit program
      printf("Bye, thank you!\n");
      free_history(history);
      return 0;
    }
    else if (input[0] == '!') { // Option to recall a certain history
      char *hist = get_history(history,atoi(input+1));
      char **tokens = tokenize(hist);
      printf("Retrieved history: %s\n", hist);
      printf("Retrieved history tokenized:\n");
      print_tokens(tokens);
      free_tokens(tokens);
    }
    else if (input[0] == 'h') { //Option to view history
      print_history(history);
    }
    else if (input[0] == 'i') { // Option to input sentence to history
      printf("Please input your sentence:\n$");
      fgets(input, 100, stdin);
      char **tokens = tokenize(input);
      print_tokens(tokens);
      add_history(history, input);
      free_tokens(tokens);
    }
    else { // Invalid option
      printf("Invalid option, try again!\n");
    }
  }
}
