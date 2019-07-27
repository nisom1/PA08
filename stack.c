#include "stack.h"
#include <ctype.h>

bool isEmpty(Stack * list)
{
  if(s->head == NULL)
	return true;
  else
	return false;
}
void initializeStack( Stack * list){
   s->head == NULL
        return true; 
}
// We will only be pushing and poping NUMBERS (we're parsing), so push and pop can return INTs

int push(Stack * list, int val)
{
  Node* newNode = malloc(sizeof(Node));
  if(newNode == NULL)
	return EXIT_FAILURE; //overflow
  else
	newNode->val = val;
	newNode->next = s->head;
	s->head = newNode;
  return EXIT_SUCCESS;
}


int pop(Stack * list)
{
  if(s->head == NULL)
	return EXIT_FAILURE; // underflow
  Node* toPop = s->head;
  s->head = s->head->next;
  int numRemove = toPop->val;
  free(toPop);
  return numRemove;
}
