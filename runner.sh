#!/bin/bash

CC=gcc
EXEC=bit-operations
SRC=bit-operations.c


echo -e "\nRebuilding $EXEC..."
make $EXEC 
echo -e "\nRunning $SRC..."
./$EXEC
