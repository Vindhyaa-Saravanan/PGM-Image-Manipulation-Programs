/****************************************/
/* COMP 1921 Programming Project        */
/* 2021-22 Spring Semester              */
/*                                      */
/* Name of Student: Vindhyaa Saravanan  */
/* Email: sc21vs@leeds.ac.uk            */
/* Student ID: 201542641                */
/****************************************/

/***********************************/
/* pgmDef.c                        */
/* Module that defines struct      */
/* PGMFile for use in code         */
/* also function for init          */
/***********************************/

//Importing standard modules
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

// DEFINING FIXED CONSTANTS
#define EXIT_NO_ERRORS 0
#define EXIT_WRONG_ARG_COUNT 1
#define EXIT_BAD_FILE_NAME 2
#define EXIT_BAD_MAGIC_NUMBER 3
#define EXIT_BAD_COMMENT_LINE 4
#define EXIT_BAD_DIMENSIONS 5
#define EXIT_BAD_MAX_GRAY 6
#define EXIT_IMAGE_MALLOC_FAILED 7
#define EXIT_BAD_DATA 8
#define EXIT_OUTPUT_FAILED 9
#define EXIT_BAD_LAYOUT 10
#define EXIT_MISC 100

#define MAGIC_NUMBER_RAW_PGM 0x3550
#define MAX_GRAY_VALUE 255
#define MIN_GRAY_VALUE 0
#define MAGIC_NUMBER_ASCII_PGM 0x3250
#define MIN_IMAGE_DIMENSION 1
#define MAX_IMAGE_DIMENSION 65536
#define MAX_COMMENT_LINE_LENGTH 130
#define BUFFER_SIZE 256


// DEFINING PGMFILE AS A STRUCT
struct PGMFile
{

  // The Magic Number
  // stored as two bytes
  // Raw:    0x5035 or P5
  // ASCII:  0x5032 or P2
  unsigned char magic_number[2];

  // To store one comment
  char *commentLine;

  // The logical width & height
  // Cannot be negative thus unsigned int
  unsigned int width, height;

  // maximum gray value (assumed)
  unsigned int maxGray;

  // PGMpointer to raw image data
  unsigned char *imageData;
  unsigned char **imageDataArray;

};


/*
* FUNCTION TO INITIALIZE PGMFILE
* Takes in a PGMfile struct PGMpointer as parameter
* Sets values of parts of struct to standard initialized values
*/
void initializePGMFile(struct PGMFile *PGMpointer)
{
  PGMpointer->magic_number[0] = 0;
  PGMpointer->magic_number[1] = 0;
  PGMpointer->commentLine = NULL;
  PGMpointer->width = 0,
  PGMpointer->height = 0;
  PGMpointer->maxGray = 255;
}
