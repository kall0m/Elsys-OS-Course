//------------------------------------------------------------------------
// NAME: Kaloyan Madjunov
// CLASS: XIb
// NUMBER: 12
// PROBLEM: #3
// FILE NAME: swap.c
// FILE PURPOSE:
// A program in C which swaps the values of two integers using pointers.
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// FUNCTION: swap
// The function swaps the values of two integers.
// PARAMETERS:
// int *a, int *b - two pointers of type int
//------------------------------------------------------------------------

#include <stdio.h>

void swap(int *a, int *b) {
	int c = *a; //the value of the variable 'c' is now equal to the value of the variable located at the address available in pointer 'a'

	*a = *b; //the value of the variable located at the address available in pointer 'a' is now equal to the value of the variable located at the address available in pointer 'b'

	*b = c; //the value of the variable located at the address available in pointer 'b' is now equal to the value of the variable 'c'
}
