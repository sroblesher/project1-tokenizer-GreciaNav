#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List *init_history()
{
  List *list = malloc(sizeof(List)); // Allocating memory for list
  list->root = malloc(sizeof(Item)); // Allocating memory for item in list
  
  return list;
}

void add_history(List *list, char *str)
{
  int id = 1;
  Item *temp = list->root;
  
  while (temp->next != 0) { // Will take us to end of list
    temp = temp->next;
    id++;
  }
  
  // Allocating memory for and adding item with given string
  temp->next = malloc(sizeof(Item)); 
  temp->next->str = copy_str(str, string_length(str));
  temp->next->id = id;
}

char *get_history(List *list, int id)
{
  Item *temp = list->root;
  
  while (temp != 0) { // Traverse whole list
    if (temp->id == id) {
      return temp->str; // Returns str if id matches given id
    }
    temp = temp->next;
  }
  return "id not found"; // id not found in List
}

void print_history(List *list)
{
  Item *temp = list->root->next; // Skips dummy node
  while (temp != 0) { // Traverse whole list
    printf("%d. %s", temp->id, temp->str); //Print string along with its id
    temp = temp->next;
  }
}

void free_history(List *list)
{
  Item *cur = list->root;
  while(cur->next != 0) {
    Item *prev = cur; // Node to be freed
    cur = cur->next; // Keeping reference to next node
    free(prev->str); // Freeing str in node to be freed
    free(prev); // Freeing node to be freed
  }
  free(cur->str); // Free str in last node
  free(cur); // Free last node
  free(list); // Free list
}
