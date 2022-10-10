#ifndef pgmOutput_H
#define pgmOutput_H

int imageWriteDimensionsASCII(struct PGMFile *PGMpointer, FILE *outputFile, char *outputFilename);
int imageWriteDimensionsBinary(struct PGMFile *PGMpointer, FILE *outputFile, char *outputFilename);
int imageWriteASCIIData_2D(struct PGMFile *PGMpointer, FILE *outputFile, char *outputFilename);
int imageWriteBinaryData_2D(struct PGMFile *PGMpointer, FILE *outputFile, char *outputFilename);
int imageCompare(struct PGMFile *PGMpointer1, struct PGMFile *PGMpointer2);
int imageReduce(struct PGMFile *PGMpointer1, struct PGMFile *PGMpointer2, int reductionFactor, FILE *inputFile);
char* generateFilename(char* nameTemplate, int row, int col, char* fileNameString, int startOfRow, int startOfColumn);
int allocateTileMemory(struct PGMFile* PGMpointer, struct PGMFile* PGMpointerTile);
int tileGenerate(struct PGMFile *PGMpointer, struct PGMFile *PGMpointerTile, int xCoordinate, int yCoordinate);

#endif
