/***************************************************************************
* COSC1283/1284 - Programming Techniques
* Semester 1 2013 Assignment #1 
* Full Name        : James Snee
* Student Number   : s3369721
* Yallara Username : s3369721
* Course Code      : COSC1284
* Program Code     : BP094
* Start up code provided by Paul Miller and Xiaodong Li
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


/* constants go here */
#define NUM_OPTION_STATS 5


/*Menu options defines*/
#define OPTION_1 0
#define OPTION_2 1
#define OPTION_3 2
#define OPTION_4 3
#define OPTION_5 4

/*Functions defines*/
#define SQUARENUMBERINPUT 7
#define SCREENSIZE 100	
#define ASCII_LENGTH 5
#define TEST_STRING_LENGTH 20
#define TEXT_LENGTH 200
#define TEXT_INT_INPUT 3
#define SIZE 20
#define STRING_LENGTH 200
#define NUMBER_OF_STRINGS 200

#define BINARY_LENGTH 40



/* This is used to compensate for the extra character spaces taken up by
   the '\n' and '\0' when user is asked for input through fgets(). */
#define EXTRA_SPACES 2

/* Specifies the maximum input length a user can enter for the options
   menu. */
#define MAX_OPTION_INPUT 1

/* provides us with a BOOLEAN type for using TRUE and FALSE */
typedef enum true_false
{
    FALSE=0,TRUE
} BOOLEAN;

/* function prototypes for each option to be implemented */
void perfect_squares(int * option_stats, unsigned number);
void ascii_to_binary(int * option_stats, char * ascii);
void matching_brackets(int * option_stats, char * test_string);
void format_text(int * option_stats, unsigned width, char * text);
void session_summary(int * option_stats);

/* function prototypes for additional functions contained in utility1.c */
void read_rest_of_line(void);
void clearScreen(void);
int decimaltobinary(int number);
void push(int i);
int pop(void);

