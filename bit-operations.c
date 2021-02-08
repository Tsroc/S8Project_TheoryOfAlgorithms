#include <stdio.h>


void bin_print(unsigned int i){
	// Num of bits in an integer
	int j = sizeof(unsigned int) * 8 - 1;
	int k;

	for (; j >= 0; j--){
		k = ((1 <<j) & i) ? 1: 0;
		printf("%d", k);
	}

}

int main(int argc, char *argv[]){

	unsigned int i = 0x0f0f0f0f;

	printf("Original: : ");
	bin_print(i);
	printf("\n");
	printf("\t%x\t%u\n\n", i, i);


	for(int j =  0; j < (sizeof(int)*8); j++){
		/*
		printf("(1 << 53u) & %08x: : ", j, i);
		bin_print((1 << j) & i);
		printf("\n");
		*/
		bin_print(1 << j); printf("\n");
		bin_print(i); printf("\n");
		printf("--------------------------------\n");
		bin_print(((i << j) & i)); printf("\n\n");

	}

	return 0;
}

