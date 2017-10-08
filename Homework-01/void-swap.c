//------------------------------------------------------------------------
// NAME: Kaloyan Madjunov
// CLASS: XIb
// NUMBER: 12
// PROBLEM: #4
// FILE NAME: void-swap.c
// FILE PURPOSE:
// A program in C which swaps the values of two arguments of the same type using pointers.
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// FUNCTION: swap
// The function swaps the values of two arguments.
// PARAMETERS:
// void *a, void *b, size_t size - two pointers of void type (void indicates the absence of type) and a variable which is the size of the type we want the arguments 'a' and 'b' to be
//------------------------------------------------------------------------

#include <stdio.h>

void swap(void *a, void *b, size_t size) {
	char *a_mem = a;
	char *b_mem = b;
	char c;

	for(size_t i = 0; i < size; i++) {
		c = a_mem[i];
		a_mem[i] = b_mem[i];
		b_mem[i] = c;
	}
}
