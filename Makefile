#File: Makefile
#Author:Junxiang Liu

#Make file for assignment 8

# Compiler Version
CC=g++

# Debugging flag -g
DEBUG=-g

# Target
TARGET=r

# Compile with all errors and warnings
CFLAGS=-c -Wall $(DEBUG)

all: $(TARGET)

$(TARGET): driver.o binary_search_tree.o
	$(CC) driver.o  binary_search_tree.o -o $(TARGET)

main.o: driver.cpp  binary_search_tree.h
	$(CC) $(CFLAGS) driver.cpp

inventory.o:  binary_search_tree.cpp  binary_search_tree.h
	$(CC) $(CFLAGS)  binary_search_tree.cpp

clean:
	rm *.o *~ $(TARGET)



