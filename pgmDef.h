#ifndef pgmDef_H
#define pgmDef_H

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

struct PGMFile
{
  unsigned char magic_number[2];
  char *commentLine;
  unsigned int width, height;
  unsigned int maxGray;
  unsigned char *imageData;
  unsigned char **imageDataArray;
};


void initializePGMFile(struct PGMFile *PGMpointer);

#endif
