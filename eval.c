#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pile.h"
/*
int expressionValid(char* filename){
   // open the file to read
   FILE * fptr1 = fopen(filename, "r");
      if (fptr1 == NULL){
                return EXIT_FAILURE;
	} // if fopen fails, return false


// count the number of Operands and Operators. If the ratio isn't right, then the program exits
  char ch;
  int numOPS = 0;
  int numNUMS = 0;
 
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
float num = 0;
  while (!feof(fptr2)){
	fscanf(fptr2, "%f", &num);
	numNUMS++;
    }
  
  if ( numOPS != (numNUMS-1) ){ // if these values aren't equal, then it's not solve-able
  	printf("Invalid Expression\n");
	return EXIT_FAILURE;
  }
  fclose(fptr2);
  return EXIT_SUCCESS;
}
*/

float calcValues(Stack * list, char ch){
float a = pop(list);
float b = pop(list);
  switch(ch){
	case '*': 
		return ( a * b );
		break;
	case '+':
		return ( a + b );
		break;
	case '-':
		return ( b  - a );
		break;
	case '/':
		  return ( b / a );
		  break;
		} 
  return EXIT_FAILURE;
}

int parseExpression(Stack list, char* filename)
{
   FILE * fptr3 = fopen(filename, "r");
      if (fptr3 == NULL){
                return EXIT_FAILURE;
	} // if fopen fails, return false
  int numNUMS = 0;
  int numOPS = 0;
  char ch = fgetc(fptr3);
  int i;
  float result = 0;
  while( !feof(fptr3) ){
	float temp = 0;
	if(ch == '/' || ch == '*' || ch == '+' || ch == '-'){
	  float totalNum;
	  totalNum = calcValues(&list, ch);  
	  push(&list, totalNum);
	  numOPS++;
	}
	else if( isdigit(ch) || (ch == '.') )
	{
	  for ( i = 0; ( (ch != ' ') && (!feof(fptr3)) ); i++)   
	  {
	    if (ch == '.')
	   {
	     ch = fgetc(fptr3);
	     while( (ch != ' ') && (!feof(fptr3)) )
	     {
		int temp1 = atoi(&ch);
		temp = temp + (0.1*temp1);
		ch = fgetc(fptr3);
		if ( (ch != ' ') && (!feof(fptr3)) )
		{
		  int temp2 = atoi(&ch);
		  temp = temp + (0.01*temp2);
		  ch = fgetc(fptr3);
		  if ( (ch != ' ') && (!feof(fptr3)) )
                  {
                    int temp3 = atoi(&ch);
                    temp = temp + (0.001*temp3);
                    ch = fgetc(fptr3);
	  	    if ( (ch != ' ') && (!feof(fptr3)) )
                    {   
                     int temp4 = atoi(&ch);
                     temp = temp + (0.0001*temp4);
                     ch = fgetc(fptr3);
                     if ( (ch != ' ') && (!feof(fptr3)) )
                     { 
                      int temp5 = atoi(&ch);
                      temp = temp + (0.00001*temp5);
                      ch = fgetc(fptr3);
		      if ( (ch != ' ') && (!feof(fptr3)) )
                      {
                       int temp6 = atoi(&ch);
                       temp = temp + (0.000001*temp6);
                       ch = fgetc(fptr3);
		      }
                     }
		    }    
                   }
		 }
	      }
	   }
	else
	{
	  int temp1 = atoi(&ch);
	  temp = temp1 + (temp * 10);
	  ch = fgetc(fptr3);
	}
       }	
       push(&list, temp);
       numNUMS++;
     }
    ch = fgetc(fptr3);
  }
   result = pop(&list);
   pop(&list);

 // Valid Expression 
  if(numOPS == (numNUMS - 1)){
    printf("Result: %f \n\n", result);
    fclose(fptr3);
    return EXIT_SUCCESS;
  }
  else{
    printf("ERROR: Invalid Expression \n\n");
    fclose(fptr3); 
    return EXIT_FAILURE;
  }  
}
