//------------------------------------------------------------------------
// NAME: Kaloyan Madjunov
// CLASS: XIb
// NUMBER: 12
// PROBLEM: #5
// FILE NAME: strdup.c
// FILE PURPOSE:
// A program in C which makes a copy of a string and returns a pointer of the place in the memory it is.
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// FUNCTION: strdup
// The function makes a copy of a string.
// PARAMETERS:
// const char *s - a sequence of characters (string)
//------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strdup( const char *s ) {
	int len = strlen(s);

	char *s_mem = malloc(len * sizeof(char));

	int i = 0;

	for(; s[i] != '\0'; i++) {
		s_mem[i] = s[i];
	}

	s_mem[i] = '\0';

	return s_mem;
}
