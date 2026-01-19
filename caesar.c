/*
   @Author- Torin Costales
   CS 333
   Lab 1 
   caesar.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int main (int argc, char * argv[]){
	
	int opt; 
	int shift_amt =3;
	int c=0;
	bool encrypt = true; 
	int effective_shift = 0;
	while((opt= getopt(argc, argv, "eds:")) != -1){
		switch(opt) 
		{
			case 'e':{
				encrypt = true;
				break;
				 }
			case 'd':{
				encrypt = false;
				break;
				 }
			case 's':{
				unsigned int length = strlen(optarg);
				unsigned int i = 0;
				for(i = 0; i < length; i++){
					if(!isdigit(optarg[i])){
						fprintf(stderr, "Shift amount must be a number (0>= or <=95)");
						exit(EXIT_FAILURE);
					}
				}

				shift_amt = atoi(optarg);
				if(shift_amt > 95 || shift_amt < 0){
					fprintf(stderr, "Shift value exceeds 95 or is negative\n"); 
					exit(EXIT_FAILURE);
				}
				break;
				 }
			default:{ 
				fprintf(stderr, "Please enter valid flags (eds)"); 
				exit(EXIT_FAILURE);
				}
		}

	}

	if (encrypt){
		effective_shift = shift_amt;
	}
	else{
		effective_shift = 95 - shift_amt;
	}

	while((c = getchar()) != EOF){
		if (c >= 32 && c <= 126){
			int position = c - ' ';
			int shifted = position + effective_shift;
			int wrap = shifted % 95;
			int output_char = wrap + ' ';
			putchar(output_char);

		}
		else{
			putchar(c);
		}
	}
	return 0;
}
