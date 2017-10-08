//------------------------------------------------------------------------
// NAME: Kaloyan Madjunov
// CLASS: XIb
// NUMBER: 12
// PROBLEM: #2
// FILE NAME: png-info.c
// FILE PURPOSE:
// A program in C which reads a png file and prints the height, width and size of the image file.
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// FUNCTION: read_image
// The function reads an image file. (This function was given by the teachers.)
// PARAMETERS:
// const char *path - a sequence of characters (string)
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// FUNCTION: main
// The function takes the name of a png file from the command line as a string, checks if the file exists or is it with the right format and then finds the height, width and size of the image file and prints them.
// PARAMETERS:
// int argc - the count of the arguments on the command line
// char *argv[] - a sequence of arguments as text separated by space on the command line
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// FUNCTION: strncmp
// The function compares the first n bytes of two strings. Can be found in the lib <string.h>.
// PARAMETERS:
// string1
// string2
// int n - number of characters to be compared
//------------------------------------------------------------------------

#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <string.h>

void *read_image(char *path);

int main(int argc, char *argv[]) {
  uint8_t *img = read_image(argv[1]);

  if(img == NULL) {
    printf("Unable to open file\n");

    return -1;
  }

  int check_PNG = strncmp(img, "\x89\x50\x4E\x47\x0D\x0A\x1A\x0A", 8); // check if the file is PNG (takes the first eight bytes and checks them)
  int check_IHDR = strncmp(img+12, "IHDR", 4); //takes the first four bytes, starting from the 12th byte (offset) of the file and checks them

  if(check_PNG != 0 || check_IHDR != 0) {
    printf("Unable to parse file\n");

    return -1;
  }

  uint32_t width = ntohl(*(uint32_t *)&img[16]); // on the 16th offset is the width
  uint32_t height = ntohl(*(uint32_t *)&img[20]); // on the 20th offset is the height

  printf("PNG image width: %d\n", width);
  printf("PNG image height: %d\n", height);

  uint32_t size = 8; // because after the first 8 bytes - "89 50 4E 47 0D 0A 1A 0A" begins the first chunk

  while(strncmp(img, "IEND", 4) != 0) { //a PNG file ends with IEND chunk (the loop starts from the beginning of the file - where the pointer 'img' points and iterates through the file to the end)
    img++; //move the pointer with 1 byte forward on every iteration of the loop
    size++;
  }

  printf("PNG file size: %d\n", size);

  return 0;
}
