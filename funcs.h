/* funcs.h - 512 Algorithm */


#ifndef _FUNCS_H
#define _FUNCS_H

#include "main.h"

// Section 2.2.2
WORD ROTL(WORD x, unsigned int n);
WORD ROTR(WORD x, unsigned int n); 
WORD SHR(WORD x,unsigned int n);

// Section 4.1.3
WORD CH(WORD x, WORD y, WORD z);
WORD MAJ(WORD x, WORD y, WORD z);

WORD SIG0(WORD x);
WORD SIG1(WORD x);
WORD Sig0(WORD x);
WORD Sig1(WORD x);

#endif /* _FUNCS_H */
