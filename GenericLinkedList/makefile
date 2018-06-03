a.out : Gadt.o main.o
	gcc Gadt.o main.o

main.o : main.c Gadt.h
	gcc -c main.c

Gadt.o : Gadt.c Gadt.h
	gcc -c Gadt.c
