#include "funcs.h"
#include "main.h"

// Section 2.2.2
WORD ROTL(WORD x, unsigned int n){
	return ( (x<<n)|(x>>(WLEN-n)) );
}	

WORD ROTR(WORD x, unsigned int n){
       	return ( (x>>n)|(x<<(WLEN-n)) );
}

WORD SHR(WORD x, unsigned int n){
       	return ( x>>n );
}

// Section 4.1.3
WORD CH(WORD x, WORD y, WORD z){
       	return ( (x&y)^(~x&z) );
}

WORD MAJ(WORD x, WORD y, WORD z){
       	return ( (x&y)^(x&z)^(y&z) );
}

WORD SIG0(WORD x){
	return ( ROTR(x,28)^ROTR(x,34)^ROTR(x,39) );
}

WORD SIG1(WORD x){
       	return ( ROTR(x,14)^ROTR(x,18)^ROTR(x,41) );
}

WORD Sig0(WORD x){
	return ( ROTR(x,1)^ROTR(x,8)^SHR(x,7) );
}

WORD Sig1(WORD x){
	return ( ROTR(x,19)^ROTR(x,61)^SHR(x,6) );
}
