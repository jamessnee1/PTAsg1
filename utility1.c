/***************************************************************************
* COSC1283/1284 - Programming Techniques
* Semester 2 2013 Assignment #1 
* Full Name        : James Snee
* Student Number   : s3369721
* Yallara Username : s3369721
* Course Code      : COSC1284
* Program Code     : BP094
* Start up code provided by Paul Miller and Padgham
***************************************************************************/
#include "assign1.h"

/**************************************************************************
* read_rest_of_line() - clear the buffer of any leftover input. Call this 
* function whenever you detect leftover input in the buffer.
**************************************************************************/
void read_rest_of_line(void)
{
    int ch;
    /* read characters one at a time from standard input until there are
     * no characters left to read
     */
    while (ch=getc(stdin), ch!=EOF && ch!='\n');
    /* reset the error status of the input FILE pointer */
    clearerr(stdin);
}

/*Function to clear the screen*/
void clearScreen(void){

	int i;
	for (i = 0; i < SCREENSIZE; i++){
		putchar('\n');
	
	}

}

/*Function to convert a decimal number to binary*/
int decimaltobinary(int number){
  
	int binary = 0, k = 1, count = 0;
	
	
	while(number > 0){
		binary = binary + (number % 2) * k;
		k = k * 10;
	
		number = number/2;
		count++;
	}
	
	if (count == 7){
		printf("0");
	}
	else if (count == 6){
		printf("00");
	}
	else if (count == 5){
		printf("000");
	}
	else if (count == 4){
		printf("0000");
	}
	else if (count == 3){
		printf("00000");
	}
	else if (count == 2){
		printf("000000");
	}
	else if (count == 1){
		printf("0000000");
	}

    return binary;
}


