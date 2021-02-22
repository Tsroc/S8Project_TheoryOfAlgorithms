#include <stdio.h>
#include <assert.h>
#include <stdint.h>

// info - https://www.youtube.com/watch?v=f9EbD6iY9zI
//
// ihttps://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf
// 	@ Section 5.

/*
 * Constants.
 * (Double check these are correct.)
 */
// This is being truncated when passed into a method
// There is a few solutions to this problem
// https://stackoverflow.com/questions/2810280/how-to-store-a-64-bit-integer-in-two-32-bit-integers-and-convert-back-again.
// malloc: int *integer_array = (int*)malloc(80 * sizeof(int));
// int64_t, unsure if can use this package... need to check: will simpliy things.
// Contained within standard library: stdint.h
//
// To test: 
// 	https://www.rapidtables.com/convert/number/binary-to-hex.html
// 	https://www.exploringbinary.com/binary-converter/
// Update: the above is untrue


//static const uint64_t k[80] = {
static const uint64_t k[80] = {
	0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
	0x3956c25bf348b538, 0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
	0xd807aa98a3030242, 0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,         
	0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235, 0xc19bf174cf692694,
	0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
	0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
	0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4,
	0xc6e00bf33da88fc2, 0xd5a79147930aa725, 0x06ca6351e003826f, 0x142929670a0e6e70,
	0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
	0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b,
	0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30,
	0xd192e819d6ef5218, 0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
	0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
	0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
	0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
	0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b,
	0xca273eceea26619c, 0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
	0x06f067aa72176fba, 0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
	0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,
	0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817
};

void print_k(){
	// I do not think this is correct...
	printf("Len: %d\n", sizeof(k)/sizeof(uint64_t));
	//for(int i = 0; i < sizeof(k)/sizeof(unsigned long); i++){
	for(int i = 0; i < 2; i++){
		//printf("%016llX : %lu : ", k[i], k[i]);
		printf("%x : %016llX : %lu : ", k[i], k[i], k[i]);
		bin_print(k[i]);
		printf("\n");

	}



	/*
	int j = sizeof(unsigned int) * 16 - 1;
	unsigned int k;

	for (; j >= 0; j--){
		k = ((1 <<j) & 447483649L) ? 1: 0;
		printf("%d", k);
	}
	*/
}


void bin_print(unsigned int i){
	// Num of bits in an integer
	int j = sizeof(unsigned int) * 16 - 1;
	printf("\nSize: %d\n", j);
	unsigned int k;

	for (; j >= 0; j--){
		k = ((1 <<j) & i) ? 1: 0;
		printf("%d", k);
	}

}

// http://marvin.cs.uidaho.edu/Teaching/CS504/bitOps.html
//void bin_print(uint64_t i){
/*
void bin_print(uint64_t i){
	// Num of bits in an integer
	long j = sizeof(int) * 16 - 1;
	printf("\nSize: %d\n", j);
	unsigned long k;

	printf("i0x: %016llx, ilu: %lu\n", i, i);
	for (; j >= 0; j--){
		//printf("F%lu\n", 1<<j);
		// If the i is bigger than int, breaks...
		k = ((1<<j) & i) ? 1: 0;
		printf("%d", k);
	}

}
*/

/*
 *
 * [FUNCTIONS]
 *
 * The following operations are used in the secure hash algorithm specifications.
 *
 *
 */


/*
 * The rotate left (circular left shift) operation.
 *
 * ROTL n(x) = (x<< n) Bitwise OR (x>> w-n).
 *
 * x = 	A .w-bit word
 * n = 	Number of bits to be rotated or shifted when a word is operated upon.
 * 	In this case, the for loop represents each bit rotation. 
 * w =	Number of bits in a word.
 *
 */
void rotl(unsigned int x){
	// Should be a constant, 64-bit, w=sizeof(unsigned int)*16 - 1;
	int w = sizeof(unsigned int)*8 - 1;

	for(int n = 0; n<w; n++){
		//shr(i, j);
		bin_print((x << n)|(x >> w-n));
		printf("\n");
	}

}

/*
 * The rotate right (circular right shift) operation.
 *
 * ROTR n(x) = (x>> n) Bitwise OR (x<< w -n).
 *
 * x = 	A w-bit word.
 * n = 	Number of bits to be rotated or shifted when a word is operated upon.
 * 	In this case, the for loop represents each bit rotation.
 * w =	Number of bits in a word.
 *
 */
void rotr(unsigned int x){
	// Should be a constant, 64-bit, w=sizeof(unsigned int)*16 - 1;
	int w = sizeof(unsigned int)*8 - 1;

	for(int n = 0; n<w; n++){
		//shr(i, j);
		bin_print((x >> n)|(x << w-n ));
		printf("\n");
	}

}

/*
 * The right shift operation.
 *
 * SHR n(x) = x >> n
 *
 *
 * x = 	A w-bit word.
 * n = 	The amount to shift.
 *
 */
void shr(unsigned int x, int n){
	bin_print(x >> n );
	printf("\n");

}


/*
 * Testing rotl and rotr functions.
 * Should be altered once return types are implemented.
 *
 */
void test_rot(){
	// Should implement at a later point
	unsigned int i = 0xF0F0F0F0;

	// rotl
	printf("Rotate left test.\n");
	printf("Start position:\n");
	bin_print(i);
	printf("\n================================\n");
	rotl(i);

	/*
	// rotr 
	printf("Rotate right test.\n");
	printf("Start position:\n");
	bin_print(i);
	printf("\n================================\n");
	rotr(i);

	// shr
	printf("Right shift test, shift=(1,4).\n");
	printf("Start position:\n");
	bin_print(i);
	printf("\n================================\n");
	for(int j=0; j<6;j++)
		shr(i,j);
	*/
	
}


/*
 *
 * [PREPROCESSING]
 *
 * Preprocessing consists of three steps:
 * 	padding the message
 * 	parsing the message into message blocks
 * 	setting the initial hash value
 *
 *
 */


/*
 * Padding
 * The purpose of this padding is to ensure that the padded message is a multiple of 512 or 1024 bits, depending on the algorithm.
 *
 */

/*
 * Parsing
 * The message and its padding must be parsed into N m-bit blocks.
 *
 */

/*
 * Initial hash value
 * Before hash computation begins for each of the secure hash algorithms, the initial hash value, H (0), must be set.
 *
 */





/*
 * Class work.
 */
void class_work(){
	unsigned int i = 0x0f0f0f0f;

	printf("Original: : ");
	bin_print(i);
	printf("\n");
	printf("\t%x\t%u\n\n", i, i);


	for(int j =  0; j < (sizeof(int)*8); j++){
	
		//printf("(1 << 53u) & %08x: : ", j, i);
		//bin_print((1 << j) & i);
		//printf("\n");

		bin_print(1 << j); printf("\n");
		bin_print(i); printf("\n");
		printf("--------------------------------\n");
		bin_print(((i << j) & i)); printf("\n\n");

	}

}

int main(int argc, char *argv[]){
	//class_work();

	test_rot();
	//print_k();
	uint32_t = 0xF0F0F0F0;
		
	



	return 0;
}

