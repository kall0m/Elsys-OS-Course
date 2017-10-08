#include <stdio.h>
#include <string.h>

char* strcat( char* destination, const char* source );

int main() {
	char *result = strcat("omg", "asd");

	//printf("%s\n", result);
	
	return 0;
}

char* strcat( char* destination, const char* source ) {
	int len = strlen(destination);
	int len2 = strlen(source);

	for(int i = 0; i < len; i++) {
		printf("%p -> %c, ", &destination[i], destination[i]);
	}

	printf("\n");

	for(int i = 0; i < len2; i++) {
		printf("%p -> %c, ", &source[i], source[i]);
	}

	char *tmp = &destination[len];

	destination[len] = source[0];

	printf("\n");

	for(int i = 0; i < len2; i++) {
		printf("%p -> %c, ", &source[i], source[i]);
	}

	//int len2 = strlen(source);

	//destination[len + len2] = '\0';

	return destination;
}
