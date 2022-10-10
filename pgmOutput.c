/****************************************/
/* COMP 1921 Programming Project        */
/* 2021-22 Spring Semester              */
/*                                      */
/* Name of Student: Vindhyaa Saravanan  */
/* Email: sc21vs@leeds.ac.uk            */
/* Student ID: 201542641                */
/****************************************/

/***********************************/
/* pgmOutput.c                     */
/* Module that contains functions  */
/* related to program output       */
/***********************************/

//Importing standard modules
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

// Importing user-defined modules
#include "pgmDef.h"
#include "pgmInput.h"


/*
* FUNCTION TO WRITE DIMENSIONS OF ASCII IMAGES
* Takes in a ASCII PGMfile struct, output file stream, output file name as parameters
* Writes dimensions of given pgm corresponding to struct into output file and returns relevant code
*/
int imageWriteDimensionsASCII(struct PGMFile *PGMpointer, FILE *outputFile, char *outputFilename)
{
	// Write dimensions
	size_t nHeaderWritten = fprintf(outputFile, "P2\n%d %d\n%d\n", PGMpointer->width, PGMpointer->height, PGMpointer->maxGray);

	// Check that dimensions are written correctly
	if (nHeaderWritten < 0)
	{
		// Free memory
		for (int rowToFree = PGMpointer->height - 1; rowToFree >= 0; rowToFree--)
    {
      free(PGMpointer->imageDataArray[rowToFree]);
    }
		free(PGMpointer->imageDataArray);

		// Close inputfile
		fclose(outputFile);

		// Print appropriate error message
		printf("ERROR: Output Failed (%s)\n", outputFilename);
		exit(EXIT_OUTPUT_FAILED);
	}
	return EXIT_NO_ERRORS;
}



/*
* FUNCTION TO WRITE DIMENSIONS OF BINARY IMAGES
* Takes in a ASCII PGMfile struct, output file stream, output file name as parameters
* Writes dimensions of given pgm corresponding to struct into output file and returns relevant code
*/
int imageWriteDimensionsBinary(struct PGMFile *PGMpointer, FILE *outputFile, char *outputFilename)
{
	// Write dimensions
	size_t nHeaderWritten = fprintf(outputFile, "P5\n%d %d\n%d\n", PGMpointer->width, PGMpointer->height, PGMpointer->maxGray);

	// Check that dimensions are written correctly
	if (nHeaderWritten < 0)
	{
		// Free memory
		for (int rowToFree = PGMpointer->height - 1; rowToFree >= 0; rowToFree--)
    {
      free(PGMpointer->imageDataArray[rowToFree]);
    }
		free(PGMpointer->imageDataArray);

		// Close inputfile
		fclose(outputFile);

		// Print appropriate error message
		printf("ERROR: Output Failed (%s)\n", outputFilename);
		exit(EXIT_OUTPUT_FAILED);
	}
	return EXIT_NO_ERRORS;
}



/*
* FUNCTION TO WRITE ASCII IMAGE STORED IN STRUCT INTO OUTPUT FILE
* Takes in a ASCII PGMfile struct, output file stream, output file name as parameters
* Writes data of given struct into output file and returns relevant code
*/
int imageWriteASCIIData_2D(struct PGMFile *PGMpointer, FILE *outputFile, char *outputFilename)
{
	// Print pixel data to file
	int numberWritten = 0;
	int row, col;

	for (row = 0; row < PGMpointer->height; row++)
	{
		for (col = 0; col < PGMpointer->width; col++)
		{
			int written = fprintf(outputFile, "%d%c", PGMpointer->imageDataArray[row][col], ' ');
			numberWritten += written;
		}
		fprintf(outputFile, "%c", '\n');
	}

	// If data write fails
	if (numberWritten < 0)
	{
		// Free memory and close outputfile
		for (int rowToFree = PGMpointer->height - 1; rowToFree >= 0; rowToFree--)
    {
      free(PGMpointer->imageDataArray[rowToFree]);
    }
		free(PGMpointer->imageDataArray);
		fclose(outputFile);

		// Print error message and return appropriate error code
		printf("ERROR: Output Failed (%s)\n", outputFilename);
		exit(EXIT_OUTPUT_FAILED);
	}


	// Close and return success value
	fclose(outputFile);
	for (int rowToFree = PGMpointer->height - 1; rowToFree >= 0; rowToFree--)
  {
    free(PGMpointer->imageDataArray[rowToFree]);
  }
	free(PGMpointer->imageDataArray);
	return EXIT_NO_ERRORS;
}



/*
* FUNCTION TO WRITE A BINARY IMAGE STORED IN STRUCT TO OUTPUT FILE
* Takes in a Binary PGMfile struct, output file stream, output file name as parameters
* Writes data of given struct into output file and returns relevant code
*/
int imageWriteBinaryData_2D(struct PGMFile *PGMpointer, FILE *outputFile, char *outputFilename)
{
	// Print pixel data to file
	int numberWritten = 0;
	int row;

	for (row = 0; row < PGMpointer->height; row++)
	{
			int written = fwrite(PGMpointer->imageDataArray[row], sizeof(unsigned char), PGMpointer->width, outputFile);
			numberWritten += written;
	}

	// If data write fails
	if (numberWritten < 0)
	{
		// Free memory and close outputfile
		for (int rowToFree = PGMpointer->height - 1; rowToFree >= 0; rowToFree--)
    {
      free(PGMpointer->imageDataArray[rowToFree]);
    }
		free(PGMpointer->imageDataArray);
		fclose(outputFile);

		// Print error message and return appropriate error code
		printf("ERROR: Output Failed (%s)\n", outputFilename);
		exit(EXIT_OUTPUT_FAILED);
	}


	// Close and return success value
	fclose(outputFile);
	free(PGMpointer->imageDataArray);
	return EXIT_NO_ERRORS;
}


/*
* FUNCTION TO COMPARE TWO PGMFILE STRUCTS
* Takes in two ASCII PGMfile structs as parameters
* Compares width, height and pixel data of both structs and returns relevant code
*/

int imageCompare(struct PGMFile *PGMpointer1, struct PGMFile *PGMpointer2)
{
	// TO COMPARE WIDTH AND HEIGHT
	if (PGMpointer1->width != PGMpointer2->width)
	{
		// Free memory
		for (int rowToFree = PGMpointer1->height - 1; rowToFree >= 0; rowToFree--)
    {
      free(PGMpointer1->imageDataArray[rowToFree]);
    }
		free(PGMpointer1->imageDataArray);

		for (int rowToFree = PGMpointer2->height - 1; rowToFree >= 0; rowToFree--)
    {
      free(PGMpointer2->imageDataArray[rowToFree]);
    }
		free(PGMpointer2->imageDataArray);

		// Print error message and return appropriate error code
		printf("DIFFERENT");
		exit(EXIT_NO_ERRORS);
	}

	else if (PGMpointer1->height != PGMpointer2->height)
	{
		// Free memory
		for (int rowToFree = PGMpointer1->height - 1; rowToFree >= 0; rowToFree--)
    {
      free(PGMpointer1->imageDataArray[rowToFree]);
    }
		free(PGMpointer1->imageDataArray);

		for (int rowToFree = PGMpointer2->height - 1; rowToFree >= 0; rowToFree--)
    {
      free(PGMpointer2->imageDataArray[rowToFree]);
    }
		free(PGMpointer2->imageDataArray);

		// Print error message and return appropriate error code
		printf("DIFFERENT\n");
		exit(EXIT_NO_ERRORS);
	}

	// TO COMPARE THE ACTUAL PIXEL DATA
	int numberSimilar = 0;

	// Compare value of each pixel to the corresponding pixel in other pgm
	int row, col;
	for (row = 0; row < PGMpointer1->height; row++)
	{
		for (col = 0; col < PGMpointer1->width; col++)
		{
			if (PGMpointer1->imageDataArray[row][col] == PGMpointer2->imageDataArray[row][col])
			{
				numberSimilar++;
			}
		}
	}

	// If all the pixels are not same,
	if (numberSimilar != PGMpointer1->width * PGMpointer1-> height)
	{
		// Free memory
		for (int rowToFree = PGMpointer1->height - 1; rowToFree >= 0; rowToFree--)
    {
      free(PGMpointer1->imageDataArray[rowToFree]);
    }
		free(PGMpointer1->imageDataArray);

		for (int rowToFree = PGMpointer2->height - 1; rowToFree >= 0; rowToFree--)
    {
      free(PGMpointer2->imageDataArray[rowToFree]);
    }
		free(PGMpointer2->imageDataArray);

		// Print error message and return appropriate error code
		printf("DIFFERENT\n");
		exit(EXIT_NO_ERRORS);
	}

	// If images identical, return success code
	for (int rowToFree = PGMpointer1->height - 1; rowToFree >= 0; rowToFree--)
	{
		free(PGMpointer1->imageDataArray[rowToFree]);
	}
	free(PGMpointer1->imageDataArray);

	for (int rowToFree = PGMpointer2->height - 1; rowToFree >= 0; rowToFree--)
	{
		free(PGMpointer2->imageDataArray[rowToFree]);
	}
	free(PGMpointer2->imageDataArray);


	return EXIT_NO_ERRORS;
}


/*
* FUNCTION TO REDUCE PGM STRUCT AND SAVE INTO ANOTHER STRUCT
* Takes in two PGMfile structs, input file stream, reduction factor as parameters
* Reduces data in first struct by reduction factor, stores in second struct, returns relevant code
*/
int imageReduce(struct PGMFile *PGMpointer1, struct PGMFile *PGMpointer2, int reductionFactor, FILE *inputFile)
{
	// Calculating dimensions of new reduced image
	PGMpointer2->width = (PGMpointer1-> width / reductionFactor);
	PGMpointer2->height = (PGMpointer1-> height / reductionFactor);
	PGMpointer2->maxGray = PGMpointer1->maxGray;


	// Allocating memory for the new image
  PGMpointer2->imageDataArray = (unsigned char **) malloc(PGMpointer2->height * PGMpointer2->width * sizeof(unsigned char *));

  // If memory not allocated properly
  if (PGMpointer2->imageDataArray == NULL)
  {
    // Free memory
		for (int rowToFree = PGMpointer1->height - 1; rowToFree >= 0; rowToFree--)
    {
      free(PGMpointer1->imageDataArray[rowToFree]);
    }
    free(PGMpointer1->imageDataArray);

    // Print error message and return appropriate error code
    printf("ERROR: Image Malloc Failed \n");
    exit(EXIT_IMAGE_MALLOC_FAILED);
  }


  int row, col;
  for (int row = 0; row < PGMpointer2->height; row++)
  {
    PGMpointer2->imageDataArray[row] = (unsigned char *) malloc(PGMpointer2->width * sizeof(unsigned char));

    // If memory not allocated properly
    if (PGMpointer2->imageDataArray[row] == NULL)
    {
      // Free memory
			for (int rowToFree = PGMpointer1->height - 1; rowToFree >= 0; rowToFree--)
	    {
	      free(PGMpointer1->imageDataArray[rowToFree]);
	    }
      free(PGMpointer1->imageDataArray);
			free(PGMpointer2->imageDataArray);

      // Print error message and return appropriate error code
      printf("ERROR: Image Malloc Failed \n");
      exit(EXIT_IMAGE_MALLOC_FAILED);
    }
  }


	// Saving data of new reduced image into its respective struct
	int newRow = 0;
	int newCol = 0;
	unsigned char reducedPixel;
	for (row = 0; row < PGMpointer1->height; row++)
	{
		// If row qualifies, get all required pixels from that row
		if ((row % reductionFactor) == 0)
		{
			for (col = 0; col < PGMpointer1->width; col++)
			{
				// If pixel qualifies
				if ((col % reductionFactor) == 0)
				{
					// Copy qualifying pixel into new reduced struct
					reducedPixel = PGMpointer1->imageDataArray[row][col];
					PGMpointer2->imageDataArray[newRow][newCol] = reducedPixel;

					// Move onto next pixel in original row
					newCol++;
				}
			}

			// Move onto next row of original image
			newRow++;
			newCol = 0;
		}
	}


	// Return relevant error codes
	// Free memory
	for (int rowToFree = PGMpointer1->height - 1; rowToFree >= 0; rowToFree--)
	{
		free(PGMpointer1->imageDataArray[rowToFree]);
	}
	free(PGMpointer1->imageDataArray);
	return EXIT_NO_ERRORS;
}



/*
* FUNCTION TO GENERATE FILENAMES FOR THE TILES
* Takes in string template, filename string, row and col to be added,
* location where row and col start in the template filename as parameters
* Returns prepared filename string
*/
char* generateFilename(char* nameTemplate, int row, int col, char* fileNameString, int startOfRow, int startOfColumn)
{
	// Reset filename
	memset(fileNameString, 0, 200);

	for (int letter = 0; letter < startOfRow; letter++)
	{
		fileNameString[letter] = nameTemplate[letter];
	}

	// String to hold row or col number
	char copyRow[2];
	char copyCol[2];

	sprintf(copyRow, "%i", row);
	sprintf(copyCol, "%i", col);

	// Add row to the filename
	strcat(fileNameString, copyRow);

	// Temporary string for manipulations, reset it
	char stringTemp[40];
	memset(stringTemp, 0, 40);

	int countOne = 0;
	for (int index = startOfRow + 5; index < startOfColumn; index++)
	{
		stringTemp[countOne] = nameTemplate[index];
		countOne++;
	}

	// Add column to the filename
	strcat(fileNameString, stringTemp);
	strcat(fileNameString, copyCol);

	// Add final .pgm
	strcat(fileNameString, ".pgm");

	// Return prepared filename
	return fileNameString;
}



/*
* FUNCTION TO ALLOCATE TILE STRUCT
* Takes in struct of inputfile, struct of tile, as parameters
* Allocates memory for the new tile struct data
*/
int allocateTileMemory(struct PGMFile* PGMpointer, struct PGMFile* PGMpointerTile)
{
	// Allocating memory for the new image
  PGMpointerTile->imageDataArray = (unsigned char **) malloc(PGMpointerTile->height * PGMpointerTile->width * sizeof(unsigned char *));

  // If memory not allocated properly
  if (PGMpointerTile->imageDataArray == NULL)
  {
    // Free memory
		for (int rowToFree = PGMpointer->height - 1; rowToFree >= 0; rowToFree--)
    {
      free(PGMpointer->imageDataArray[rowToFree]);
    }
    free(PGMpointer->imageDataArray);

    // Print error message and return appropriate error code
    printf("ERROR: Image Malloc Failed \n");
    exit(EXIT_IMAGE_MALLOC_FAILED);
  }


  int row;
  for (row = 0; row < PGMpointerTile->height; row++)
  {
    PGMpointerTile->imageDataArray[row] = (unsigned char *) malloc(PGMpointerTile->width * sizeof(unsigned char));

    // If memory not allocated properly
    if (PGMpointerTile->imageDataArray[row] == NULL)
    {
      // Free memory
			for (int rowToFree = PGMpointer->height - 1; rowToFree >= 0; rowToFree--)
	    {
	      free(PGMpointer->imageDataArray[rowToFree]);
	    }
      free(PGMpointer->imageDataArray);

			free(PGMpointerTile->imageDataArray);

      // Print error message and return appropriate error code
      printf("ERROR: Image Malloc Failed \n");
      exit(EXIT_IMAGE_MALLOC_FAILED);
    }
  }

	return EXIT_NO_ERRORS;
}




/*
* FUNCTION TO CREATE TILE STRUCT
* Takes in struct of inputfile, struct of tile, and relative position
* of tile as parameters
* Validates the template as a good template
*/
int tileGenerate(struct PGMFile *PGMpointer, struct PGMFile *PGMpointerTile, int xCoordinate, int yCoordinate)
{
	int rowIndex, colIndex;
	for (rowIndex = 0; rowIndex < PGMpointerTile->height; rowIndex++)
	{
		for (colIndex = 0; colIndex < PGMpointerTile->width; colIndex++)
		{
			PGMpointerTile->imageDataArray[rowIndex][colIndex] = PGMpointer->imageDataArray[rowIndex + xCoordinate][colIndex + yCoordinate];
		}
	}

	return EXIT_NO_ERRORS;
}
