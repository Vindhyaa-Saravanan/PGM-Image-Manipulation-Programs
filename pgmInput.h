#ifndef pgmInput_H
#define pgmInput_H

int getMagicNumber(struct PGMFile *PGMpointer, FILE *inputFile, char* filename);
int getComment(struct PGMFile *PGMpointer, FILE *inputFile, char* filename);
int getHeader(struct PGMFile *PGMpointer, FILE *inputFile, char* filename);
int imageReadASCII(struct PGMFile *PGMpointer, FILE *inputFile, char* filename);
int imageReadBinary(struct PGMFile *PGMpointer, FILE *inputFile, char* filename);
int imageReadASCII_2D(struct PGMFile *PGMpointer, FILE *inputFile, char* filename);
int imageReadBinary_2D(struct PGMFile *PGMpointer, FILE *inputFile, char* filename);

#endif
