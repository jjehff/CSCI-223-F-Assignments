#include "alloc_int.h"
#include <stdlib.h>
#include <stdio.h>

int* Alloc_intArray(int numElems) {
	auto int* array = malloc(numElems * sizeof(int));
	return array;
}

void Init_intArray(int* array, int numElems, int value) {
	for (int i = 0; i < numElems; i++) {
		array[i] = value;
	}
}

void Disp_intArray(int* array, int numElems) {
	for (int i = 0; i < numElems; i++) {
 		printf("array[%d] = %d\n", i, array[i]);
	}
}
