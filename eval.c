#include "calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

bool expressionValid(char* filename, Stack * * list, int * numOPS, int * numNUMS)
{
   // open the file to read
   FILE * fptr1 = fopen(filename, "r");
      if (fptr1 == NULL){
                return EXIT_FAILURE;
	}; // if fopen fails, return false

// count the number of Operands and Operators. If the ratio isn't right, then the program exits
  int ch;
  *numOPS = NULL; // initialized in declaration
  *numNUMS = NULL;
 
  while ((ch = fgetc(fptr1)) != EOF){
      if ( (ch == '/') || (ch == '*') || (ch == '+') || (ch == '-') ){
        numOPS++;
    }
  }
  fclose(fptr1);

// reopen to scan for the number of operands in the file
   FILE * fptr2 = fopen(filename, "r");
      if (fptr2 == NULL){
                return EXIT_FAILURE;
        }; // if fopen fails, return false
  int num;
  for ( i = 0; ) 
  while ( fscanf(fptr2, "%f", &num) > 0){
	*numNUMS++;
    }
  
  if ( *numNUMS != ((*numOPS)-1) ){ // if these values aren't equal, then it's not solve-able
  	return EXIT_FAILURE;
  }
  fclose(fptr2);
  return true;
}


float calcValues(Stack * * list, char ch){
  switch(ch){
	case '*':
		return pop(list) * pop(list);
	case '+':
		return pop(list) * pop(list);
	case '-':
		temporaryVariable = pop(list);
        	return ( pop(list) / temporaryVariable );
	case '/': 
		temporaryVariable = pop(list);
		return ( pop(list) / temporaryVariable );
  }
}

float parseExpression(Stack * * list)
{
   FILE * fptr3 = fopen(filename, "r");
      if (fptr3 == NULL){
                return EXIT_FAILURE;
	}; // if fopen fails, return false
 
  char ch;
  int i = 0;
  float num;
  char* str1 = '';
  char* str2 = '';
  while( (ch = fgetc(fptr3)) != EOF ){
	if( ch == '/' | '*' |'+' |'-'){
	  totalNum = calcValues(list, ch);  
	  push(list, totalNum);
	}
	else if( isdigit(ch) ){
		str1 = '';
	  while(ch != ' '){
		size_t len = strlen(str1);
		char* str2 = malloc(len + 1);
		strcpy(str2, str1);
		str2[len] = ch;
		strcpy(str1, str2);
		
		fgetc(fptr3); // advance to the next digit??
	  }
	  num = (float) atof(str2);
	  push(list, num);
	  free(str2);
	}
  }
  return num;  
}



