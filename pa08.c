#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
#include "calc.h"

int main (int argc, char ** argv) {
	if (argc != 2) {
		fprintf(stderr, "Incorrect number of arguments.\n");
		fprintf(stderr, "Usage: ./pa08 <input file>\n");		
		return EXIT_FAILURE;
	}

	Stack * * stackList; // initializing the stackList
	stackList->head == NULL;

	expressionValid(argv[1],stackList, OPS, NUMS); // checking that it's a valid expression
	
	float result; // result of calculation
	result = parseExpression(Stack * * list);

	printf("%f\n", result);
	
	return EXIT_SUCCESS;
}
