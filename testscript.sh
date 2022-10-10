#! /bin/sh

# TESTSCRIPT FOR PGM UTILITIES

# The following testscript contains tests for checking
# various error outputs and return codes
# as well as successful output behaviour
# in the programs of this assignment.


# **************************** TESTS FOR PGMECHO *******************************


printf "\n"
echo '************TESTS FOR PGMECHO************'
printf "\n"
echo '1. No arguments provided:'
# Should print Usage: ./pgmEcho inputImage.pgm outputImage.pgm and return 0
./pgmEcho
echo $?

printf "\n"
echo '2. Wrong number of arguments:'
# Should print ERROR: Bad Argument Count and return 1
./pgmEcho inputAscii.pgm
echo $?

printf "\n"
echo '3. Bad filename:'
# Should print ERROR: Bad File Name (badFilename.pgm) and return 2
./pgmEcho badFilename.pgm echoed.pgm
echo $?

printf "\n"
echo '3. Non-Readable file:'
# Should print ERROR: Bad File Name (badFilename.pgm) and return 2
./pgmEcho badFilename.pgm echoed.pgm
echo $?

printf "\n"
echo '4. Bad magic number:'
# Should print ERROR: Bad Magic Number (badMagicNumber.pgm) and return 3
./pgmEcho badMagicNumber.pgm echoed.pgm
echo $?

printf "\n"
echo '5. Large comment:'
# Should print ERROR: Bad Comment Line (largeComment.pgm) and return 4
./pgmEcho largeComment_A.pgm echoed.pgm
echo $?
./pgmEcho largeComment_B.pgm echoed.pgm
echo $?

printf "\n"
echo '6. Bad dimensions (-1):'
# Should print ERROR: Bad Dimensions (badDimensionLower_A.pgm) and return 5
./pgmEcho badDimensionLower_A.pgm echoed.pgm
echo $?
./pgmEcho badDimensionLower_B.pgm echoed.pgm
echo $?

printf "\n"
echo '7. Bad dimensions (65536):'
# Should print ERROR: Bad Dimensions (badDimensionHigher_A.pgm) and return 5
./pgmEcho badDimensionHigher_A.pgm echoed.pgm
echo $?
./pgmEcho badDimensionHigher_B.pgm echoed.pgm
echo $?

printf "\n"
echo '8. Bad max gray value:'
# Should print ERROR: Bad Max Gray Value (badMaxGray_A.pgm) and return 6
./pgmEcho badMaxGray_A.pgm echoed.pgm
echo $?
./pgmEcho badMaxGray_B.pgm echoed.pgm
echo $?

printf "\n"
echo '9. Too little data:'
# Should print ERROR: Bad Max Gray Value (tooLittleData_A.pgm) and return 8
./pgmEcho tooLittleData_A.pgm echoed.pgm
echo $?
./pgmEcho tooLittleData_B.pgm echoed.pgm
echo $?

printf "\n"
echo '10. Too much data:'
# Should print ERROR: Bad Data (tooMuchData_A.pgm) and return 8
./pgmEcho tooMuchData_A.pgm echoed.pgm
echo $?
./pgmEcho tooMuchData_B.pgm echoed.pgm
echo $?

printf "\n"
echo '11. Non writeable file:'
# Should print ERROR: Bad Data (tooMuchData_A.pgm) and return 8
./pgmEcho inputAscii.pgm nonWriteable.pgm
echo $?

# Correct format ASCII
printf "\n"
echo '12. Correct format, ASCII file being echoed:'
# Should print ECHOED (and produce a correctly echoed ASCII file) and return 0
./pgmEcho inputAscii.pgm echoedAscii.pgm
echo $?

# Correct format BINARY
printf "\n"
echo '13. Correct format, Binary file being echoed:'
# Should print ECHOED (and produce a correctly echoed BINARY file) and return 0
./pgmEcho inputBinary.pgm echoedBinary.pgm
echo $?


# **************************** TESTS FOR PGMCOMP *******************************

printf "\n"
echo '************TESTS FOR PGMCOMP************'
printf "\n"
echo '14. No arguments provided:'
# Should print Usage: ./pgmComp inputImage.pgm inputImage.pgm and return 0
./pgmComp
echo $?

printf "\n"
echo '15. Wrong number of arguments:'
# Should print ERROR: Bad Argument Count and return 1
./pgmComp inputAscii.pgm
echo $?

printf "\n"
echo '16. Bad filename:'
# Should print ERROR: Bad File Name (badFilename.pgm) and return 2
./pgmComp badFilename.pgm inputAscii.pgm
echo $?

printf "\n"
echo '17. Non-Readable file:'
# Should print ERROR: Bad File Name (badFilename.pgm) and return 2
./pgmComp badFilename.pgm inputAscii.pgm
echo $?

printf "\n"
echo '18. Bad magic number:'
# Should print ERROR: Bad Magic Number (badMagicNumber.pgm) and return 3
./pgmComp badMagicNumber.pgm inputAscii.pgm
echo $?

printf "\n"
echo '19. Large comment:'
# Should print ERROR: Bad Comment Line (largeComment.pgm) and return 4
./pgmComp largeComment_A.pgm inputAscii.pgm
echo $?
./pgmComp largeComment_B.pgm inputAscii.pgm
echo $?

printf "\n"
echo '20. Bad dimensions (-1):'
# Should print ERROR: Bad Dimensions (badDimensionLower.pgm) and return 5
./pgmComp badDimensionLower_A.pgm inputAscii.pgm
echo $?
./pgmComp badDimensionLower_B.pgm inputAscii.pgm
echo $?

printf "\n"
echo '21. Bad dimensions (65536):'
# Should print ERROR: Bad Dimensions (badDimensionHigher.pgm) and return 5
./pgmComp badDimensionHigher_A.pgm inputAscii.pgm
echo $?
./pgmComp badDimensionHigher_B.pgm inputAscii.pgm
echo $?

printf "\n"
echo '22. Bad max gray value:'
# Should print ERROR: Bad Max Gray Value (badMaxGray_A.pgm) and return 6
./pgmComp badMaxGray_A.pgm inputAscii.pgm
echo $?
./pgmComp badMaxGray_B.pgm inputAscii.pgm
echo $?

printf "\n"
echo '23. Too little data:'
# Should print ERROR: Bad Max Gray Value (tooLittleData_A.pgm) and return 8
./pgmComp tooLittleData_A.pgm inputAscii.pgm
echo $?
./pgmComp tooLittleData_B.pgm inputAscii.pgm
echo $?

printf "\n"
echo '24. Too much data:'
# Should print ERROR: Bad Data (tooMuchData_A.pgm) and return 8
./pgmComp tooMuchData_A.pgm inputAscii.pgm
echo $?
./pgmComp tooMuchData_B.pgm inputAscii.pgm
echo $?

# Correct format
# ASCII TESTS
printf "\n"
echo '25. Correct format, two identical ASCII files being compared:'
# Identifies identical correctly
# Should print IDENTICAL
./pgmComp inputAscii.pgm identicalA.pgm
echo $?

# Identifies different correctly
printf "\n"
echo '26. Two ASCII files being compared, pixels different:'
# Pixels Different
# Should print DIFFERENT
./pgmComp inputAscii.pgm different1_A.pgm
echo $?

printf "\n"
echo '27. Two ASCII files being compared, width different:'
# Width Different
# Should print DIFFERENT
./pgmComp inputAscii.pgm different2_A.pgm
echo $?

printf "\n"
echo '28. Two ASCII files being compared, height different:'
# Height Different
# Should print DIFFERENT
./pgmComp inputAscii.pgm different3_A.pgm
echo $?

# BINARY TESTS
printf "\n"
echo '29. Correct format, two identical binary files being compared:'
# Identifies identical correctly
# Should print IDENTICAL
./pgmComp inputBinary.pgm identicalB.pgm
echo $?

# Identifies different correctly
printf "\n"
echo '30. Two binary files being compared, pixels different:'
# Pixels Different
# Should print DIFFERENT
./pgmComp inputBinary.pgm different1_B.pgm
echo $?

# Width Different
printf "\n"
echo '31. Two binary files being compared, width different:'
# Should print DIFFERENT
./pgmComp inputBinary.pgm different2_B.pgm
echo $?

# Height Different
printf "\n"
echo '32. Two binary files being compared, height different:'
# Should print DIFFERENT
./pgmComp inputBinary.pgm different3_B.pgm
echo $?



# **************************** TESTS FOR PGMA2B *******************************


# TESTS FOR PGMA2B
printf "\n"
echo '************TESTS FOR PGMA2B************'
printf "\n"
echo '33. No arguments provided:'
# Should print Usage: ./pgmaa2b inputImage.pgm inputImage.pgm and return 0
./pgma2b
echo $?

printf "\n"
echo '34. Wrong number of arguments:'
# Should print ERROR: Bad Argument Count and return 1
./pgma2b inputAscii.pgm
echo $?

printf "\n"
echo '35. Bad filename:'
# Should print ERROR: Bad File Name (badFilename.pgm) and return 2
./pgma2b badFilename.pgm converted.pgm
echo $?

printf "\n"
echo '36. Non-Readable file:'
# Should print ERROR: Bad File Name (badFilename.pgm) and return 2
./pgma2b badFilename.pgm converted.pgm
echo $?

printf "\n"
echo '37. Bad magic number:'
# Should print ERROR: Bad Magic Number (badMagicNumber.pgm) and return 3
./pgma2b badMagicNumber.pgm converted.pgm
echo $?

printf "\n"
echo '38. Large comment:'
# Should print ERROR: Bad Comment Line (largeComment.pgm) and return 4
./pgma2b largeComment_A.pgm converted.pgm
echo $?

printf "\n"
echo '39. Bad dimensions (-1):'
# Should print ERROR: Bad Dimensions (badDimensionLower.pgm) and return 5
./pgma2b badDimensionLower_A.pgm converted.pgm
echo $?

printf "\n"
echo '40. Bad dimensions (65536):'
# Should print ERROR: Bad Dimensions (badDimensionHigher.pgm) and return 5
./pgma2b badDimensionHigher_A.pgm converted.pgm
echo $?

printf "\n"
echo '41. Bad max gray value:'
# Should print ERROR: Bad Max Gray Value (badMaxGray_A.pgm) and return 6
./pgma2b badMaxGray_A.pgm converted.pgm
echo $?

printf "\n"
echo '42. Too little data:'
# Should print ERROR: Bad Max Gray Value (tooLittleData_A.pgm) and return 8
./pgma2b tooLittleData_A.pgm converted.pgm
echo $?

printf "\n"
echo '43. Too much data:'
# Should print ERROR: Bad Data (tooMuchData_A.pgm) and return 8
./pgma2b tooMuchData_A.pgm converted.pgm
echo $?

printf "\n"
echo '44. Non writeable file:'
# Should print ERROR: Bad Data (tooMuchData_A.pgm) and return 8
./pgma2b inputAscii.pgm nonWriteable.pgm
echo $?

printf "\n"
echo '45. Binary file input to pgma2b:'
# Should print ERROR: Bad Data (tooMuchData_A.pgm) and return 8
./pgma2b inputBinary.pgm converted.pgm
echo $?

# Correct format
printf "\n"
echo '46. Correct format, ASCII file being converted to Binary:'
# Identifies identical correctly
# Should print CONVERTED
./pgma2b inputAscii.pgm convertedBinary.pgm
echo $?


# **************************** TESTS FOR PGMB2A *******************************


printf "\n"
echo '************TESTS FOR PGMB2A************'
printf "\n"
echo '47. No arguments provided:'
# Should print Usage: ./pgmb2a inputImage.pgm inputImage.pgm and return 0
./pgmb2a
echo $?

printf "\n"
echo '48. Wrong number of arguments:'
# Should print ERROR: Bad Argument Count and return 1
./pgmb2a inputAscii.pgm
echo $?

printf "\n"
echo '49. Bad filename:'
# Should print ERROR: Bad File Name (badFilename.pgm) and return 2
./pgmb2a badFilename.pgm converted.pgm
echo $?

printf "\n"
echo '50. Non-Readable file:'
# Should print ERROR: Bad File Name (badFilename.pgm) and return 2
./pgmb2a badFilename.pgm converted.pgm
echo $?

printf "\n"
echo '51. Bad magic number:'
# Should print ERROR: Bad Magic Number (badMagicNumber.pgm) and return 3
./pgmb2a badMagicNumber.pgm converted.pgm
echo $?

printf "\n"
echo '52. Large comment:'
# Should print ERROR: Bad Comment Line (largeComment.pgm) and return 4
./pgmb2a largeComment_B.pgm converted.pgm
echo $?

printf "\n"
echo '53. Bad dimensions (-1):'
# Should print ERROR: Bad Dimensions (badDimensionLower.pgm) and return 5
./pgmb2a badDimensionLower_B.pgm converted.pgm
echo $?

printf "\n"
echo '54. Bad dimensions (65536):'
# Should print ERROR: Bad Dimensions (badDimensionHigher.pgm) and return 5
./pgmb2a badDimensionHigher_B.pgm converted.pgm
echo $?

printf "\n"
echo '55. Bad max gray value:'
# Should print ERROR: Bad Max Gray Value (badMaxGray_A.pgm) and return 6
./pgmb2a badMaxGray_B.pgm converted.pgm
echo $?

printf "\n"
echo '56. Too little data:'
# Should print ERROR: Bad Max Gray Value (tooLittleData_A.pgm) and return 8
./pgmb2a tooLittleData_B.pgm converted.pgm
echo $?

printf "\n"
echo '57. Too much data:'
# Should print ERROR: Bad Data (tooMuchData_A.pgm) and return 8
./pgmb2a tooMuchData_B.pgm converted.pgm
echo $?

printf "\n"
echo '58. Non writeable file:'
# Should print ERROR: Bad Data (tooMuchData_A.pgm) and return 8
./pgmb2a inputBinary.pgm nonWriteable.pgm
echo $?

printf "\n"
echo '59. ASCII file input to pgmb2a:'
# Should print ERROR: Bad Data (tooMuchData_A.pgm) and return 8
./pgmb2a inputAscii.pgm converted.pgm
echo $?

# Correct format
printf "\n"
echo '60. Correct format, Binary file being converted to ASCII:'
# Identifies identical correctly
# Should print CONVERTED
./pgmb2a inputBinary.pgm convertedAscii.pgm
echo $?


# **************************** TESTS FOR PGMREDUCE ****************************


printf "\n"
echo '************TESTS FOR PGMREDUCE************'
printf "\n"
echo '61. No arguments provided:'
# Should print Usage: ./pgmReduce inputImage.pgm reduction_factor outputImage.pgm and return 0
./pgmReduce
echo $?

printf "\n"
echo '62. Wrong number of arguments:'
# Should print ERROR: Bad Argument Count and return 1
./pgmReduce inputAscii.pgm
echo $?

printf "\n"
echo '63. Wrong number of arguments:'
# Should print ERROR: Bad Argument Count and return 1
./pgmReduce inputAscii.pgm 5
echo $?

printf "\n"
echo '64. Bad filename:'
# Should print ERROR: Bad File Name (badFilename.pgm) and return 2
./pgmReduce badFilename.pgm 5 reduced.pgm
echo $?

printf "\n"
echo '65. Non-Readable file:'
# Should print ERROR: Bad File Name (badFilename.pgm) and return 2
./pgmReduce badFilename.pgm 5 reduced.pgm
echo $?

printf "\n"
echo '66. Bad magic number:'
# Should print ERROR: Bad Magic Number (badMagicNumber.pgm) and return 3
./pgmReduce badMagicNumber.pgm 5 reduced.pgm
echo $?

printf "\n"
echo '67. Large comment:'
# Should print ERROR: Bad Comment Line (largeComment.pgm) and return 4
./pgmReduce largeComment_A.pgm 5 reduced.pgm
echo $?
./pgmReduce largeComment_B.pgm 5 reduced.pgm
echo $?

printf "\n"
echo '68. Bad dimensions (-1):'
# Should print ERROR: Bad Dimensions (badDimensionLower.pgm) and return 5
./pgmReduce badDimensionLower_A.pgm 5 reduced.pgm
echo $?

printf "\n"
echo '69. Bad dimensions (65536):'
# Should print ERROR: Bad Dimensions (badDimensionHigher.pgm) and return 5
./pgmReduce badDimensionHigher_A.pgm 5 reduced.pgm
echo $?

printf "\n"
echo '70. Bad max gray value:'
# Should print ERROR: Bad Max Gray Value (badMaxGray_A.pgm) and return 6
./pgmReduce badMaxGray_A.pgm 5 reduced.pgm
echo $?

printf "\n"
echo '71. Too little data:'
# Should print ERROR: Bad Max Gray Value (tooLittleData_A.pgm) and return 8
./pgmReduce tooLittleData_A.pgm 5 reduced.pgm
echo $?

printf "\n"
echo '72. Too much data:'
# Should print ERROR: Bad Data (tooMuchData_A.pgm) and return 8
./pgmReduce tooMuchData_A.pgm 5 reduced.pgm
echo $?

printf "\n"
echo '73. Negative scaling factor:'
# Should print ERROR: Bad Data (tooMuchData_A.pgm) and return 8
./pgmReduce input_6x6_A.pgm -5 reduced.pgm
echo $?

printf "\n"
echo '74. Non Numeric scaling factor:'
# Should print ERROR: Bad Data (tooMuchData_A.pgm) and return 8
./pgmReduce input_6x6_A.pgm a reduced.pgm
echo $?

printf "\n"
echo '75. Non Divisible scaling factor:'
# Should print ERROR: Bad Data (tooMuchData_A.pgm) and return 8
./pgmReduce input_6x6_A.pgm 5 reduced.pgm
echo $?

# Correct format
printf "\n"
echo '76. Correct format, file being reduced:'
# Should print REDUCED and output reduced file
./pgmReduce input_6x6_A.pgm 2 reducedAscii_6x6_2.pgm
echo $?
./pgmReduce input_6x6_A.pgm 3 reducedAscii_6x6_3.pgm
echo $?
./pgmReduce input_4x4_A.pgm 2 reducedAscii_4x4_2.pgm
echo $?


# **************************** TESTS FOR PGMTILE *******************************


printf "\n"
echo '************TESTS FOR PGMTILE************'
printf "\n"
echo '77. No arguments provided:'
# Should print Usage: ./pgmTile inputImage.pgm tiling_factor outputImage_<row>_<column>.pgm and return 0
./pgmTile
echo $?

printf "\n"
echo '78. Wrong number of arguments:'
# Should print ERROR: Bad Argument Count and return 1
./pgmTile inputImage.pgm tiling_factor
echo $?

printf "\n"
echo '79. Bad filename:'
# Should print ERROR: Bad File Name (badFilename.pgm) and return 2
./pgmTile badFilename.pgm 3 "outputImage_<row>_<column>.pgm"
echo $?

printf "\n"
echo '80. Non-Readable file:'
# Should print ERROR: Bad File Name (badFilename.pgm) and return 2
./pgmTile badFilename.pgm 3 "outputImage_<row>_<column>.pgm"
echo $?

printf "\n"
echo '81. Bad magic number:'
# Should print ERROR: Bad Magic Number (badMagicNumber.pgm) and return 3
./pgmTile badMagicNumber.pgm 3 "outputImage_<row>_<column>.pgm"
echo $?

printf "\n"
echo '82. Large comment:'
# Should print ERROR: Bad Comment Line (largeComment.pgm) and return 4
./pgmTile largeComment_A.pgm 3 "outputImage_<row>_<column>.pgm"
echo $?
./pgmTile largeComment_B.pgm 3 "outputImage_<row>_<column>.pgm"
echo $?

printf "\n"
echo '83. Bad dimensions (-1):'
# Should print ERROR: Bad Dimensions (badDimensionLower.pgm) and return 5
./pgmTile badDimensionLower.pgm 3 "outputImage_<row>_<column>.pgm"
echo $?

printf "\n"
echo '84. Bad dimensions (65536):'
# Should print ERROR: Bad Dimensions (badDimensionHigher.pgm) and return 5
./pgmTile badDimensionHigher.pgm 3 "outputImage_<row>_<column>.pgm"
echo $?

printf "\n"
echo '85. Bad max gray value:'
# Should print ERROR: Bad Max Gray Value (badMaxGray_A.pgm) and return 6
./pgmTile badMaxGray_A.pgm 3 "outputImage_<row>_<column>.pgm"
echo $?

printf "\n"
echo '86. Too little data:'
# Should print ERROR: Bad Max Gray Value (tooLittleData_A.pgm) and return 8
./pgmTile tooLittleData_A.pgm 3 "outputImage_<row>_<column>.pgm"
echo $?

printf "\n"
echo '87. Too much data:'
# Should print ERROR: Bad Data (tooMuchData_A.pgm) and return 8
./pgmTile tooMuchData_A.pgm 3 "outputImage_<row>_<column>.pgm"
echo $?

printf "\n"
echo '88. Negative tiling factor:'
# Should print ERROR: Miscellaneous (Negative Tiling Factor) and return 100
./pgmTile input_6x6_A.pgm -3 "outputImage_<row>_<column>.pgm"
echo $?

printf "\n"
echo '89. Non Numeric tiling factor:'
# Should print ERROR: Miscellaneous (Non Numeric Tiling Factor) and return 100
./pgmTile input_6x6_A.pgm a "outputImage_<row>_<column>.pgm"
echo $?

printf "\n"
echo '90. Non Divisible tiling factor:'
# Should print ERROR: Miscellaneous (Non Divisible Tiling Factor) and return 100
./pgmTile input_6x6_A.pgm 5 "outputImage_<row>_<column>.pgm"
echo $?

printf "\n"
echo '91. Bad Template:'
# Should print ERROR: Miscellaneous (Bad Template) and return 100
./pgmTile input_6x6_A.pgm 3 "outputImage_<column>.pgm"
echo $?

# Correct format
printf "\n"
echo '92. Correct format, Image being tiled:'
./pgmTile input_6x6_A.pgm 2 "outputImage_<row>_<column>.pgm"
echo $?


# ************************** TESTS FOR PGMASSEMBLE *****************************


printf "\n"
echo '************TESTS FOR PGMASSEMBLE************'
printf "\n"
echo '93. No arguments provided:'
# Should print Usage: ./pgmAssemble outputImage.pgm width height (row column inputImage.pgm)+ and return 0
./pgmAssemble
echo $?

printf "\n"
echo '94. Wrong number of arguments:'
# Should print ERROR: Bad Argument Count and return 1
./pgmAssemble
echo $?

printf "\n"
echo '95. Bad filename:'
# Should print ERROR: Bad File Name (badFilename.pgm) and return 2
./pgmAssemble output.pgm 2 2 0 0 badFilename.pgm 0 1 inputAscii.pgm
echo $?

printf "\n"
echo '96. Non-Readable file:'
# Should print ERROR: Bad File Name (badFilename.pgm) and return 2
./pgmAssemble output.pgm 2 2 0 0 badFilename.pgm 0 1 inputAscii.pgm
echo $?
