#include "alloc_char.h"
#include <stdlib.h>
#include <stdio.h>

char* Alloc_charArray(int numElems) {
	char* array = malloc(numElems * sizeof(char));
	return array;
}

void Init_charArray(char* array, int numElems, char value) {
	for (int i = 0; i < numElems; i++) {
		array[i] = value;
	}
}

void Disp_charArray(char* array, int numElems) {
	for (int i = 0; i < numElems; i++) {
		printf("array[%d] = %c\n", i, array[i]);
	}
}
