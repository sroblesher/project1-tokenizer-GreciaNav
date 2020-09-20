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
    printf("1.Input '#' to quit\n 2.Input a sentence\n 3.Input '!' followed by a sequence number to recall a certain history.\n4. Input '&' to view all history\n"); 
    printf("$");
    fgets(input, 100, stdin);
    
    if (input[0] == '#') { // Option to quit program
      printf("Bye, thank you!\n");
      free_history(history);
      return 0;
    }
    else if (input[0] == '!') { // Option to recall a certain history
      printf("%s\n",get_history(history,atoi(input+1)));
    }
    else if (input[0] == '&') { //Option to view history
      print_history(history);
    }
    else { // Option to input sentence to history
      char **tokens = tokenize(input);
      print_tokens(tokens);
      token_to_history(history, tokens); //Turns tokenized word to string, adds to history
      free_tokens(tokens);
    }
  }
}

void token_to_history(List *history, char **tokens)
{
      char *token_str = malloc(100*sizeof(char));
      char *curr = token_str;
      int w = 0;
      int l = 0;
      for (int i = 0; i < 100; i++) {
	curr[i] = tokens[w][l]; // copying contents in tokens
	l++;
	if (tokens[w][l] == '\0') { // Reached end of word 
	  l = 0; // Reset letter to 0
	  w++;
	  curr[++i] = ' '; // Adding single space after word
	}
	if(tokens[w] == 0) { // Reached end of words
	  curr[++i] = '\0';
	  break;
	}
      }
      add_history(history, token_str); // Adding tokenized input to history
      free(token_str); 
}     

