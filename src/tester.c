#include <string.h>
#include <stdio.h>
#include "tokenizer.h"
/*#include "history.h"

/*
    The following is a simple testing script with a single example of input
    your code is expected to handle. The testing of your code should be more
    thorough and explore other input cases.
*/

#define TEST_TOKENIZER 1
#define TEST_HISTORY 1

int main() {
  char input[100];

  // Display an indicator and take user input
  printf("$ Write a word: ");

  // Read input from the user
  while (fgets(input, sizeof(input), stdin) != NULL) {
    // Remove newline character from the input
    input[strcspn(input, "\n")] = 0;

    // Echo the input back to the user
    printf("%s\n", input);

    // Display the indicator again
    printf("$ ");
  }

  return 0;
}
