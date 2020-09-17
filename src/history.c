#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  List *list = malloc(sizeof(List)); //Allocating memory for list
  list->root = malloc(sizeof(Item)); //Allocating memory for item in list

  return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  Item *temp = list->root;
  int id = 1;
  while(temp->next != 0) //Will take us to end of list
  {
    temp = temp->next;
    id++;
  }
  //Allocating memory for and adding item with given string
  temp->next = malloc(sizeof(Item)); 
  temp->next->str = str;
  temp->next->id = id;
  
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  Item *temp = list->root;
  
  while(temp != 0) //Traverse whole list
  {
    if (temp->id == id)
    {
      return temp->str; //Returns str if id matches given id
    }
    temp = temp->next;
  }
  return '\0'; //id not found in List
}

/*Print the entire contents of the list. */
void print_history(List *list)
{
  Item *temp = list->root;
  while(temp != 0) //Traverse whole list
  {
    printf("%d. %s\n",temp->id, temp->str); //Print string along with its id
    temp = temp->next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list)
{
  Item *temp = list->root;
  /*while(temp != '\0')
  {
  
  }*/
  free(list);
}


