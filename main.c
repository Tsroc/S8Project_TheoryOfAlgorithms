#include <stdio.h>

#include "main.h"
#include "sha512.h"

int main(int argc, char *argv[]){
	/*
	WORD H[] = {
		0x6a09e667f3bcc908, 0xbb67ae8584caa73b, 0x3c6ef372fe94f82b, 0xa54ff53a5f1d36f1,
		0x510e527fade682d1, 0x9b05688c2b3e6c1f, 0x1f83d9abfb41bd6b, 0x5be0cd19137e2179
	};

	// Error check...

	*/
	FILE *f;
	f = fopen(argv[1], "r");
	// Calculate the SHA512 of f.
	sha512(f);
	// Print the final SHA512 hash.
	/*
	for(int i = 0; i < 8; i++)
	  printf("%016" PF, H[i]);
	printf("\n");
	*/
	fclose(f);
	return 0;
}
