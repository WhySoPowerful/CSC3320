#!/bin/bash

#========================================================================================
#
# Description: Displays the man entry for the command from mandatabase
#
# Usage      : ./helpme.sh
#
#========================================================================================

# man database file (specify if yours is different)
mandatabase="mandatabase.txt"

# Take input from the user
echo -n "Enter the command for which help is needed: "
read command

# A man page for any command starts with COMMAND(1)
# (in uppercase letters, in the beginning of line) and ends with COMMAND(1)
# (in uppercase letters, at the end of line), hence the following 'sed' is used to get
# the man entry for the command and display it page by page using 'more'

# Convert user input to uppercase
command=$(echo "$command" | tr a-z A-Z)

# Find the man entry from the mandatabase or display a message
if [ -n "$(sed -n "/^$command(1)/,/$command(1)$/p" "$mandatabase" | more)" ]
then
    sed -n "/^$command(1)/,/$command(1)$/p" "$mandatabase" | more
else
    echo "Sorry, I cannot help you"
fi

exit 0
