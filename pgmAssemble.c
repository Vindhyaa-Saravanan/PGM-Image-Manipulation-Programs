/****************************************/
/* COMP 1921 Programming Project        */
/* 2021-22 Spring Semester              */
/*                                      */
/* Name of Student: Vindhyaa Saravanan  */
/* Email: sc21vs@leeds.ac.uk            */
/* Student ID: 201542641                */
/****************************************/

/***********************************/
/* PGMASSEMBLE.C                   */
/* Main routine that assembles     */
/* input tiles into one file       */
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
    printf("Usage: ./pgmAssemble outputImage.pgm width height (row column inputImage.pgm)+\n");
    return EXIT_NO_ERRORS;
  }

  // If wrong number of arguments given
  else if (argc < 6 && argc != 1)
  {
    // Print error message and return appropriate error code
    printf("ERROR: Bad Argument Count\n");
    return EXIT_WRONG_ARG_COUNT;
  }

  // CODE FOR READING INPUTFILES
  // Starting with argument number 3
  int fileCount = 0;
  int argNumber = 3;
  while (argNumber < (argc + 1))
  {
    FILE *inputFile = fopen(argv[argNumber], "r");

    // If file not available or not opened correctly
    if (inputFile == NULL)
    {
      // Print error message and return appropriate error code
      printf("ERROR: Bad File Name (%s)\n", argv[argNumber]);
      return EXIT_BAD_FILE_NAME;
    }

    fileCount++;
    argNumber = 3 * fileCount + 3;
  }


  // CODE FOR WRITING TO COMBINED OUTPUTFILE
  FILE *outputFile = fopen(argv[1], "w");

  // If file not opened correctly
  if (outputFile == NULL)
  {
    // Print error message and return appropriate error code
    printf("ERROR: Output Failed (%s)\n", argv[1]);
    return EXIT_OUTPUT_FAILED;
  }
  fclose(outputFile);

  // SUCCESS OUTPUTS
  printf("ASSEMBLED\n");
  return EXIT_NO_ERRORS;
}
