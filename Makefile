# Programming Project Coursework 1
# Name of Student: Vindhyaa Saravanan
# Student ID: 201542641
# Email: sc21vs@leeds.ac.uk

# MAKEFILE

# Name of compiler to use
CC =         gcc

# Flags to use in compilation
CCFLAGS =    -g -std=c99 -fmax-errors=1 -Wall -Werror

# Set of subordinate modules
MODULES =    pgmDef.o pgmInput.o pgmOutput.o

# Set of all main routines
MAINS =      pgmEcho.o pgmComp.o pgma2b.o pgmb2a.o pgmReduce.o pgmTile.o pgmAssemble.o

# Set of all targets
TARGETS =    pgmEcho pgmComp pgma2b pgmb2a pgmReduce pgmTile pgmAssemble

# Standard target to compile all files and create multiple executables
all:         ${TARGETS}

# Standard target to clean up all files
clean:
	rm ${TARGETS} ${MAINS} ${MODULES} *.o



# PGMECHO Executable
# target          dependencies
pgmEcho:          pgmEcho.o ${MODULES}
#       tool    flags        output name   files
				${CC}   ${CCFLAGS}   -o pgmEcho    pgmEcho.o ${MODULES}

# PGMCOMP Executable
# target          dependencies
pgmComp:          pgmComp.o ${MODULES}
#       tool    flags        output name   files
				${CC}   ${CCFLAGS}   -o pgmComp    pgmComp.o ${MODULES}

# PGMREDUCE Executable
# target          dependencies
pgmReduce:        pgmReduce.o ${MODULES}
#       tool    flags        output name   files
				${CC}   ${CCFLAGS}   -o pgmReduce    pgmReduce.o ${MODULES}

# PGMTILE Executable
# target          dependencies
pgmTile:          pgmTile.o ${MODULES}
#       tool    flags        output name   files
				${CC}   ${CCFLAGS}   -o pgmTile    pgmTile.o ${MODULES}

# PGMASSEMBLE Executable
# target          dependencies
pgmAssemble:      pgmAssemble.o ${MODULES}
#       tool    flags        output name   files
				${CC}   ${CCFLAGS}   -o pgmAssemble    pgmAssemble.o ${MODULES}

# PGMA2B Executable
# target         dependencies
pgma2b:          pgma2b.o ${MODULES}
#       tool    flags        output name  files
				${CC}   ${CCFLAGS}   -o pgma2b    pgma2b.o ${MODULES}

# PGMA2B Executable
# target         dependencies
pgmb2a:          pgmb2a.o ${MODULES}
#       tool    flags        output name  files
				${CC}   ${CCFLAGS}   -o pgmb2a    pgmb2a.o ${MODULES}




# Target codes for different Modules

# PGMASSEMBLE.C
# target              implementation         interfaces
pgmAssemble.o:        pgmAssemble.c          pgmDef.h pgmInput.h pgmOutput.h

#        tool   flags                                           output name           files
	       gcc    -c -g -std=c99 -fmax-errors=1 -Wall -Werror     -o pgmAssemble.o      pgmAssemble.c


# PGMTILE.C
# target          implementation     interfaces
pgmTile.o:        pgmTile.c          pgmDef.h pgmInput.h pgmOutput.h

#        tool   flags                                           output name       files
	       gcc    -c -g -std=c99 -fmax-errors=1 -Wall -Werror     -o pgmTile.o      pgmTile.c


# PGMREDUCE.C
# target          implementation     interfaces
pgmReduce.o:        pgmReduce.c          pgmDef.h pgmInput.h pgmOutput.h

#        tool   flags                                           output name       files
	       gcc    -c -g -std=c99 -fmax-errors=1 -Wall -Werror     -o pgmReduce.o      pgmReduce.c


# PGMB2A.C
# target         implementation    interfaces
pgmb2a.o:        pgmb2a.c          pgmDef.h pgmInput.h pgmOutput.h

#        tool   flags                                           output name      files
	       gcc    -c -g -std=c99 -fmax-errors=1 -Wall -Werror     -o pgmb2a.o      pgmb2a.c


# PGMA2B.C
# target         implementation    interfaces
pgma2b.o:        pgma2b.c          pgmDef.h pgmInput.h pgmOutput.h

#        tool   flags                                           output name      files
	       gcc    -c -g -std=c99 -fmax-errors=1 -Wall -Werror     -o pgma2b.o      pgma2b.c


# PGMCOMP.C
# target          implementation     interfaces
pgmComp.o:        pgmComp.c          pgmDef.h pgmInput.h pgmOutput.h

#        tool   flags                                           output name       files
	       gcc    -c -g -std=c99 -fmax-errors=1 -Wall -Werror     -o pgmComp.o      pgmComp.c


# PGMECHO.C
# target          implementation     interfaces
pgmEcho.o:        pgmEcho.c          pgmDef.h pgmInput.h pgmOutput.h

#        tool   flags                                           output name       files
				 gcc    -c -g -std=c99 -fmax-errors=1 -Wall -Werror     -o pgmEcho.o      pgmEcho.c


# PGMECHOINPUT.C
# target           implementation      interfaces
pgmInput.o:        pgmInput.c          pgmDef.h pgmInput.h

#        tool   flags                                           output name        files
	       gcc    -c -g -std=c99 -fmax-errors=1 -Wall -Werror     -o pgmInput.o      pgmInput.c


# PGMECHOOUTPUT.C
# target            implementation       interfaces
pgmOutput.o:        pgmOutput.c          pgmDef.h pgmInput.h pgmOutput.h

#        tool   flags                                           output name         files
	       gcc    -c -g -std=c99 -fmax-errors=1 -Wall -Werror     -o pgmOutput.o      pgmOutput.c


# PGMECHODEF.C
# target         implementation    interfaces
pgmDef.o:        pgmDef.c          pgmDef.h

#        tool   flags                                           output name      files
	       gcc    -c -g -std=c99 -fmax-errors=1 -Wall -Werror     -o pgmDef.o      pgmDef.c
