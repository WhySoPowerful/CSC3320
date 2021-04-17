#!/bin/bash

#========================================================================================
#
# Description: Finds the number of occurrences of a particular keyword
#
# Usage      : ./wordsearch.sh
#
#========================================================================================

# Wikipedia file location
examfile="myexamfile.txt"

# Take user input
echo -n "Enter a keyword to search: "
read keyword

# Find the number of occurrences of the keyword in the file
grep -o "$keyword" "$examfile" | wc -l

exit 0
