/*
   @Author- Torin Costales
   CS 333
   Lab 1 
   caeser.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

int main (int argc, char * argv[]){
	
	int opt; 
	int shift_amt =0;
	while((opt= getopt(argc, argv, "eds:")) != -1){
		switch(opt) 
		{
			case 'e':
				printf("encrypt\n");
				break;
			case 'd':
				printf("decrypt\n");
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
				printf("encrypt\n");
				shift_amt = 3;
				break;
		}
	}
	printf("Shift amt:%d", shift_amt);


	return 0;
}
