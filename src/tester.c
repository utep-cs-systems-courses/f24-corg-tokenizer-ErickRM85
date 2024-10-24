#include <string.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

/*
    The following is a simple testing script with a single example of input
    your code is expected to handle. The testing of your code should be more
    thorough and explore other input cases.
*/

#define TEST_TOKENIZER 1
#define TEST_HISTORY 1

int main() {
  
  while(1){
    List *history = init_history();
    fputs("Select what you want to do (Enter command = c, Show history = h, or q to quit\n>",stdout);
    fflush(stdout);
    int c;
    while((c = getchar()) == '\n');
    if (c == EOF){
      goto finish;
    }
    
    switch (c){
    case 'c':
      puts("You selected to Enter a command");
      char input[256];
      printf("Enter a string to tokenize: ");
      fgets(input, sizeof(input), stdin);
      printf("\nInput: %s\n", input);
      
      char **tokens = tokenize(input);
      printf("Tokens:\n");
      print_tokens(tokens);
      add_history(history, input);
      
      break;
    case 'h':
      printf("\nHistory:\n");
      print_history(history);

      printf("Enter the ID of the command");
      int ID;
      scanf("%d", &ID); 
      char *command = get_history(history,ID);
      if (command != NULL) {
	printf("\nRetrieved Command (ID: %d): %s\n", ID);
      } else {
	printf("\nNo command found with ID: %d\n", ID);
      }
      break;
    case 'q':
      printf("bye byee");
      goto finish;
    case '\n':
      break;
    deafult:
      printf("Option not available '%c', try again\n", c);
    }
    while (getchar() != '\n');
  }
  finish:
    
    return 0;
}
