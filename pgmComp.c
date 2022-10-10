/****************************************/
/* COMP 1921 Programming Project        */
/* 2021-22 Spring Semester              */
/*                                      */
/* Name of Student: Vindhyaa Saravanan  */
/* Email: sc21vs@leeds.ac.uk            */
/* Student ID: 201542641                */
/****************************************/

/***********************************/
/* PGMCOMP.C                       */
/* Main routine that compares      */
/* two pgm files for               */
/* logical equivalence             */
/***********************************/

//Importing standard modules
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

// Import user-defined modules
#include "pgmDef.h"
#include "pgmInput.h"
#include "pgmOutput.h"

// MAIN FUNCTION
int main(int argc, char **argv) {

  // ARGUMENT CHECKS
  // If no arguments given
  if (argc == 1)
  {
    // Print error message and return appropriate error code
    printf("Usage: ./pgmComp inputImage.pgm inputImage.pgm\n");
    return 0;
  }

  // If wrong number of arguments given
  else if (argc != 3 && argc != 1)
  {
    // Print error message and return appropriate error code
    printf("ERROR: Bad Argument Count\n");
    return EXIT_WRONG_ARG_COUNT;
  }


  // OPENING FIRST INPUTFILE
  FILE *inputFile1 = fopen(argv[1], "r");

  // If file not available or not opened correctly
  if (inputFile1 == NULL)
  {
    // Print error message and return appropriate error code
    printf("ERROR: Bad File Name (%s)\n", argv[1]);
    return EXIT_BAD_FILE_NAME;
  }

  // Set struct and PGMpointer to struct
  struct PGMFile pgmFile1;
  struct PGMFile *PGMpointer1 = &pgmFile1;
  char* filename1 = argv[1];

  // READING FIRST INPUTFILE
  initializePGMFile(PGMpointer1);
  getMagicNumber(PGMpointer1, inputFile1, filename1);
  getComment(PGMpointer1, inputFile1, filename1);
  getHeader(PGMpointer1, inputFile1, filename1);

  // Read data acc to inputfile being ascii or binary
  unsigned short *magic_Number1 = (unsigned short *) PGMpointer1->magic_number;
  if (*magic_Number1 == MAGIC_NUMBER_ASCII_PGM)
  {
    imageReadASCII_2D(PGMpointer1, inputFile1, filename1);
  }
  else if (*magic_Number1 == MAGIC_NUMBER_RAW_PGM)
  {
    imageReadBinary_2D(PGMpointer1, inputFile1, filename1);
  }


  // OPENING SECOND INPUTFILE
  FILE *inputFile2 = fopen(argv[2], "r");

  // If file not available or not opened correctly
  if (inputFile2 == NULL)
  {
    // Free memory
    for (int rowToFree = PGMpointer1->height - 1; rowToFree >= 0; rowToFree--)
    {
      free(PGMpointer1->imageDataArray[rowToFree]);
    }
    free(PGMpointer1->imageDataArray);

    // Print error message and return appropriate error code
    printf("ERROR: Bad File Name (%s)\n", argv[2]);
    return EXIT_BAD_FILE_NAME;
  }

  // Set struct and PGMpointer to struct
  struct PGMFile pgmFile2;
  struct PGMFile *PGMpointer2 = &pgmFile2;
  char* filename2 = argv[2];

  // READING SECOND INPUT FILE
  initializePGMFile(PGMpointer2);
  getMagicNumber(PGMpointer2, inputFile2, filename2);
  getComment(PGMpointer2, inputFile2, filename2);
  getHeader(PGMpointer2, inputFile2, filename2);

  // Read data acc to inputfile being ascii or binary
  unsigned short *magic_Number2 = (unsigned short *) PGMpointer2->magic_number;
  if (*magic_Number2 == MAGIC_NUMBER_ASCII_PGM)
  {
    imageReadASCII_2D(PGMpointer2, inputFile2, filename2);
  }
  else if (*magic_Number2 == MAGIC_NUMBER_RAW_PGM)
  {
    imageReadBinary_2D(PGMpointer2, inputFile2, filename2);
  }


  // Compare the two images for logical equivalence
  // The function will exit program if images are different
  imageCompare(PGMpointer1, PGMpointer2);


  // SUCCESS OUTPUTS when images are identical
  printf("IDENTICAL\n");
  return EXIT_NO_ERRORS;
}
