#include <stdio.h>
#include <assert.h>

// info - https://www.youtube.com/watch?v=f9EbD6iY9zI
//
// ihttps://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf
// 	@ Section 5.

/*
 * Constants.
 * (Double check these are correct.)
	428a2f98d728ae22 7137449123ef65cd b5c0fbcfec4d3b2f e9b5dba58189dbbc
	3956c25bf348b538 59f111f1b605d019 923f82a4af194f9b ab1c5ed5da6d8118
	d807aa98a3030242 12835b0145706fbe 243185be4ee4b28c 550c7dc3d5ffb4e2
	72be5d74f27b896f 80deb1fe3b1696b1 9bdc06a725c71235 c19bf174cf692694
	e49b69c19ef14ad2 efbe4786384f25e3 0fc19dc68b8cd5b5 240ca1cc77ac9c65
	2de92c6f592b0275 4a7484aa6ea6e483 5cb0a9dcbd41fbd4 76f988da831153b5
	983e5152ee66dfab a831c66d2db43210 b00327c898fb213f bf597fc7beef0ee4
	c6e00bf33da88fc2 d5a79147930aa725 06ca6351e003826f 142929670a0e6e70
	27b70a8546d22ffc 2e1b21385c26c926 4d2c6dfc5ac42aed 53380d139d95b3df
	650a73548baf63de 766a0abb3c77b2a8 81c2c92e47edaee6 92722c851482353b
	a2bfe8a14cf10364 a81a664bbc423001 c24b8b70d0f89791 c76c51a30654be30
	d192e819d6ef5218 d69906245565a910 f40e35855771202a 106aa07032bbd1b8
	19a4c116b8d2d0c8 1e376c085141ab53 2748774cdf8eeb99 34b0bcb5e19b48a8
	391c0cb3c5c95a63 4ed8aa4ae3418acb 5b9cca4f7763e373 682e6ff3d6b2b8a3
	748f82ee5defb2fc 78a5636f43172f60 84c87814a1f0ab72 8cc702081a6439ec
	90befffa23631e28 a4506cebde82bde9 bef9a3f7b2c67915 c67178f2e372532b
	ca273eceea26619c d186b8c721c0c207 eada7dd6cde0eb1e f57d4f7fee6ed178
	06f067aa72176fba 0a637dc5a2c898a6 113f9804bef90dae 1b710b35131c471b
	28db77f523047d84 32caab7b40c72493 3c9ebe0a15c9bebc 431d67c49c100d4c
	4cc5d4becb3e42b6 597f299cfc657e2a 5fcb6fab3ad6faec 6c44198c4a475817 

 */
void bin_print(unsigned int i){
	// Num of bits in an integer
	int j = sizeof(unsigned int) * 8 - 1;
	unsigned int k;

	for (; j >= 0; j--){
		k = ((1 <<j) & i) ? 1: 0;
		printf("%d", k);
	}

}

/*
 * The following operations are used in the secure hash algorithm specifications.
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


void test_rot(){
	// Should implement at a later point
	unsigned int i = 0x0f0f0f0f;

	// rotl
	printf("Rotate left test.\n");
	printf("Start position:\n");
	bin_print(i);
	printf("\n================================\n");
	rotl(i);

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
	
}

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

	return 0;
}

