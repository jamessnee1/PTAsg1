/***************************************************************************
* COSC1283/1284 - Programming Techniques
* Semester 2 2013 Assignment #1 
* Full Name        : James Snee
* Student Number   : s3369721
* Yallara Username : s3369721
* Course Code      : COSC1284
* Program Code     : BP094
* Start up code provided by Paul Miller and Lin Padgham
***************************************************************************/
#include "assign1.h"

int *tos, *p1;
int stack[SIZE];
/***************************************************************************
* This source file contains important functions to be developed and
* used by various menu options, as indicated. Note that every
* function has as its first parameter the optionsStats array, which
* will be appropriately updated for later reporting of menu option 6.
* You may ignore this parameter and its relevance to each function
* until you develop the sessionSummary() function.
 **************************************************************************/

/**************************************************************************
* perfect_squares() - implements the "Perfect Squares" option (requirement 
* 2) from the main menu. You need to determine whether the number passed
* in is a perfect square and let the user know if it is or not. You also
* need to print the perfect square before and after this value. Finally
* you need to update the option_stats variable appropriately.
**************************************************************************/
void perfect_squares(int * option_stats, unsigned number)
{
	char charNumber[SQUARENUMBERINPUT + EXTRA_SPACES];
	int square, roundup, rounddown; 
	double result;
	clearScreen();
	
	printf("\nPerfect Squares\n");
	printf("------------------\n\n");
	
	printf("Enter a positive integer (1-100000): ");
	
	/*!=NULL is the test for ctrl-D*/
	while (fgets(charNumber, SQUARENUMBERINPUT + EXTRA_SPACES, stdin) != NULL){
	

			if (charNumber[strlen(charNumber) - 1] != '\n'){
				printf("Error: Input was too long! Please try again.\n");
				read_rest_of_line();
		
			}
			else if (strcmp(charNumber, "\n") == 0){
				return;
			}

			else if ((number = atoi(charNumber)) < 0){
				printf("Error: Number is a negative! Please try again.\n");
				read_rest_of_line();
			}
		
			else{
				charNumber[strlen(charNumber) - 1] = '\0';
				number = atoi(charNumber);
			}
	
	
	for (square = 0; square <= number; square++){
		
		if (number == square * square){
			printf("%u is a perfect square.\n", number);
			printf("Perfect square before: %i\n", (square - 1) * (square - 1));
			printf("Perfect square after: %i\n", (square + 1) * (square + 1));
			return;
			
		}
	}
		
		
		printf("%u is not a perfect square.\n", number);
		result = sqrt(number);
		roundup = (int)(result + 1);
		rounddown = (int)(result);
		printf("Perfect square before: %i\n", rounddown*rounddown);
		printf("Perfect square after: %i\n", roundup*roundup);
		
		
		
		option_stats[OPTION_1]+=1;
		return;
		}
}

/**************************************************************************
* ascii_to_binary() - implements the "ASCII to Binary Generator" option
* (requirement 3) from the main menu. Essentially, you need to implement
* an algorithm for conversion of integers to binary and apply this to 
* every character in the input array (called 'ascii' here) and print out
* the result. Finally, you need to update the option_stats array 
* appropriately 
**************************************************************************/
void ascii_to_binary(int * option_stats, char * ascii)
{
	
	int count = 0;
	int convertedAscii[ASCII_LENGTH] = {0};
	clearScreen();

	
	printf("\nASCII to Binary Generator\n");
	printf("---------------------------\n\n");
	
	
	printf("Enter a string (1-5 characters): ");
	
	while(fgets(ascii, ASCII_LENGTH + EXTRA_SPACES, stdin) != NULL){
	
	if (ascii[strlen(ascii) - 1] != '\n'){
			printf("Error: Input was too long! Please try again.\n");
			read_rest_of_line();
		
		}
		else if (strcmp(ascii, "\n") == 0){
			return;
		}
		else{
			ascii[strlen(ascii) - 1] = '\0';
			
		
		
		}
	
	
	printf("\nBinary representation: ");
	
	
	for (count = 0; count < strlen(ascii); count++){
	
		convertedAscii[count] = ascii[count];
		printf("%i ", decimaltobinary(convertedAscii[count]));
	
	}
	
	
	printf("\n");
	option_stats[OPTION_2]+=1;
	return;
	}
}
	


/**************************************************************************
* matching_brackets() - implements the "Matching Brackets" option 
* (requirement 4) from the main menu. You need to implement an algorithm 
* which will parse a string passed in and determine whether the brackets 
* all match, including the type of brackets. You need to account for 
* {} [] () and you also need to allow for the nesting of brackets. 
* You need to tell the user whether the brackets match or not. Finally you
* need to update the option_stats array appropriately.
**************************************************************************/
void matching_brackets(int * option_stats, char * test_string)
{
	
	
	
	int i = 0, j = 0, stackelem = 0, mismatch = 0;
	char brackets[TEST_STRING_LENGTH] = {0};
	
	tos = stack;
	p1 = stack;
	
	
	clearScreen();
	printf("Matching Brackets\n");
	printf("-----------------\n\n");
	
	
	printf("Enter a string (1-20 characters): ");
	
	while(fgets(test_string, TEST_STRING_LENGTH + EXTRA_SPACES, stdin) != NULL){
	
	if (test_string[strlen(test_string) - 1] != '\n'){
			printf("Error: Input was too long! Please try again.\n");
			read_rest_of_line();
		
		}
		else if (strcmp(test_string, "\n") == 0){
			return;
		}
		else{
			test_string[strlen(test_string) - 1] = '\0';
			
		
		}

	
	for (i = 0; test_string[i] != '\0'; i++){
      
	    if (test_string[i] == '('){
	      stackelem = 1;
	      strcat(brackets, "(");
	      push(stackelem);
	
			
			
	    }
	    else if (test_string[i] == ')'){
	      strcat(brackets, ")");
	
	     
	      if (pop() == -1){
		printf("Brackets do not match.\n");
		return;
	      }
	      
		
		
	    }
	    else if (test_string[i] == '{'){
	      stackelem = 2;
	      strcat(brackets, "{");
	      push(stackelem);	
		  
		
	    }
	    else if (test_string[i] == '}'){
	      strcat(brackets, "}");
	      
	      if (pop() == -1){
		printf("Brackets do not match.\n");
		return;
	      }
	      
		
	    }
	    else if (test_string[i] == '['){
	      stackelem = 3;
	      strcat(brackets, "[");
	      push(stackelem);
		
		
	    }
	    else if (test_string[i] == ']'){
	      strcat(brackets, "]");
	      
	      if (pop() == -1){
		printf("Brackets do not match.\n");
		return;
	      }
	      
	  }

      }
	
	
  
	for (j = 0; j < sizeof(stack)/sizeof(int); j++){

	 
	    if (stack[j] == 1 || stack[j] == 2 || stack[j] == 3){
	      printf("Brackets do not match.\n");
	      mismatch = 1;
	      break;
	    }
      
      }

      
      if (mismatch == 1){
	return;
      }
      
      printf("Brackets match!\n");
      option_stats[OPTION_3]+=1;
      return;
	} 
}

/**************************************************************************
* format_text() - implements the "Formatting Text" option (requirement 6)
* from the main menu. You will need to parse the text, adding newlines 
* so that no line is longer than "width" which means you will need to 
* replace the first white space character before this with the newline. You
* then need to insert extra spaces so that lines are spaced as evenly as 
* possible. Finally you want to update the option_stats array appropriately.
* 
**************************************************************************/
void format_text(int * option_stats, unsigned width, char * text)
{
	BOOLEAN finished = FALSE;
	char input[TEXT_INT_INPUT + EXTRA_SPACES];
	int wordcount = 0;
	int col = 0, i;
	char * wordPtr;

	
	
	
	clearScreen();
	printf("\nFormatting Text\n");
	printf("------------------\n\n");
	
	do{
	
		printf("Enter an integer (maximum number of chars per line): ");
		
		fgets(input, TEXT_INT_INPUT + EXTRA_SPACES, stdin);
		
		if (input[strlen(input) - 1] != '\n'){
			printf("Error: Input was too long! Please try again.\n");
			read_rest_of_line();
		
		}
		
		else if (strcmp(input, "\n") == 0){
			return;
		}
		
		else{
			input[strlen(input) - 1] = '\0';
			/*convert input to an int, and store in width variable*/
			width = atoi(input);
			finished = TRUE;
		
		}
	
	
	
	}
	while(!finished);
	
	finished = FALSE;
	
	do{
		printf("Enter some sentences (between 150 - 200 chars): ");
	
		fgets(text, TEXT_LENGTH + EXTRA_SPACES, stdin);
	
		if (text[strlen(text) - 1] != '\n'){
		  printf("Error: Input was too long! Please try again.\n");
		  read_rest_of_line();
		
		}
		
		else if (strcmp(text, "\n") == 0){
			return;
		}
		
		else if (strlen(text) < 150){
		  printf("Error: Input was too short! Please enter between 150 and 200 characters.\n");
		  read_rest_of_line();
		}
		
		else{
			text[strlen(text) - 1] = '\0';
			finished = TRUE;
		
		}
	}
	while(!finished);
	
	/*process text using the number entered*/
	printf("\nFormatted Text:\n");
	
	wordPtr = strtok(text, " ");
	
	
	while (wordPtr != NULL){ 
	  
	  
	  for (i = 0; i <= strlen(wordPtr); i++){
	    col++;
	    printf("%c", wordPtr[i]);
	    
	    if (i == strlen(wordPtr)){
	      printf(" ");
	    }
	    
	    if (col == width){  
	    printf("\n");
	    col = 0;
	    
	    }
	      
	    
	     
	  }
	  
	  wordcount++;
	  
	  wordPtr = strtok(NULL, " ");
	  
	  
	}
	
	
	printf("\nWord count: %i\n", wordcount);
	printf("\n");

	option_stats[OPTION_4]+=1;
	 
}	

/**************************************************************************
* session_summary() - implements the "Session Summary" option (requirement
* 7) from the main menu. In this option you need to display the number of 
* times that each option has been run and then update the count of how 
* many times this function has been run.
**************************************************************************/
void session_summary(int * option_stats)
{
	option_stats[OPTION_5]+=1;
	clearScreen();	
		
	printf("\nSession Summary\n");
	printf("------------------\n");
	printf("Options      Count\n");
	printf("-------      -----\n");
	printf("%7d        	%2d\n", 1, option_stats[OPTION_1]);
	printf("%7d        	%2d\n", 2, option_stats[OPTION_2]);
	printf("%7d        	%2d\n", 3, option_stats[OPTION_3]);
	printf("%7d        	%2d\n", 4, option_stats[OPTION_4]);
	printf("%7d        	%2d\n", 5, option_stats[OPTION_5]);
	printf("\n");

}

/*Push and Pop functions*/

void push(int i)
{

  p1++;
  if(p1 == (tos+SIZE)) {
    printf("Stack Overflow.\n");
    exit(1);
  }
  *p1 = i;
  
}
 
int pop(void)
{
  
  if(p1 == tos) {
    return -1;
  }
  
  *p1 = 0;
  p1--;
  
  return *(p1+1);
}
