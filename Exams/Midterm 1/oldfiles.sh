#!/bin/bash

#===================================================================================
#
# Description: Finds the files in user's home directory that have not been accessed
#              for N days and compresses them
#
#
# Usage      : ./oldfiles.sh
#
#===================================================================================

# Take user input
echo -n "Enter the number of days the files are not accessed: "
read days

# Find the files not been accessed in 'days' and compress them
# The diagnostic output is redirected to avoid printing errors in case the file
# owner is not the current user
zip "${days}_old_access.zip" $(find $HOME -atime +"$days" -type f 2>/dev/null)

# Display the message specifying the name of the compressed file created
echo "Created a compressed (zip) file of the old accessed files with the name ${days}_old_access.zip"

exit 0
