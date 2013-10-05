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
#include <stdio.h>
#include <string.h>




int main(void)
{
    int option_stats[NUM_OPTION_STATS] = {0};
	
	/*Variables for menu purposes*/
	char menuOption[MAX_OPTION_INPUT + EXTRA_SPACES];
	unsigned number = 0;
	char ascii[ASCII_LENGTH];
	char test_string[TEST_STRING_LENGTH];
	char text[TEXT_LENGTH + EXTRA_SPACES];
	unsigned width = 0;
	int choice;
	
	
	
    do{
	
		printf("\nMain Menu\n");
		printf("----------\n\n");
		
		printf("1) Perfect Squares\n");
		printf("2) ASCII to Binary Converter\n");
		printf("3) Matching Brackets\n");
		printf("4) Formatting Text\n");
		printf("5) Session Summary\n");
		printf("6) Exit\n");
		printf("\nSelect your option: ");
		
		
		/*prompt to take in menu option*/
		fgets(menuOption, MAX_OPTION_INPUT + EXTRA_SPACES, stdin);
		
		if (menuOption[strlen(menuOption) - 1] != '\n'){
			clearScreen();
			printf("Error: Input was too long! Please try again.\n");
			read_rest_of_line();
		
		}
		
		choice = atoi(menuOption);
		
		/*Switch statement for menu*/
		switch(choice){
		
			case 0:
				clearScreen();
				printf("Error: Not a valid option! Please try again.\n");
				break;
			case 1:
				perfect_squares(option_stats, number);
				break;
			case 2:
				ascii_to_binary(option_stats, ascii);
				break;
			case 3:
				matching_brackets(option_stats, test_string);
				break;
			case 4:
				format_text(option_stats, width, text);
				break;
			case 5:
				session_summary(option_stats);
				break;
			case 6:
				return EXIT_SUCCESS;
				break;
			case 7:
				clearScreen();
				printf("Error: Not a valid option! Please try again.\n");
				break;
			case 8:
				clearScreen();
				printf("Error: Not a valid option! Please try again.\n");
				break;	
			case 9:
				clearScreen();
				printf("Error: Not a valid option! Please try again.\n");
				break;	

		
		}
		
		
		
		
	}
	while(choice !=6);
    return EXIT_SUCCESS;
}
