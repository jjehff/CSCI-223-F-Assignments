#include "alloc_double.h"
#include <stdlib.h>
#include <stdio.h>

double* Alloc_doubleArray(int numElems) {
	auto double* array = malloc(numElems * sizeof(double));
	return array;
}

void Init_doubleArray(double* array, int numElems, double value) {
	for (int i = 0; i < numElems; i++) {
		array[i] = value;
	}
}

void Disp_doubleArray(double* array, int numElems) {
	for (int i = 0; i < numElems; i++) {
		printf("array[%d] = %f\n", i, array[i]);
	}
}
