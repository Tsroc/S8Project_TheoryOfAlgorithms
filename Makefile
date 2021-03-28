# Useage:
# # make		# compile all binary
# # make clean		# remove all vinaries and objects

CC = gcc

final: 
	$(CC) main.c sha512.c funcs.c -o main



clean:
	rm *.o main test
