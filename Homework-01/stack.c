//------------------------------------------------------------------------
// NAME: Kaloyan Madjunov
// CLASS: XIb
// NUMBER: 12
// PROBLEM: #6
// FILE NAME: stack.c
// FILE PURPOSE:
// A program in C which initializes a stack and its basic functions.
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// FUNCTION: stack_init
// The function initializes an empty stack.
// PARAMETERS:
// stack *st - A stack which is passed by reference.

// FUNCTION: stack_destroy
// The function destroys a created stack.
// PARAMETERS:
// stack *st - A stack which is passed by reference.

// FUNCTION: stack_empty
// The function tells if a stack is empty.
// PARAMETERS:
// stack *st - A stack which is passed by reference.

// FUNCTION: stack_push
// The function adds an element of type int in the stack.
// PARAMETERS:
// stack *st - A stack which is passed by reference.
// int val - A variable of type int

// FUNCTION: stack_top
// The function returns the last pushed element in the stack.
// PARAMETERS:
// stack *st - A stack which is passed by reference.

// FUNCTION: stack_pop
// The function removes the last pushed element in the stack.
// PARAMETERS:
// stack *st - A stack which is passed by reference.
//------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    size_t size;
    size_t capacity;
    int *elements;
} stack;

void stack_pop( stack *st ) {
	if(stack_empty(st)) {
		return;
	}

	st->size--;
}

int stack_top( stack *st ) {
	return st->elements[st->size - 1];
}

void stack_push( stack *st, int val) {
	if(st->size == st->capacity) {
		st->capacity *= 2;
		st->elements = realloc(st->elements, st->capacity * sizeof(int));
	}

	st->elements[st->size++] = val;
}

int stack_empty( stack *st ) {
	return st->size == 0;
}

void stack_destroy( stack *st ) {
	st->capacity = 0;
	st->size = 0;
	free(st->elements);
	st->elements = NULL;
}

void stack_init( stack *st ) {
	st->capacity = 10;
	st->size = 0;
	st->elements = malloc(10 * sizeof(int));
}
