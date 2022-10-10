/****************************************/
/* COMP 1921 Programming Project        */
/* 2021-22 Spring Semester              */
/*                                      */
/* Name of Student: Vindhyaa Saravanan  */
/* Email: sc21vs@leeds.ac.uk            */
/* Student ID: 201542641                */
/****************************************/

/***********************************/
/* PGMA2B.C                        */
/* Main routine that produces      */
/* an binary copy of ASCII file    */
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
    printf("Usage: ./pgma2b inputImage.pgm outputImage.pgm\n");
    return 0;
  }

  // If wrong number of arguments given
  else if (argc != 3 && argc != 1)
  {
    // Print error message and return appropriate error code
    printf("ERROR: Bad Argument Count\n");
    return EXIT_WRONG_ARG_COUNT;
  }


  // CODE FOR OPENING INPUTFILE
  FILE *inputFile = fopen(argv[1], "r");

  // If file not available or not opened correctly
  if (inputFile == NULL)
  {
    // Print error message and return appropriate error code
    printf("ERROR: Bad File Name (%s)\n", argv[1]);
    return EXIT_BAD_FILE_NAME;
  }


  // Set name of file and make new struct for input pgm file
  struct PGMFile pgmFile;
  struct PGMFile *PGMpointer = &pgmFile;
  char* filename = argv[1];

  // Read input file into PGMFile struct
  initializePGMFile(PGMpointer);
  getMagicNumber(PGMpointer, inputFile, filename);

  // Reject inputfile if not ASCII
  unsigned short *magic_Number = (unsigned short *) PGMpointer->magic_number;
  if (*magic_Number != MAGIC_NUMBER_ASCII_PGM)
  {
    // Print error message and return appropriate error code
    printf("ERROR: Bad Magic Number (%s)\n", argv[1]);
    return EXIT_BAD_MAGIC_NUMBER;
  }

  // If file is in appropriate format, continue reading
  getComment(PGMpointer, inputFile, filename);
  getHeader(PGMpointer, inputFile, filename);
  imageReadASCII_2D(PGMpointer, inputFile, filename);


  // CODE FOR WRITING TO OUTPUT
  // Open a file for writing
  FILE *outputFile = fopen(argv[2], "wb");

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


  // Set output filename and write to file
  char *outputFilename = argv[2];
  imageWriteDimensionsBinary(PGMpointer, outputFile, outputFilename);
  imageWriteBinaryData_2D(PGMpointer, outputFile, outputFilename);

  // SUCCESS OUTPUTS
  printf("CONVERTED\n");
  return EXIT_NO_ERRORS;
}
