#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

char *token_to_string(char **tokens);

int main()
{
  char input[100];
  List *history = init_history();

  while (1) {
    printf("\nPlease do one of the following:\n");
    printf("1.Input '#' to quit\n 2.Input a sentence\n 3.Input ! followed by a sequence number to recall a certain history.\n"); 
    printf("$");
    fgets(input, 100, stdin);
    
    if (input[0] == '#') { // Option to quit program
      printf("Bye, thank you!\n");
      free_history(history);
      return 0;
    }
    if (input[0] == '!') { // Option to recall a certain history
      printf("%s\n",get_history(history,atoi(input+1)));
    }
    else { // Option to input sentence to history
      char **tokens = tokenize(input);
      print_tokens(tokens);

      //Make tokenized word to string
      char *token_str = malloc(100*sizeof(char));
      char *curr = token_str;
      int w = 0;
      int l = 0;
      for (int i = 0; i < 100; i++) {
	curr[i] = tokens[w][l];
	l++;
	if (tokens[w][l] == '\0') {
	  l = 0;
	  w++;
	  curr[++i] = ' ';
	}
	if(tokens[w] == 0) {
	  curr[++i] = '\0';
	  break;
	}
      }
      
      free_tokens(tokens);
      add_history(history, token_str);
      free(token_str);
    }
  }
}
