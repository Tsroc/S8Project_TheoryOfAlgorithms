#include <stdio.h>
#include <inttypes.h>


#define W 64
#define WORD uint64_t
#define PF PRIX64
#define BYTE uint8_t

// SHA512 works on blocks of 1024 bits.
union Block{
	// 8*128=1024 - dealing with block as bytes
	BYTE bytes[128];
	// 64*16=1024 - dealing with block as words.
	WORD words[16];
	// 128*8=1024 - dealing with the last 128 bits of the last block.
	// NOTE: Currently this is not well designed, it works but when the size is large enough it wil lfall apart as,
	// The length is just added to sixf[14]
	// This will need to be processed.
	uint64_t sixf[16];
};

// For keeping track of where we are with the input message/padding.
enum Status {
	READ, PAD, END
};

// Returns 1 if it created a new block from original message  or padding.
// Returns 0 if all paddied message has already been consumed.
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
		printf("%d, %d\n", nobytes, *nobits);

		// Enough room for padding.
		if(nobytes == 128){
			return 1;
		}
		else if(nobytes < 112){
			// Append a 1 bit ( and seven 0 bits to make the byte)
			B->bytes[nobytes] = 0x80;
			for(nobytes++;nobytes < 128; nobytes++){
				B->bytes[nobytes] = 0x00;
			}
			// Check BIG ENDIAN
			B->sixf[14] = *nobits;
			// Say this is the last block
			*S = END;
		}else{
			// Gotten to the end of the input message and not enough room
			// in this block for all padding.
			// // Append a 1 bit (and seven 0 bits to make a full byte.)
			B->bytes[nobytes] = 0x80;
			// Append 0 bits.
			for(nobytes++; nobytes < 128; nobytes++){
				B->bytes[nobytes] = 0x00;
			}
			// Change the status to PAD.
			*S = PAD;


		}

	} else if (*S == PAD){
		nobytes = 0;

		// Append 0 bits.
		for(;nobytes < 128; nobytes++){
			B->bytes[nobytes] = 0x00;
		}
		// Check BIG ENDIAN
		B->sixf[14] = *nobits;
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
