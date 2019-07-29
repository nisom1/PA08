#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "eval.h"

// We will only be pushing and poping NUMBERS (we're parsing), so push and pop can return INTs

int push(Stack * s, float val)
{
  Node* newNode = malloc(sizeof(Node));
  if(newNode == NULL)
	return EXIT_FAILURE; //overflow
  else
  {	newNode->val = val;
	newNode->next = s->head;
	s->head = newNode;
     return EXIT_SUCCESS;
   }
}


float pop(Stack * s)
{
  if(s->head == NULL)
	return EXIT_FAILURE; // underflow
  Node* toPop = s->head;
  s->head = s->head->next;
  float numRemove = toPop->val;
  free(toPop);
  return numRemove;
}
