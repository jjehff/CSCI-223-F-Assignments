// ============================================================================
// File: alloc_array.h (Spring 2024)
// ============================================================================

#ifndef ALLOC_ARRAY_H
#define ALLOC_ARRAY_H

// #include files
#include    "alloc_int.h"
#include    "alloc_char.h"
#include    "alloc_double.h"

// macros (use token-pasting operator to map function calls here...)
#define AllocArray(type, numElems) Alloc_##type##Array(numElems)
#define InitArray(type, arr, numElems, initVal) Init_##type##Array(arr, numElems, initVal)
#define DispArray(type, arr, numElems) Disp_##type##Array(arr, numElems)

#endif  // ALLOC_ARRAY_H
