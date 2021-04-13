#include <stdio.h>
#include <assert.h>
#include <string.h>

int main (int argc, char *argv[]){
	printf("TESTING SHA512 ALGORITHM\n");
	printf("========================\n");
	printf("Comparing the output of the sha512.f function against the sha512sum function using main.c\n");
	printf("Sha512.f:\t%s\n", argv[1]);
	printf("Sha512sum:\t%s\n", argv[2]);
	printf("\n");

	assert(strcmp(argv[1], argv[2]) == 0);
	printf("Both algorithms produce equal hash digests.\n");
}
