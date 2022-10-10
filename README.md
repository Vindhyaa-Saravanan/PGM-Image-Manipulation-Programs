# PGM-Image-Manipulation-Programs
A coursework application that was developed for the course COMP1921 Programming Project in C, academic year: 2021-22.

Name of Student: Vindhyaa Saravanan
Student ID: 201542641
Email: sc21vs@leeds.ac.uk

Individual project undertaken in C, to develop set of programs utilizing common functions from custom-made modules to read, write, copy, compare, convert, and reduce PGM image files. 
This assignment consists of writing a variety of utility C programs that work on .pgm files.
To compile all the tasks, run `make`.

## TASK ONE : MODULAR VERSION OF pgmEcho.c
The program pgmEcho.c produces a copy of an input .pgm file saved with a user-specified name.
It was redesigned to be more modular in nature.
* It takes 2 arguments (Usage: ./pgmEcho inputImage.pgm outputImage.pgm)
* To compile: run `make pgmEcho`
Refer to modules.txt for a full explanation of functionality of each module.

## TASK TWO: pgmComp.c
The program pgmComp checks if two .pgm files are logically equivalent.
* It takes 2 arguments (Usage: ./pgmComp inputImage.pgm inputImage.pgm)
* To compile: run `make pgmComp`

## TASK THREE: pgma2b.c AND pgmb2a.c
pgma2b and pgmb2a are two utility programs that convert pgm files between ASCII and binary formats.
* pgma2b takes 2 arguments (Usage: ./pgma2b inputImage.pgm outputImage.pgm)
* To compile: run 'make pgma2b'
* pgmb2a takes 2 arguments (Usage: ./pgmb2a inputImage.pgm outputImage.pgm)
* To compile: run `make pgmb2a`

## TASK FOUR: pgmReduce.c
The program pgmReduce reduces the input file by a user-specified factor in each dimension.
* It takes 3 arguments (Usage: ./pgmReduce inputImage.pgm reduction_factor outputImage.pgm)
* To compile: run `make pgmReduce`


# Modules for above programs:
The files pgmInput.c and pgmOutput.c contain functions for processing PGM images.
These are reused across all the programs of this assignment.
Refer to modules.txt for a full explanation of functionality of each module.


# TESTING THE TASKS
Testscript can be run using `./testscript.sh`
