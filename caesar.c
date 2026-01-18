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
	while((opt= getopt(argc, argv, "eds:")) != -1){
		switch(opt) 
		{
			case 'e':
				encrypt = true;
				break;
			case 'd':
				encrypt = false;
				break;
			case 's':
				unsigned int length = strlen(optarg);
				for(unsigned int i = 0; i < length; i++){
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
			default: 
				fprintf(stderr, "Please enter valid flags (eds)"); 
				exit(EXIT_FAILURE);
				break;
		}

	}
	while((c = getchar()) != EOF){
		if (c < 32 || c > 126){
			putchar(c);
		}
		else if(encrypt){
			int position = c - ' ';
			int result_enc = position + shift_amt;
			int result_fin = result_enc % 95;
			int output_char = result_fin + ' ';
			putchar(output_char);
		}
		else{
			printf("todo dec\n");
		}
	}
	

	//printf("Shift amt:%d", shift_amt);


	return 0;
}
