#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

#include "sha512.h"

void print_usage(){
	printf("Usage: main -v <temp> | main -o <temp> \n");
	exit(2);
}

int shaOutput(char *argc){
	FILE *f;
	f = fopen(argc, "r");
	sha512(f);
	fclose(f);
	return 0;
}

int shaWrite(char *argc){
	FILE *f;
	FILE *out = fopen("output.txt", "w");
	f = fopen(argc, "r");
	sha512w(f, out);
	fclose(f);
	fclose(out);
	return 0;
}

int main (int argc, char *argv[]){
	if(argc < 2) {
		print_usage();
	}

	int option;
	int vflag = 0;
	int oflag = 0;

	while((option = getopt(argc, argv, "vo:w:")) != -1){
		switch (option){
			case 'v':
				if(vflag){
					print_usage();
				} else {
					vflag++;
					oflag++;
				}

				printf("Version: SHA512 1.0\n");
				break;
			case 'o':
				if(oflag){
					print_usage();
				} else {
					vflag++;
					oflag++;
				}
				
				printf("SHA512 hash digest for %s.\n", optarg);
				shaOutput(optarg);
				break;
			case 'w':
				if(oflag){
					print_usage();
				} else {
					vflag++;
					oflag++;
				}
				
				shaWrite(optarg);
				printf("SHA512 hash digest for %s saved to output.txt.\n", optarg);
				break;
			default:
				printf("Error\n");
		}

	}

}
