#include <stdio.h>
#include <inttypes.h>


#define W 64
#define WORD uint64_t
#define PF PRIX64
#define BYTE uint8_t

union Block{
	// Set for 32, not 64
	BYTE bytes[128];
	WORD words[16];
	uint64_t sixf[16];
};

enum Status {
	READ, PAD, END
};

// Get the next block
int next_block(FILE *f, union Block *B, enum Status *S, uint64_t *nobits){

	// Number of bytes to read.
	size_t nobytes;


	if(*S == END){
		return 0;

	}
	else if(*S == READ){
		// Try to read 128 bytes.
		nobytes = fread(B->bytes, 1, 128, f);
		// Calculate the total bits read so far.
		*nobits = *nobits + (8 * nobytes);

		// Enough room for padding.
		if(nobytes == 128){
			return 1;
		}
		else if(nobytes < 119){
			// Append a 1 bit ( and seven 0 bits to make the byte)
			B->bytes[nobytes++] = 0x80;
			while(nobytes++ < 120){
				B->bytes[nobytes] = 0x00;
			}
			// Check BIG ENDIAN
			B->sixf[15] = *nobits;
			// Say this is the last block
			*S = END;
		}else{
			// Gotten to the end of the input message,
			// Not enough room in this block for all padding.
			// // Append a 1 bit (and seven 0 bits to make a full byte.)
			B->bytes[nobytes] = 0x80;
			// Append 0 bits.
			while(nobytes++ < 128){
				B->bytes[nobytes] = 0x00;
			}
			// Change the status to PAD.
			*S = PAD;


		}

	} else if (*S == PAD){
		nobytes = 0;

		// Append 0 bits.
		while(nobytes++ < 120){
			B->bytes[nobytes] = 0x00;
		}
		// Check BIG ENDIAN
		// This may be incorrect, sixf may need resized.
		B->sixf[15] = *nobits;
		// Change the status to PAD.
		*S = END;


	}
	return 1;


}



int main(int argc, char *argv[]){
	// Iterator.
	int i = 0;

	union Block B;
	uint64_t nobits = 0;

	enum Status S = READ;
	// Error check...
	FILE *f;
	f = fopen(argv[1], "r");

	// Loop through (preprocessed) blocks
	while(next_block(f, &B, &S, &nobits)){
		for( i = 0; i< 16; i++){
			printf("%016" PF " ", B.words[i]);
		}
		printf("\n");


	}

	fclose(f);
	printf("Total bits read: %d\n", nobits);



	return 0;
}
