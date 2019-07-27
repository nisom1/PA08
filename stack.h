#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct Node {
  int val;
  struct Node* next;
}Node;

typedef struct{
  Node* head;
}Stack;

int push(Stack * * list, int val);
int pop(Stack * * list);

bool isEmpty(Stack* s);

