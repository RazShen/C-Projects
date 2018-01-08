a.out : SmallestStr.o GetString.o ChangeSen.o FindRepeat.o SortNames.o LinkedList.o main.o
	gcc SmallestStr.o GetString.o ChangeSen.o FindRepeat.o SortNames.o LinkedList.o main.o

main.o : main.c GetString.h FindRepeat.h ChangeSen.h SmallestStr.h
	gcc -c main.c

FindRepeat.o : FindRepeat.c FindRepeat.h
	gcc -c FindRepeat.c

GetString.o : GetString.c GetString.h
	gcc -c GetString.c

SmallestStr.o : SmallestStr.c FindRepeat.h SmallestStr.h
	gcc -c SmallestStr.c

ChangeSen.o : ChangeSen.c ChangeSen.h
	gcc -c ChangeSen.c

SortNames.o : SortNames.c SortNames.h
	gcc -c SortNames.c

LinkedList.o : LinkedList.c LinkedList.h
	gcc -c LinkedList.c