#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pile.h"
#include "eval.h"


int main (int argc, char ** argv) {
	if (argc != 2) {
		printf("wrong num arguments");
		fprintf(stderr, "Incorrect number of arguments.\n");
		fprintf(stderr, "Usage: ./pa08 <input file>\n");		
		return EXIT_FAILURE;
	}

	Stack list = {.head = NULL};
	//if (!list) return NULL;
	//list->head->next = NULL;
	
	//expressionValid(argv[1]); // checking that it's a valid expression
	
	// float result; // result of calculation
	parseExpression(list,argv[1]);
	return EXIT_SUCCESS;
}
