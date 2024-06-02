a.out			: main.o add.o sub.o
				gcc main.o add.o sub.o

add.o	: add.c add.h
		gcc -c add.c

sub.o	: sub.c sub.h
		gcc -c sub.c

clean	:
		rm -f *.o a.out
