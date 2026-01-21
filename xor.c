/*
   @Author - Torin Costales
   CS 333

   */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#define BUF_SIZE 4096
int main(int argc, char* argv[]){
	char * def_key = "Xerographic";
	char * key= def_key;
	int key_len =0;
	int opt=0;
	unsigned char buf[BUF_SIZE];
	ssize_t bytes_read;
	
	
	while((opt= getopt(argc, argv, "k:")) != -1){
		switch(opt){
			case 'k':
				if(optarg != NULL && optarg[0] != '\0'){
					key = optarg;
				}
				else{
					key = def_key;
				}
				break;

			case '?':
				if(optopt =='k'){
					key = def_key;
				}
				else{
					fprintf(stderr, "Invalid option.\n");
					exit(EXIT_FAILURE);
				}
				break;

			default:
				fprintf(stderr, "Invalid option.\n");
				exit(EXIT_FAILURE);

		}

	}

	key_len= strlen(key);
	while((bytes_read = read(STDIN_FILENO, buf, BUF_SIZE)) >0){
		ssize_t total_bytes =0;
		while(total_bytes < bytes_read){
			unsigned char * output = buf + total_bytes;
			size_t remaining = (size_t)(bytes_read - total_bytes);
			ssize_t bytes_writ = write(STDOUT_FILENO, output, remaining);
			if (bytes_writ < 0){
				perror("write");
				exit(EXIT_FAILURE);
			}
			total_bytes += bytes_writ;
		}
	}
	if (bytes_read < 0){
		perror("read");
		exit(EXIT_FAILURE);
	}
	printf("%d\n", key_len);

	return 0;

}
