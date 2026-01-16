/*
   @Author- Torin Costales
   CS 333
   Lab 1 
   caeser.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
				shift_amt = atoi(optarg);
				break;
		}
	}
	printf("Shift amt:%d", shift_amt);


	return 0;
}
