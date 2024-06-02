a.out				: main.o alloc_double.o alloc_char.o alloc_int.o 
					gcc main.o alloc_double.o alloc_char.o alloc_int.o

main.o				: main.c alloc_array.h
					gcc -c main.c

alloc_double.o 		: alloc_double.h alloc_double.c
					gcc -c alloc_double.c

alloc_int.o			: alloc_int.h alloc_int.c
					gcc -c alloc_int.c

alloc_char.o		: alloc_char.h alloc_char.c
					gcc -c alloc_char.c

clean				:
					rm -f *.o a.out					
