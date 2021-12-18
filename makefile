CC = gcc
FLAG = -Wall -g
.PHONY: all clean
all:Gen.o gimatria.o anag.o main.o at.o stringProg
Gen.o: Gen.c my_lib.h
	$(CC) $(FLAG) -c Gen.c
gimatria.o: gimatria.c my_lib.h
	$(CC) $(FLAG) -c gimatria.c
anag.o: anag.c my_lib.h
	$(CC) $(FLAG) -c anag.c
at.o: at.c my_lib.h
	$(CC) $(FLAG) -c at.c	
main.o: main.c my_lib.h
	$(CC) $(FLAG) -c main.c
stringProg: Gen.o gimatria.o anag.o main.o
	$(CC) $(FLAG) -o stringProg Gen.o gimatria.o anag.o main.o at.o
clean: 
	rm -f *.o *.out *.h.ghc stringProg