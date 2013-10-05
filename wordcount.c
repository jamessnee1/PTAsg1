#include <stdio.h>
#include <stdlib.h>

#define OUT 0
#define IN 1

int main(void){

  int c, lines = 0, words = 0, charsperline = 0, state;

  state = OUT;
    
  while((c = getchar()) != EOF){

  ++charsperline;
  if (c == '\n'){
    ++lines;

  }
  if (c == ' ' || c == '\n' || c == '\t')
	  state = OUT;

  else if (state == OUT){
    state = IN;
    ++words;


  }



  }



  printf("Lines are: %d, Words are: %d, Characters per line are: %d\n", lines, words, charsperline);	

return 0;
}