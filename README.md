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




## Secure Hash Standard (SHS) 



### An explanation of what the SHA512 algorithm is and why it is important


__What is SHA512?__

SHA512 is a member of SHA-2, a set of cryptographic hash functions standardized by the United States National Institute of Standards and Technology. It was developed by the United States National Security Agency and published in 2001.
SHA512 is an iterative hash function which pads and processes an input message using 1024-bit message blocks. The 512-bit hash digest is computed using a compression function.
A cryptographic hash function is an algorithm that can be used to generate digests of messages, a fixed size numeric representation of the contents of a message.[1]
The hash digests are used to validate the authenticity of data, to detect whether data has been changed since the digests were generated.[2] 
 
Hash functions are generally used to verify that files being sent from one computer to another have been received as they were sent.
To do this the digest is sent with the message and the receiver can compare the digest sent with the message against the hash digest generated from the message, the data is proven to be unchanged if the digests are equal.
Hash functions are also widely used for password verification. Because storing passwords may compromise security, websites can store the password hash value and use this to verify the user's password.



__Properties of a hash function__

A hash function has the following properties:[3]
- The hash value is fully determined by the data being hashed.
- The hash function uses all the input data.
- The hash function "uniformly" distributes the data across the entire set of possible hash values.
- The hash function generates very different hash values for similar strings. 

These properties result in a hash digest which is fully dependant on the input message, with even small alterations to the data will result in a significantly different digest. This is known as in the avalanche effect.
An example of the avalanche effect can be seen with the messages "Hello, World!", and "Hello, World".

- The message "Hello, World!" will generate a SHA512 digest of "397118fdac8d83ad98813c50759c85b8c47565d8268bf10da483153b747a74743a58a90e85aa9f705ce6984ffc128db567489817e4092d050d8a1cc596ddc119"
- The message "Hello, World" will generate a SHA512 digest of "45546d4d71407e82ecda31eba5bf74b65bc092b0436a2409a6b615c1f78fdb2d3da371758f07a65b5d2b3ee8fa9ea0c772dd1eff884c4c77d4290177b002ccdc"


A hash function must also be both collision and preimage resistant.
Collisions are an unavoidable flaw of hash functions which may be exploited, a collision is when two messages result in the same digest, and a collision attack is one which attempts to uncover these messages.
Collision resistance means that these collisions are difficult to find. 
The existance of collisions is proven by the pigeonhole principle, which states that if n items are put into m containers, with n > m, then at least one container must contain more than one item.  
Because the number of possible hash function inputs are larger than the number of possible hash function outputs, different message inputs will inevitably produce the same hash digest.
An attack which aims to find a message which will generate a specific hash value is known as a preimage attack, and hash functions are considered to be preimage resistant.
Cryptographic hash algorithms depend on the infeasibility of such attacks. The fastest way to compute a preimage attack on a hash digest is by brute-force, which has a quadratic time complexity.






__The SHA512 algorithm__  
There are several steps to the SHA512 algorithm.  
Pre-processing  
- The input message is broken into blocks of 1024-bit length.
- Not all input messages will fit perfectly into these 1024 blocks, those which do not are padded.
- Messages are padded by appending a bit "1", followed by "0"s, with the final 128-bit block assigned the length of the message in bits.
- An initial hash value is created using 6 64-bit words, obtained by taking the first sixty-four bits of the fractional parts of the square roots of the first eight prime numbers.

Processing  
- Each message block is processed with a variety of bit shifting functions and the initial hash value is updated based on these calculations.
- Processing continues for 80 rounds, each round uses a different constant value in processing. The output of the previous round is used to process the next.
- The resulting 512-bit message digest after N iterations is the final output.


SHA512 is important because unlike its predecessors, it is still considered secure and while this status may change with technological advancements, SHA512 is likely to be deployed for the foreseeable future.[4] 



#### Why can't we reverse the SHA512 algorithm to retrieve the original message from a hash digest

SHA512 is a one-way hash function and preimage resistance is a required characteristic of a secure hash algorithm, as outlined by NIST's secure hash standard.
In cryptography, a preimage attack on cryptographic hash functions tries to find a message that has a specific hash value. 

What this means is that, given H it should be hard to find M such that H = hash(M).
Preimage attacks on SHA512 are computationally infeasible because the fastest way to compute a preimage attack is by brute-force.



It has a fixed output of 512 bits while the input can be significantly larger than this.
Essentially what this means is that hash functions adhere to the pigeonhole principle which describes why we would not be able to ascertain that a SHA512 message corresponds with a specific hash digest.



#### Can you design an algorithm that, given enough time, will find input messages that give each of the possible 512-bit strings

This question is again describing a primage attack, preimage attacks on SHA512 are computationally infeasible.
However, the answer to this question is yes. Given enough time and processing power, it would be possible to find a desired input messages which corresponds to a given hash digest.
This is a less difficult task than the previous one because we are simply seeking a desired hash output and not attempting to verify that a hash output was produced by a given message, 
Finding a input messages which will produce each of the possible 512-bit strings would be possible but time and processing constraints which make such algorithms impracticable. 
Its worth noting that there are 2^512 string which would need to be discovered. This gives the algorithm a quadratic space complexity as the information on all 2^512 strings would need to be stored and frequently searched against.



As advancements in hardware are developed practical attacks which may not have been possible, will become possible. [5]
And while we can expect SHA-2 to similarly breakdown with further increases in hardware, this task has an overwhelming space and time complexity.


#### How difficult is it to find a hash digest beginning with at least twelve zeros

Again, this is a question on the feasibility of a preimage attack on SHA512.
This task does not seem quite as troublesome as the previous task, which has enormous space and time complexity problems. Yet, like any preimage attack on a hash function, it is not computationally feasible because SHA512 is preimage resistant. 
Seeking a hash digest which begins with at least twelve zeros is no easier than finding any other pattern as SHA512 hash digests are uniformly random.
The trouble is that there is no discernible pattern to the hash digest, each byte of the input message will alter the digest drastically. The only means to achieve this is by brute force, and the probability of finding THE desired hash digest is extremely low.

What is the probability that the first bits are a number? 	(10/64)*(10/64) = 0.024
What is the probability that the first bits are 0? 			(1/64)*(1/64) = 0.00024





### Resources
Hashing algorithms
- https://www.iusmentis.com/technology/hashfunctions/
- https://www.youtube.com/watch?v=b4b8ktEV4Bg
- https://www.investopedia.com/news/cryptographic-hash-functions/
- https://www.synopsys.com/blogs/software-security/cryptographic-hash-functions/
- https://www.tutorialspoint.com/cryptography/cryptography_hash_functions.htm

SHA512
- https://www.nist.gov/publications/secure-hash-standard-shs?pub_id=910977
- https://medium.com/@zaid960928/cryptography-explaining-sha-512-ad896365a0c1
- https://en.wikipedia.org/wiki/SHA-2
- https://eprint.iacr.org/2016/374.pdf
- https://en.wikipedia.org/wiki/Avalanche_effect

Pigeonhole principle
- https://blog.codinghorror.com/hashtables-pigeonholes-and-birthdays/
- https://steemit.com/technology/@jiansoo/the-pigeonhole-principle-how-do-pigeons-and-pigeonholes-relate-to-cryptographic-hashing-functions-and-the-number-of-hairs-on

Attacks
- https://en.wikipedia.org/wiki/Collision_(computer_science)
- https://en.wikipedia.org/wiki/Preimage_attack
- https://eprint.iacr.org/2009/479.pdf
- https://eprint.iacr.org/2012/440.pdf


Message Digest
- https://www.sciencedirect.com/topics/computer-science/message-digest


### References
[1] Message digests and digital signatures, https://www.ibm.com/support/knowledgecenter/en/SSFKSJ_7.5.0/com.ibm.mq.sec.doc/q009810_.htm  
[2] Secure Hash Standard, https://www.nist.gov/publications/secure-hash-standard-shs?pub_id=910977  
[3] Hash Functions, https://www.sparknotes.com/cs/searching/hashtables/section2/  
[4] Analysis of SHA-512/224 and SHA-512/256, https://eprint.iacr.org/2016/374.pdf
[5] SHA-1 is a Shambles, https://eprint.iacr.org/2020/014.pdf
