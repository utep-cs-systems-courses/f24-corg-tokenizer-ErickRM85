#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define TEST_TOKENIZER 1
#define TEST_HISTORY 1

void clear_input_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

int main() {
  List *history = init_history();  

  while (1) {
    fputs("Select what you want to do (Enter command = c, Show history = h, or q to quit)\n> ", stdout);
    fflush(stdout);

    int c;
    while ((c = getchar()) == '\n');  
    if (c == EOF) {
      goto finish;
    }

    switch (c) {
    case 'c': {
      puts("You selected to Enter a command");
      char input[256];
      printf("Enter a string to tokenize: ");
      clear_input_buffer();  
      fgets(input, sizeof(input), stdin);
      input[strcspn(input, "\n")] = 0;  
      printf("\nInput: %s\n", input);
      char **tokens = tokenize(input);
      printf("Tokens:\n");
      print_tokens(tokens);
      add_history(history, strdup(input));  
      free_tokens(tokens);  
      break;
    }
    case 'h': {
      printf("\nHistory:\n");
      print_history(history);

      printf("Enter the ID of the command: ");
      int ID;
      scanf("%d", &ID);
      clear_input_buffer();  

      char *command = get_history(history, ID);
      if (command != NULL) {
	printf("\nRetrieved Command (ID: %d): %s\n", ID, command);
      } else {
	printf("\nNo command found with ID: %d\n", ID);
      }
      break;
    }
    case 'q':
      printf("Bye bye\n");
      goto finish;
    default:
      printf("Option not available '%c', try again\n", c);
      break;
    }

    clear_input_buffer();  
  }

 finish:
  free_history(history);  
  return 0;
}
