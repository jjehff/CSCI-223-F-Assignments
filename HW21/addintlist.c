// ============================================================================
// File: addintlist.c (Spring 2024)
// ============================================================================
// This program is an exercise is writing a function that works with a variable
// length argument list. The "AddIntList" function allows the caller to pass 
// any number of integer values as arguments and returns their sum 
// a variable-length argument list. 
// ============================================================================
// Sample output:
//
//   AddIntList(3, 11, 22, 33) = 66
//   AddIntList(7, 11, 22, 33, 44, 55, 66, 77) = 308
//   AddIntList(1, 11) = 11
//
// ============================================================================

#include    <stdio.h>
#include    <stdlib.h>
#include    <stdarg.h>


// function prototypes
int     AddIntList(int numInts, ...);


// ==== main ==================================================================
// 
// ============================================================================

int     main(void)
{
    auto    int         sum;

    sum = AddIntList(3, 11, 22, 33);
    printf("AddIntList(3, 11, 22, 33) = %d\n", sum);

    sum = AddIntList(7, 11, 22, 33, 44, 55, 66, 77);
    printf("AddIntList(7, 11, 22, 33, 44, 55, 66, 77) = %d\n", sum);

    sum = AddIntList(1, 11);
    printf("AddIntList(1, 11) = %d\n", sum);

    return 0;

}  // end of "main"



// ==== AddIntList ============================================================
// 
// This function adds however many int values the caller passes as arguments to
// derive a sum total, which is then returned to the caller. The first argument
// is mandatory and contains the number of ints to add.
// 
// Input:
//    numInts [IN]      -- the number of ints to add (required)
// 
// Output:
//    The sum total of the int values that follow the first parameter.
// 
// ============================================================================

int     AddIntList(int numInts, ...)
{
    va_list arguments;
    va_start(arguments, numInts);
	auto int sum = 0;
    for (int i = 0; i < numInts; i++) {
    	auto int temp = va_arg(arguments, int);
    	sum += temp;
    }
    va_end(arguments);
    return sum;
}  // end of "AddIntList"
