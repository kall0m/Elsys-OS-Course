//------------------------------------------------------------------------
// NAME: Kaloyan Madjunov
// CLASS: XIb
// NUMBER: 12
// PROBLEM: #1
// FILE NAME: bmp-info.c
// FILE PURPOSE:
// A program in C which reads a bmp file and prints the height and width of the image file.
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// FUNCTION: read_image
// The function reads an image file. (This function was given by the teachers.)
// PARAMETERS:
// const char *path - a sequence of characters (string)
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// FUNCTION: main
// The function takes the name of a bmp file from the command line as a string and then finds the 18th and the 22th byte which are the width and the height of the image file and prints them.
// PARAMETERS:
// int argc - the count of the arguments on the command line
// char *argv[] - a sequence of arguments as text separated by space on the command line
//------------------------------------------------------------------------

#include <stdio.h>
#include <stdint.h>

void *read_image(const char *path);

int main(int argc, char *argv[]) {
  uint8_t *img = read_image(argv[1]);

  uint16_t *w = (uint16_t *)&img[18]; //a pointer which points to the 18th byte where the width of the bmp image can be found
  uint16_t *h = (uint16_t *)&img[22]; //a pointer which points to the 22th byte where the height of the bmp image can be found

  printf("BMP image width: %d\n", *w); //prints the value of the pointer
  printf("BMP image height: %d\n", *h);

  return 0;
}
