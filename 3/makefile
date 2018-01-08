a.out : calculate.o PigLatin.o ex4.o
	gcc calculate.o PigLatin.o ex4.o

ex4.o : ex4.c calculate.h PigLatin.h
	gcc -c ex4.c

calculate.o : calculate.c calculate.h
	gcc -c calculate.c

PigLatin.o : PigLatin.c PigLatin.h
	gcc -c PigLatin.c