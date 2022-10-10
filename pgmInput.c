/****************************************/
/* COMP 1921 Programming Project        */
/* 2021-22 Spring Semester              */
/*                                      */
/* Name of Student: Vindhyaa Saravanan  */
/* Email: sc21vs@leeds.ac.uk            */
/* Student ID: 201542641                */
/****************************************/

/***********************************/
/* pgmInput.c                      */
/* Module that contains functions  */
/* related to inputfile            */
/***********************************/

//Importing standard modules
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

// Importing user-defined modules
#include "pgmDef.h"

/*
* FUNCTION TO READ MAGIC NUMBER
* Takes in a PGMfile struct, input file stream as parameters
* Reads magic number of given file into struct and returns relevant code
*/
int getMagicNumber(struct PGMFile *PGMpointer, FILE *inputFile, char* filename)
{
  // Read magic number from input file stream
  PGMpointer->magic_number[0] = getc(inputFile);
  PGMpointer->magic_number[1] = getc(inputFile);

  unsigned short *magic_Number = (unsigned short *) PGMpointer->magic_number;

  // Check if magic number is valid
  if (*magic_Number != MAGIC_NUMBER_ASCII_PGM && *magic_Number != MAGIC_NUMBER_RAW_PGM)
  {
    // Close file
    fclose(inputFile);

    // Print error message and return appropriate error code
    printf("ERROR: Bad Magic Number (%s)\n", filename);
    exit(EXIT_BAD_MAGIC_NUMBER);
  }

  return EXIT_NO_ERRORS;
}


/*
* FUNCTION TO READ COMMENT
* Takes in a PGMfile struct, input file stream as parameters
* Reads comment of given file into struct and returns relevant code
*/
int getComment(struct PGMFile *PGMpointer, FILE *inputFile, char* filename)
{
  // Scan whitespace if present
  fscanf(inputFile, " ");

  // Check for a comment line
  char checkChar = fgetc(inputFile);
  if (checkChar == '#')
  {
    // Allocate buffer using malloc and read in comment
    PGMpointer->commentLine = (char *) malloc(MAX_COMMENT_LINE_LENGTH);
    char *commentString = fgets(PGMpointer->commentLine, MAX_COMMENT_LINE_LENGTH, inputFile);

    // If comment line malloc fails or comment is too long
    if ((commentString == NULL) || (strlen(commentString) > 128))
    {
      // Free memory and close inputfile
      free(PGMpointer->commentLine);
      fclose(inputFile);

      // Print error message and return appropriate error code
      printf("ERROR: Bad Comment Line (%s)\n", filename);
      exit(EXIT_BAD_COMMENT_LINE);
    }

    // Freeing commentline once validation is over
    free(PGMpointer->commentLine);
  }

  else
  {
    // This is not a comment line, hence put the character back
    ungetc(checkChar, inputFile);
  }

  return EXIT_NO_ERRORS;
}


/*
* FUNCTION TO READ IMAGE HEADER
* Takes in a PGMfile struct, input file stream as parameters
* Reads header of given file into struct and returns relevant code
*/
int getHeader(struct PGMFile *PGMpointer, FILE *inputFile, char* filename)
{
  // Read in width, height, grays
  int scanCount = fscanf(inputFile, " %u %u %u", &(PGMpointer->width), &(PGMpointer->height), &(PGMpointer->maxGray));

  // If number of items read is incorrect or dimensions are invalid
  if 	(
    (scanCount != 3				)	||
    (PGMpointer->width 	< MIN_IMAGE_DIMENSION	) 	||
    (PGMpointer->width 	>= MAX_IMAGE_DIMENSION	) 	||
    (PGMpointer->height < MIN_IMAGE_DIMENSION	) 	||
    (PGMpointer->height >= MAX_IMAGE_DIMENSION	)
  )
  {
    // Close inputfile
    fclose(inputFile);

    // Print error message and return appropriate error code
    printf("ERROR: Bad Dimensions (%s)\n", filename);
    exit(EXIT_BAD_DIMENSIONS);
  }

  // If maxGray is invalid
  else if (PGMpointer->maxGray != 255	)
  {
    // Close inputfile
    fclose(inputFile);

    // Print error message and return appropriate error code
    printf("ERROR: Bad Max Gray Value (%s)\n", filename);
    exit(EXIT_BAD_MAX_GRAY);
  }

  return EXIT_NO_ERRORS;
}


/*
* FUNCTION TO READ IN AN ASCII PGM FILE
* Takes in a ASCII PGMfile struct, input file stream as parameters
* Writes data of given input file into struct and returns relevant code
*/
int imageReadASCII_2D(struct PGMFile *PGMpointer, FILE *inputFile, char* filename)
{
  // Calculate number of bytes to be read, allocate memory for same
  PGMpointer->imageDataArray = (unsigned char **) malloc(PGMpointer->height * sizeof(unsigned char *));

  // If memory not allocated properly
  if (PGMpointer->imageDataArray == NULL)
  {
    // Close inputfile
    fclose(inputFile);

    // Print error message and return appropriate error code
    printf("ERROR: Image Malloc Failed \n");
    exit(EXIT_IMAGE_MALLOC_FAILED);
  }

  int numberRead = 0;
  int row, col;

  for (int row = 0; row < PGMpointer->height; row++)
  {
    PGMpointer->imageDataArray[row] = (unsigned char *) malloc(PGMpointer->width * sizeof(unsigned char));

    // If memory not allocated properly
    if (PGMpointer->imageDataArray[row] == NULL)
    {
      // Free memory and close inputfile
      free(PGMpointer->imageDataArray);
      fclose(inputFile);

      // Print error message and return appropriate error code
      printf("ERROR: Image Malloc Failed \n");
      exit(EXIT_IMAGE_MALLOC_FAILED);
    }
  }

  for (row = 0; row < PGMpointer->height; row++)
  {
    for (col = 0; col < PGMpointer->width; col++)
    {
      // Read next value
      int grayValue = -1;
      int scanCount = fscanf(inputFile, " %u", &grayValue);

      // If number of items read if incorrect or pixel value is invalid
      if ((scanCount != 1) || (grayValue < 0) || (grayValue > 255))
      {
        // Free memory and close inputfile
        for (int rowToFree = PGMpointer->height - 1; rowToFree >= 0; rowToFree--)
        {
          free(PGMpointer->imageDataArray[rowToFree]);
        }
        free(PGMpointer->imageDataArray);
        fclose(inputFile);

        // Print error message and return appropriate error code
        printf("ERROR: Bad Data (%s)\n", filename);
        exit(EXIT_BAD_DATA);
      }

      // Set pixel value into imageData, count number of pixels read
      PGMpointer->imageDataArray[row][col] = (unsigned char) grayValue;
      numberRead++;
    }
  }


  // Read more than dimensions and see if extra data is there
  unsigned int extraValue;
  int checkExtra = fscanf(inputFile, " %u", &extraValue);

  // IF TOO LITTLE DATA
  if (numberRead < PGMpointer->width * PGMpointer->height)
  {
    // Free memory and close inputfile
    for (int rowToFree = PGMpointer->height - 1; rowToFree >= 0; rowToFree--)
    {
      free(PGMpointer->imageDataArray[rowToFree]);
    }
    free(PGMpointer->imageDataArray);
    fclose(inputFile);

    // Print error message and return appropriate error code
    printf("ERROR: Bad Data (%s)\n", filename);
    exit(EXIT_BAD_DATA);
  }

  // IF TOO MUCH DATA
  else if (checkExtra > 0)
  {
    // Free memory and close inputfile
    for (int rowToFree = PGMpointer->height - 1; rowToFree >= 0; rowToFree--)
    {
      free(PGMpointer->imageDataArray[rowToFree]);
    }
    free(PGMpointer->imageDataArray);
    fclose(inputFile);

    // Print error message and return appropriate error code
    printf("ERROR: Bad Data (%s)\n", filename);
    exit(EXIT_BAD_DATA);
  }

  // Close inputfile
  fclose(inputFile);
  return EXIT_NO_ERRORS;

}

/*
* FUNCTION TO READ IN A BINARY PGM FILE
* Takes in a Binary PGMfile struct, input file stream as parameters
* Writes data of given input file into struct and returns relevant code
*/
int imageReadBinary_2D(struct PGMFile *PGMpointer, FILE *inputFile, char* filename)
{
  // Calculate number of bytes to be read, allocate memory for same
  PGMpointer->imageDataArray = (unsigned char **) malloc(PGMpointer->height * sizeof(unsigned char *));
  fgetc(inputFile);

  // If memory not allocated properly
  if (PGMpointer->imageDataArray == NULL)
  {
    // Close inputfile
    fclose(inputFile);

    // Print error message and return appropriate error code
    printf("ERROR: Image Malloc Failed \n");
    exit(EXIT_IMAGE_MALLOC_FAILED);
  }

  int row, col;

  for (row = 0; row < PGMpointer->height; row++)
  {
    PGMpointer->imageDataArray[row] = (unsigned char *) malloc(PGMpointer->width * sizeof(unsigned char));

    // If memory not allocated properly
    if (PGMpointer->imageDataArray[row] == NULL)
    {
      // Free memory and close inputfile
      free(PGMpointer->imageDataArray);
      fclose(inputFile);

      // Print error message and return appropriate error code
      printf("ERROR: Image Malloc Failed \n");
      exit(EXIT_IMAGE_MALLOC_FAILED);
    }
  }


  // Read in binary data into the array
  for (row = 0; row < PGMpointer->height; row++)
  {
    for (col = 0; col < PGMpointer->width; col++)
    {
      // Get value from array for validation
      int read = fread(&PGMpointer->imageDataArray[row][col], sizeof(unsigned char), 1, inputFile);

      // Check for too little data
      if (read == 0)
      {
        // Free memory and close inputfile
        for (int rowToFree = PGMpointer->height - 1; rowToFree >= 0; rowToFree--)
        {
          free(PGMpointer->imageDataArray[rowToFree]);
        }
        free(PGMpointer->imageDataArray);
        fclose(inputFile);

        // Print error message and return appropriate error code
        printf("ERROR: Bad Data (%s)\n", filename);
        exit(EXIT_BAD_DATA);
      }
    }
  }

  // Read more than dimensions and see if extra data is there
  unsigned int extraValue;
  int checkExtra = fscanf(inputFile, " %u", &extraValue);

  // IF TOO MUCH DATA
  if (checkExtra > 0)
  {
    // Free memory
    for (int rowToFree = PGMpointer->height - 1; rowToFree >= 0; rowToFree--)
    {
      free(PGMpointer->imageDataArray[rowToFree]);
    }
    free(PGMpointer->imageDataArray);

    // Close file
    fclose(inputFile);

    // Print error message and return appropriate error code
    printf("ERROR: Bad Data (%s)\n", filename);
    exit(EXIT_BAD_DATA);
  }

  // Close inputfile
  fclose(inputFile);
  return EXIT_NO_ERRORS;
}
