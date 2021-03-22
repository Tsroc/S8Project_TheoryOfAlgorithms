# Useage:
# # make		# compile all binary
# # make clean		# remove all vinaries and objects

CC = gcc

final: 
	$(CC) main.c sha512.c funcs.c -o main


test: test.o
	$(CC) test.c -o test
	./test

clean:
	rm *.o main test
