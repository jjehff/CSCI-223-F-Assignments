// ============================================================================
// File: qsortints.c (Spring 2024)
// ============================================================================
// Write a program that lets the user allocate a dynamic array of ints and 
// populate it with unsorted values. Then use the qsort function to sort the
// array in ascending, then descending order.
// ============================================================================

#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <time.h>

// defined constants
#define TRUE              1
#define FALSE             0
#define ASC_FNAME         "ascending.txt"
#define DESC_FNAME        "descending.txt"
#define UNSORTED_FNAME    "unsorted.txt"

// function prototypes
int*    AllocInts(int  numInts);
int     SortDown(const void* vptr1, const void* vptr2);
int     SortUp(const void* vptr1, const void* vptr2);
int     WriteInts(const char  *fname, const int  array[], int  numElems);


// ==== main ==================================================================
// 
// ============================================================================

int     main(void)
{
    auto    int         *arrayPtr;
    auto    int         numElems;
	printf("How many ints do you want? ");
	scanf("%d", &numElems);

	arrayPtr = AllocInts(numElems);
	if (arrayPtr == NULL) {
		printf("error\n");
		return 0;
	}

	WriteInts("unsorted.txt", arrayPtr, numElems);
	printf("Random ints saved to unsorted.txt...\n");
    qsort(arrayPtr, numElems, sizeof(int), SortUp);
    WriteInts("ascending.txt", arrayPtr, numElems);
	printf("Random ints saved to ascending.txt...\n");
    qsort(arrayPtr, numElems, sizeof(int), SortDown);
    WriteInts("descending.txt", arrayPtr, numElems);
    printf("Random ints saved to descending.txt...\n");

    free(arrayPtr);
	
	
    // ask the user how many ints they want

    // allocate an array of ints and fill it with random values

    // write the unsorted array to an output file

    // sort the array in ascending order and write it to a file
    
    // sort the array in descending order and write it to a file

    // release the array

    return 0;

}  // end of "main"



// ==== AllocInts =============================================================
// 
// This function uses the formal parameter to allocate an array of ints from the 
// heap and fill it up with random integer values.
// 
// Input:
//      numInts [IN]        -- the number of elements to allocate for the array
// 
// Output:
//      The base address of the populated array, or NULL if an error occurs.
// 
// ============================================================================

int*    AllocInts(int  numInts)
{
	int* arrayPtr = malloc(numInts * sizeof(int));
	if (arrayPtr == NULL) {
		return NULL; // Allocation failed
	}

	for (int i = 0; i < numInts; i++) {
		arrayPtr[i] = rand();
	}
 	return arrayPtr;
       

}  // end of "AllocInts"



// ==== SortDown ==============================================================
// 
// This is the comparison function for qsort so that the array can be sorted
// in descending order.
// 
// Input:
//      vptr1 [IN]          -- a void pointer containing the address of a single
//                             array element
// 
//      vptr2 [IN]          -- a void pointer containing the address of a single
//                             array element
// 
// Output:
//      A negative value if the first parameter is greater than the second
//      parameter, or a positive value if the first parameter is less than
//      the second parameter, or a value of zero if the parameters are equal.
// 
// ============================================================================

int     SortDown(const void* vptr1, const void* vptr2)
{
	auto const int *int1 = vptr1;
	auto const int *int2 = vptr2;
	if (*int1 == *int2) {
		return 0;
	}
	else if (*int1 > *int2) {
		return -1;
    }
    else {
		return 1; 
	}
}  // end of "SortUp"



// ==== SortUp ================================================================
// 
// This is the comparison function for qsort so that the array can be sorted
// in ascending order.
// 
// Input:
//      vptr1 [IN]          -- a void pointer containing the address of a single
//                             array element
// 
//      vptr2 [IN]          -- a void pointer containing the address of a single
//                             array element
// 
// Output:
//      A negative value if the first parameter is less than the second
//      parameter, or a positive value if the first parameter is greater than
//      the second parameter, or a value of zero if the parameters are equal.
// 
// ============================================================================

int     SortUp(const void* vptr1, const void* vptr2)
{
    auto const int *int1 = vptr1;
    auto const int *int2 = vptr2;
    if (*int1 == *int2) {
    	return 0;
    }
    else if (*int1 < *int2) {
    	return -1;
    }
    else {
    	return 1;
    }

}  // end of "SortUp"



// ==== WriteInts =============================================================
// 
// This function writes the contents of the caller's array to an output file.
// 
// Input:
//      fname [IN]          -- the name of the output file to open
// 
//      array [IN]          -- the base address of the integer array to write
//                             to the output file
// 
//      numElems [IN]       -- the number of elements in the array
// 
// Output:
//      A value of TRUE if everything goes okay, FALSE otherwise.
//      
// ============================================================================

int     WriteInts(const char  *fname, const int  array[], int  numElems)
{
    FILE *outFile = fopen(fname, "w");
    if (outFile == NULL) {
    	printf("Error\n");
    	return 0;
    }
    for (int i = 0; i < numElems; i++) {
    	fprintf(outFile, "%d\n", array[i]);
    }
}  // end of "WriteInts"
