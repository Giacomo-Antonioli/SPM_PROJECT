# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -std=c++17 -Wall -g -pthread
 
# ****************************************************
# Targets needed to bring the executable up to date
 
main: main.o Graph.o Node.o Token.o Destination_Token.o MDFRepo.o MDFI.o
		$(CC) $(CFLAGS) -o main main.o Graph.o Node.o Token.o Destination_Token.o MDFI.o MDFRepo.o

# The main.o target can be written more simply

main.o: main.cpp Graph.h Node.h
		$(CC) $(CFLAGS) -c main.cpp

Node.o:  Node.cpp Node.h
		$(CC) $(CFLAGS) -c Node.cpp

Graph.o: Graph.cpp Graph.h  Node.h
		$(CC) $(CFLAGS) -c Graph.cpp

Token.o: Token.cpp  Token.h
		$(CC) $(CFLAGS) -c Token.cpp

Destination_Token.o: Destination_Token.cpp  Destination_Token.h
		$(CC) $(CFLAGS) -c Destination_Token.cpp

MDFI.o: MDFI.cpp  MDFI.h
		$(CC) $(CFLAGS) -c MDFI.cpp

MDFRepo.o: MDFRepo.cpp  MDFRepo.h
		$(CC) $(CFLAGS) -c MDFRepo.cpp


clean:
		$(RM) main main.o Graph.o Node.o MDFI.o MDFRepo.o Destination_Token.o