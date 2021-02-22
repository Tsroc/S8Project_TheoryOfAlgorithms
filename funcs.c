#include <stdio.h>
//#include <stdint.h>
#include <inttypes.h>


#define WORD uint32_t
#define PF PRIX32
//#define Ch(x, y, z) 



// function operates on 64-bit words, which are represented as x, y, and z
// Ch(x, y,z) = (x AND y)XOR((Bitwise complement)x AND z)
WORD Ch(WORD x, WORD y, WORD z){
	return (x&y)^(~x&z);

}


// function operates on 64-bit words, which are represented as x, y, and z
// Maj(x, y,z) = (x AND y)XOR(x AND z)XOR(y AND z)
WORD Maj(WORD x, WORD y, WORD z){
	return (x&y)^(x&z)^(y&z);

}

/*
 * The rotate left (circular left shift) operation.
 *
 * ROTL n(x) = (x<< n) Bitwise OR (x>> w-n).
 * 
 * x =  A .w-bit word
 * n =  Number of bits to be rotated or shifted when a word is operated upon.
 *      In this case, the for loop represents each bit rotation.
 *      w =  Number of bits in a word.
 *
 */
WORD rotl(WORD x, unsigned int n){
	int w = sizeof(WORD)*8 - 1;
	return (x << n)|(x >> w-n);

}

/*
 * The rotate right (circular right shift) operation.
 * 
 * ROTR n(x) = (x>> n) Bitwise OR (x<< w -n).
 * 
 * x =  A w-bit word.
 * n =  Number of bits to be rotated or shifted when a word is operated upon.
 *      In this case, the for loop represents each bit rotation.
 * w =  Number of bits in a word.
 *
 */
WORD rotr(WORD x, unsigned int n){
	int w = sizeof(WORD)*8 - 1;
	return (x >> n)|(x << w-n);

}

/*
 * The right shift operation.
 * 
 * SHR n(x) = x >> n
 *
 * x =  A w-bit word.
 * n =  The amount to shift.
 *
 */
WORD shr(WORD x, unsigned int n){
	return x >> n;

}

WORD big_sigma0(WORD x){
	rotr(x, 2)^rotr(x, 13)^rotr(x, 22);
}

WORD big_sigma1(WORD x){
	rotr(x, 6)^rotr(x, 11)^rotr(x, 25);
}


WORD little_sigma0(WORD x){
	rotr(x, 7)^rotr(x, 18)^shr(x, 3);
}

WORD little_sigma1(WORD x){
	rotr(x, 17)^rotr(x, 19)^shr(x, 10);
}


int main(int argc, char *argv[]){
	WORD x = 0xf0f0f0f0;
	WORD y = 0x0f0f0f0f;
	WORD z = 0xf0f0f0f0;
	WORD ansCh = Ch(x, y, z);
	WORD ansMaj = Maj(x, y, z);
	WORD ansRotl = rotl(x, 4);
	WORD ansRotr = rotr(x, 4);
	WORD ansShr = shr(x, 16);

	printf("ch(%08" PF ",%08" PF ",%08" PF ")=%08" PF "\n", x, y, z, ansCh);
	printf("maj(%08" PF ",%08" PF ",%08" PF ")=%08" PF"\n", x, y, z, ansMaj);
	printf("rotl(%08" PF ", 4)=%08" PF"\n", x, ansRotl);
	printf("rotr(%08" PF ", 4)=%08" PF"\n", x, ansRotr);
	printf("shr(%08" PF ", 16)=%08" PF"\n", x, ansShr);

	return 0;
}



