#include <stdio.h>
#include <inttypes.h>


#define W 64
#define WORD uint64_t
#define PF PRIX32
#define BYTE uint8_t

union Block{
	// Set for 32, not 64
	BYTE bytes[128];
	WORD words[32];
};


int main(int argc, char *argv[]){
	// Iterator.
	int i = 0;

	union Block B;
	uint64_t nobits = 0;
	// Error check...
	FILE *f;

	// Open file from command line for reading
	f = fopen(argv[1], "r");

	size_t nobytes;

	nobytes = fread(&B.bytes, 1, 128, f);
	printf("Read %d bytes.\n", nobytes);
	nobits = nobits + (8 * nobytes);

	// Print the 16 32-bit words 
	for(i = 0; i < 32; i++){
		printf("%08" PF " ", B.words[i]);

		if((i + 1) % 8 == 0){
			printf("\n");
		}
	}

	while(!feof(f)){
		// Picking up end of line char, this should not be an issue?
		nobytes = fread(&B.bytes, 1, 128, f);
		printf("Read %d bytes.\n", nobytes);
		nobits = nobits + (8 * nobytes);

		// Print the 16 32-bit words 
		for(i = 0; i < 32; i++){
			printf("%08" PF " ", B.words[i]);

			if((i + 1) % 8 == 0){
				printf("\n");
			}
		}
	}

	fclose(f);
	printf("Total bits read: %d\n", nobits);



	return 0;
}
