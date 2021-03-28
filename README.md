### Project spec
C programming language to calculate the SHA512 value of an input file.  
Your program must take the name or path of the file as a command line argument and output the SHA512 digest of it.  
You cannot use any external libraries.  
Your program must compile using gcc or clang
You must include a Makefile which compiles it upon make being called in the project folder.  
You must include tests which run upon make test being called.  
You should also include in your repository an appropriate .gitignore file and a README.md.  



# S8Project_TheoryOfAlgorithms

## Description of repository:
This program, written in the C programming language, calculates the SHA512 value of an input file.

__File structure__ 
- Makefile:		Recipes for compiling the program.
- funcs.c: 		Implements the sha512 functions described in section 4 of the secure hash standard.
- funcs.h		Describes the funcs API.
- main.c		Handles command line options.
- main.h:		Global constants and definitions.
- sha512.c		Implements the sha512 functions described in sections 5 and 6 of the secure hash standard.
- sha512.h		Describes the sha512 API.

## Compilation instructions:

__Command line inputs__ 
The following command line inputs are accepted.
- v: 		Prints the program version to screen.
- o:		Prints the hash digest for the input file to console.
- w: 		Writes the hash digest for the input file to output file. 




## What is SHA512, why is it important:
SHA-2 (Secure Hash Algorithm 2) is a set of cryptographic hash functions designed by the United States National Security Agency (NSA) and first published in 2001. {https://en.wikipedia.org/wiki/SHA-2}

No longer considered secure?

This is not encryption, cannot be reversed, why? Does not need to be reversed

#### Why can't we reverse the SHA512 algorithm to retrieve the original message from a hash digest?


#### Can you design an algorithm that, given enough time, will find input messages that give each of the possible 512-bit strings?


#### How difficult is it to find a hash digest beginning with at least twelve zeros?
