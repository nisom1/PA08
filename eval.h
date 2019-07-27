#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

bool expressionValid(char * filename, Stack * * list, int * numelem);
// expressionRead reads the inputs file and verifies that the given input expression has
// the right operand : operator ratio

float parseExpression(Stack * list, int numelem); // RPN calculator
float calcValues(Stack * list, char ch); 
