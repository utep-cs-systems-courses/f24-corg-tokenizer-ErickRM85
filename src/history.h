#ifndef _HISTORY_
#define _HISTORY_

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;

/* Initialize the linked list to keep the history. */
List* init_history(){
  List* list = (List*)malloc(sizeof(List));
  list->root = NULL; 
  return list;
}
/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  Item* newHist = (Item*)malloc(sizeof(Item));
  newHist->str = str;
  newHist->next = NULL;
  
  if (list->root == NULL) {
    newHist->id = 1;
    list->root = newHist;
  } else {
    Item *currHist = list->root;
    while (currHist->next != NULL) {
      currHist = currHist->next;
    }
    newHist->id = currHist->id + 1;
    currHist->next = newHist;
  }
}
/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item *current = list->root;
  while (current != NULL) {
    if (current->id == id) {
      return current->str;
    }
    current = current->next;
  }
  return NULL;  // Return NULL if id is not found
}
/*Print the entire contents of the list. */
void print_history(List *list){
  Item *current = list->root;
  while (current != NULL) {
    printf("ID: %d, Command: %s\n", current->id, current->str);
    current = current->next;
  }
}
/*Free the history list and the strings it references. */
void free_history(List *list){
  Item *current = list->root;
  while (current != NULL) {
    Item *next = current->next;
    free(current->str);  // Free the copied string
    free(current);       // Free the item node
    current = next;
  }
  free(list);
}
#endif
