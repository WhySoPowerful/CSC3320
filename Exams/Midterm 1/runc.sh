#!/bin/bash

#==============================================================================
#
# Description: Runs the C programs
#
# Usage      : ./runc.sh integer
#
#==============================================================================

if [ "$#" -ne 1 ]
then
    echo "Usage: $0 integer"
    exit 1
fi

arg="$1"

./factorial "$arg"
./shift "$arg"

exit 0
