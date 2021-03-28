/* main.h - SHA512 algorithm */

#ifndef _MAIN_H
#define _MAIN_H

#include <inttypes.h>

#define WORD uint64_t
#define WLEN 64
#define PF PRIx64
#define BYTE uint8_t

// For keeping track of where we are with the input message/padding.
enum Status { 
	READ, PAD, END
};


#endif /* _MAIN_H */
