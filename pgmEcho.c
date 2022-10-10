/****************************************/
/* COMP 1921 Programming Project        */
/* 2021-22 Spring Semester              */
/*                                      */
/* Name of Student: Vindhyaa Saravanan  */
/* Email: sc21vs@leeds.ac.uk            */
/* Student ID: 201542641                */
/****************************************/

/***********************************/
/* MODULAR PGMECHO.C               */
/* Main routine that produces      */
/* an identical copy of inputfile  */
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
    printf("Usage: ./pgmEcho inputImage.pgm outputImage.pgm\n");
    return 0;
  }

  // If wrong number of arguments given
  else if (argc != 3 && argc != 1)
  {
    // Print error message and return appropriate error code
    printf("ERROR: Bad Argument Count\n");
    return EXIT_WRONG_ARG_COUNT;
  }


  // OPENING INPUTFILE
  FILE *inputFile = fopen(argv[1], "r");

  // If file not available or not opened correctly
  if (inputFile == NULL)
  {
    // Print error message and return appropriate error code
    printf("ERROR: Bad File Name (%s)\n", argv[1]);
    return EXIT_BAD_FILE_NAME;
  }


  // READING INPUTFILE INTO PGM STRUCT
  // Set struct and PGMpointer to struct
  struct PGMFile pgmFile;
  struct PGMFile *PGMpointer = &pgmFile;
  char* filename = argv[1];

  // Read input file into PGMFile struct
  initializePGMFile(PGMpointer);
  getMagicNumber(PGMpointer, inputFile, filename);
  getComment(PGMpointer, inputFile, filename);
  getHeader(PGMpointer, inputFile, filename);

  // Read data acc to inputfile being ascii or binary
  unsigned short *magic_Number = (unsigned short *) PGMpointer->magic_number;
  if (*magic_Number == MAGIC_NUMBER_ASCII_PGM)
  {
    imageReadASCII_2D(PGMpointer, inputFile, filename);
  }
  else if (*magic_Number == MAGIC_NUMBER_RAW_PGM)
  {
    imageReadBinary_2D(PGMpointer, inputFile, filename);
  }


  // OPENING OUTPUTFILE
  FILE *outputFile = fopen(argv[2], "w");

  // If file not opened correctly
  if (outputFile == NULL)
  {
    // Free memory
    for (int rowToFree = PGMpointer->height - 1; rowToFree >= 0; rowToFree--)
    {
      free(PGMpointer->imageDataArray[rowToFree]);
    }
    free(PGMpointer->imageDataArray);


    // Print error message and return appropriate error code
    printf("ERROR: Output Failed (%s)\n", argv[2]);
    return EXIT_OUTPUT_FAILED;
  }


  // WRITING TO OUTPUT
  char *outputFilename = argv[2];

  // Write to file in appropriate format
  if (*magic_Number == MAGIC_NUMBER_ASCII_PGM)
  {
    imageWriteDimensionsASCII(PGMpointer, outputFile, outputFilename);
    imageWriteASCIIData_2D(PGMpointer, outputFile, outputFilename);
  }
  else if (*magic_Number == MAGIC_NUMBER_RAW_PGM)
  {
    imageWriteDimensionsBinary(PGMpointer, outputFile, outputFilename);
    imageWriteBinaryData_2D(PGMpointer, outputFile, outputFilename);
  }

  // SUCCESS OUTPUTS
  printf("ECHOED\n");
  return EXIT_NO_ERRORS;
}
