/****************************************/
/* COMP 1921 Programming Project        */
/* 2021-22 Spring Semester              */
/*                                      */
/* Name of Student: Vindhyaa Saravanan  */
/* Email: sc21vs@leeds.ac.uk            */
/* Student ID: 201542641                */
/****************************************/

/***********************************/
/* PGMREDUCE.C                     */
/* Main routine that reduces       */
/* a pgm file                      */
/***********************************/

//Importing standard modules
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

// Importing user-defined modules
#include "pgmDef.h"
#include "pgmInput.h"
#include "pgmOutput.h"


/*
* MAIN FUNCTION
*/
int main(int argc, char **argv) {

  // ARGUMENT CHECKS
  // If no arguments given
  if (argc == 1)
  {
    // Print error message and return appropriate error code
    printf("Usage: ./pgmReduce inputImage.pgm reduction_factor outputImage.pgm\n");
    return 0;
  }

  // If wrong number of arguments given
  else if (argc != 4 && argc != 1)
  {
    // Print error message and return appropriate error code
    printf("ERROR: Bad Argument Count\n");
    return EXIT_WRONG_ARG_COUNT;
  }


  // VALIDATING REDUCTION FACTOR
  // Convert given reduction factor number string to int
  int reductionFactor = atoi(argv[2]);

  // If negative number is entered
  if (reductionFactor < 0)
  {
    // Print error message and return appropriate error code
    printf("ERROR: Miscellaneous (Negative Scaling Factor)\n");
    return EXIT_MISC;
  }

  // If entered argument is not a number
  if (reductionFactor == 0)
  {
    // Print error message and return appropriate error code
    printf("ERROR: Miscellaneous (Non-Numeric Scaling Factor)\n");
    return EXIT_MISC;
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


  // Define struct for input PGM file
  struct PGMFile pgmFile1;
  struct PGMFile *PGMpointer1 = &pgmFile1;
  char* filename1 = argv[1];

  // Read the first file
  initializePGMFile(PGMpointer1);
  getMagicNumber(PGMpointer1, inputFile, filename1);
  getComment(PGMpointer1, inputFile, filename1);
  getHeader(PGMpointer1, inputFile, filename1);

  // Read image pixel data
  unsigned short *magic_Number = (unsigned short *) PGMpointer1->magic_number;
  if (*magic_Number == MAGIC_NUMBER_ASCII_PGM)
  {
    imageReadASCII_2D(PGMpointer1, inputFile, filename1);
  }
  else if (*magic_Number == MAGIC_NUMBER_RAW_PGM)
  {
    imageReadBinary_2D(PGMpointer1, inputFile, filename1);
  }


  // Check valid and divisible reduction factor
  if (PGMpointer1->height % reductionFactor != 0 ||
      PGMpointer1->width % reductionFactor != 0)
  {
    // Print error message and return appropriate error code
    printf("ERROR: Miscellaneous (Non-Divisible Scaling Factor)\n");
    return EXIT_MISC;
  }


  // Open a file for writing
  FILE *outputFile = fopen(argv[3], "w+");

  // Check whether file opening worked
  if (outputFile == NULL)
  {
    // Free memory
    for (int rowToFree = PGMpointer1->height - 1; rowToFree >= 0; rowToFree--)
    {
      free(PGMpointer1->imageDataArray[rowToFree]);
    }
    free(PGMpointer1->imageDataArray);

    // Print error message and return appropriate error code
    printf("ERROR: Output Failed (%s)\n", argv[3]);
    return EXIT_OUTPUT_FAILED;
  }


  // Define struct for outputfile
  struct PGMFile pgmFile2;
  struct PGMFile *PGMpointer2 = &pgmFile2;
  char *outputFilename = argv[3];

  // Reduce input struct and write to output struct
  imageReduce(PGMpointer1, PGMpointer2, reductionFactor, inputFile);

  // Write contents of output struct into outputfile
  if (*magic_Number == MAGIC_NUMBER_ASCII_PGM)
  {
    imageWriteDimensionsASCII(PGMpointer2, outputFile, outputFilename);
    imageWriteASCIIData_2D(PGMpointer2, outputFile, outputFilename);
  }
  else if (*magic_Number == MAGIC_NUMBER_RAW_PGM)
  {
    imageWriteDimensionsBinary(PGMpointer2, outputFile, outputFilename);
    imageWriteBinaryData_2D(PGMpointer2, outputFile, outputFilename);
  }

  // SUCCESS OUTPUTS
  printf("REDUCED\n");
  return EXIT_NO_ERRORS;
}
