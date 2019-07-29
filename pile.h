#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#ifndef PILE 
typedef struct Node{
  float  val;
  struct Node* next;
}Node;

typedef struct{
  Node* head;
}Stack;

int push(Stack * list, float val);
float pop(Stack *  list);

#endif
//bool isEmpty(Stack* s);

