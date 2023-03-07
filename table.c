#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include "table.h"


typedef struct Node node;
struct Node
{
  int   number;
  node  *next;
};

static node *top = NULL;
static node *traverseNode = NULL;


// add an element to the table
// Return TRUE if the item is in the table
// Return FALSE if the item is *not* in the table
Boolean insertItem( int item ) {
    //printf("\n");

    Boolean inserted = false;
    node *prev = malloc(sizeof( node ));
    node *curr = top;

    node *newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->number = item;
    newNode->next = NULL;

    if(top == NULL) {
        top = newNode;
        inserted = true;
        //printf("Item: %d inserted in table as the first element since TOP == NULL\n",item);
    } else{
      while(curr != NULL){
        if(curr->number > item){
          prev->next = newNode;
          newNode->next = curr;
          inserted=true;
          //printf("Item: %d was inserted in table between the values %d and %d\n",item,prev->number,curr->number);
          break;
        }
        prev=curr;
        curr=curr->next;        
      }

      if(inserted == false){
        prev->next = newNode;
        inserted = true;
        //printf("Item: %d was inserted as the end of the table since it is the largest value inside\n",item);
      }
    }
    return inserted;
}


// removes the int from the table
Boolean removeItem( int item ) {
    node *prev = malloc(sizeof( node ));
    node *curr = top;
    Boolean removed = false;

    if(curr->number==item){
      if(top->next != NULL){top = top->next;}
      else{ top = NULL; }

      free(curr);
      removed = true;
    }

    while(curr != NULL && removed == false) {
        if(curr->number == item) {
            if(curr->next != NULL){prev->next = curr->next;}
            else{ prev->next = NULL; }

            free(curr);
            removed = true;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    return removed;
}


// empty the table so that we clear all memory and can start a fresh table
void clearTable() { 
    node *curr = top;
    node *temp = malloc(sizeof( node ));

    while ( curr != NULL ) {
        temp = curr;
        curr = curr->next;
        free( temp );
    }
    top = NULL;
}


// tells us whether or not the given item is in the table
Boolean search( int item ) {
    node *curr = top;
    Boolean found = false;
    while(curr != NULL && found == false) {
        if(curr->number == item) {
            found = true;
            break;
        }
        curr = curr->next;
    }
    return found;
}


// table iterators
// Return TRUE if item was assigned
// Return FALSE if item was *not* assigned

Boolean firstItem( int * const item ) {
  Boolean result = false;
  
  if ( top )
  {   
    traverseNode = top->next;  
    result = true;
  }  
  
  return result;
}


Boolean nextItem( int * const item ) {
  Boolean result = false;
  
  if ( traverseNode )
  {
    traverseNode = traverseNode->next;    
    result = true;
  }
  
  return result;
}

void print() {
  node *curr = top;
  printf("Linked List: \n");
  if(top == NULL){
    printf("TABLE IS EMPTY\n");
    return;
  }
  while(curr != NULL) {
    printf("%d\t", curr->number);
    curr = curr->next;
  }
  printf("\n");
}