# Useage:
# # make		# compile all binary
# # make clean		# remove all vinaries and objects

CC = gcc

sha512Test := $(shell sha512sum main.c | cut -d " " -f 1)

final: 
	$(CC) main.c sha512.c funcs.c -o main

test:
	@$(CC) test.c -o testSha512 
	@./testSha512 "$(shell ./main -o main.c)" "$(sha512Test)"

clean:
	rm *.o main testSha512 output.txt

