#!/bin/bash

#========================================================================================
#
# Description: Manages phone directory
#              1. Displays entries sorted on last name
#              2. Adds a new entry
#              3. Modifies an entry
#              4. Deletes an entry
#
#              Accepts a phone lists as an argument
#
# Usage      : ./phonemgr
#
#========================================================================================

# Phonebook filename
infile="phonebook.txt"

#----------------------------------------------------------------------------------------

# Displays menu
menu()
{
  echo ""
  echo "================================="
  echo "     Phone Directory Manager     "
  echo "================================="
  echo "1.   Display phone directory"
  echo "2.   Find people"
  echo "3.   Add a new entry"
  echo "4.   Modify an entry"
  echo "5.   Delete an entry"
  echo "6.   Exit"
  echo ""
}

#----------------------------------------------------------------------------------------

# Create a phone directory file with read/write permissions to user only
touch "$infile"
chmod 600 "$infile"

clear

# User input validation and processing
while [ "$option" != "6" ]
do
     # Reset variables
     fname=""
     lname=""
     phone=""
     address=""

     oldfname=""
     oldlname=""
     oldphone=""
     oldaddress=""

     newfname=""
     newlname=""
     newphone=""
     newaddr=""

     case "$option" in
      1)
         if [ -s "$infile" ]
         then
             echo ""
             echo "Phone Directory sorted on Last Name (second column)"
             echo ""

             # Sort on lastname
             sort -t":" -k2 "$infile" | column -s: -t | more
         else
             echo ""
             echo "No phone directory '$infile' found"
         fi

         menu
         echo -n "Enter option [1-6]: "
         read option
         continue
         ;;
      2) # Check if file is available and is readable
         if [ ! -r "$infile" ]
         then
             echo ""
             echo "Error: You're not allowed to read '$infile'"
             echo ""

             exit 1
         fi

         echo ""

         while [ -z "$fname" ]
         do
             echo -n "Enter First Name (Type exit to end): "
             read fname

             if [ "$fname" = "exit" ]
             then
                 exit 0
             fi
         done

         while [ -z "$lname" ]
         do
             echo -n "Enter Last Name (Type exit to end) : "
             read lname

             if [ "$lname" = "exit" ]
             then
                 exit 0
             fi
         done

         # Remove extra spaces, if any
         fname=$(echo "$fname" | tr -s ' ')
         lname=$(echo "$lname" | tr -s ' ')

         echo ""
         entry=$(grep -iw "$fname:$lname" "$infile")

         # Display message if no match found
         if [ -z "$entry" ]
         then
             echo "Info: No match found"

             menu
             echo -n "Enter option [1-6]: "
             read option
             continue
         else
             echo "$entry"
         fi

         menu
         echo -n "Enter option [1-6]: "
         read option
         continue
         ;;
      3) # Check if file is writable
         if [ ! -w "$infile" ]
         then
             menu
             echo "Error: You're not allowed to write into $infile"
             echo ""

             exit 1
         fi

         echo ""

         while [ -z "$fname" ]
         do
             echo -n "Enter First Name (Type exit to end): "
             read fname

             if [ "$fname" = "exit" ]
             then
                 exit 0
             fi
         done

         while [ -z "$lname" ]
         do
             echo -n "Enter Last Name (Type exit to end) : "
             read lname

             if [ "$lname" = "exit" ]
             then
                 exit 0
             fi
         done

         while [ -z "$phone" ]
         do
             echo -n "Enter phone# (Type exit to end)    : "
             read phone

             if [ "$phone" = "exit" ]
             then
                 exit 0
             fi
         done

         while [ -z "$address" ]
         do
             echo -n "Enter address (Type exit to end)     : "
             read address

             if [ "$address" = "exit" ]
             then
                 exit 0
             fi
         done

         echo "$fname:$lname:$phone:$address" >> "$infile"
         echo ""
         echo "Info: New phone added"

         menu
         echo -n "Enter option [1-6]: "
         read option

         continue
         ;;
      4) # Check if file is writable
         if [ ! -w "$infile" ]
         then
             echo ""
             echo "Error: You're not allowed to write into $infile"
             echo ""

             exit 1
         fi

         echo ""

         while [ -z "$oldfname" ]
         do
             echo -n "Enter old First Name (Type exit to end): "
             read oldfname

             if [ "$oldfname" = "exit" ]
             then
                 exit 0
             fi
         done

         while [ -z "$oldlname" ]
         do
             echo -n "Enter old Last Name (Type exit to end) : "
             read oldlname

             if [ "$oldlname" = "exit" ]
             then
                 exit 0
             fi
         done

         echo ""

         while [ -z "$newfname" ]
         do
             echo -n "Enter new First Name (Type exit to end): "
             read newfname

             if [ "$newfname" = "exit" ]
             then
                 exit 0
             fi
         done

         while [ -z "$newlname" ]
         do
             echo -n "Enter new Last Name (Type exit to end) : "
             read newlname

             if [ "$newlname" = "exit" ]
             then
                 exit 0
             fi
         done

         while [ -z "$newphone" ]
         do
             echo -n "Enter new phone# (Type exit to end)    : "
             read newphone

             if [ "$newphone" = "exit" ]
             then
                 exit 0
             fi
         done

         while [ -z "$newaddr" ]
         do
             echo -n "Enter new address (Type exit to end)   : "
             read newaddr

             if [ "$newaddr" = "exit" ]
             then
                 exit 0
             fi
         done

         # Remove extra spaces, if any
         oldfname=$(echo "$oldfname" | tr -s ' ')
         oldlname=$(echo "$oldlname" | tr -s ' ')

         echo ""
         oldentry=$(grep -iw "$oldfname:$oldlname" "$infile")
         newentry="$newfname:$newlname:$newphone:$newaddr"

         # Display message if no match found
         if [ -z "$oldentry" ]
         then
             echo "Info: No match found"

             menu
             echo -n "Enter option [1-6]: "
             read option
             continue
         else
             sed -i "s/$oldentry/$newentry/" "$infile"
             echo "Info: Modified phone"
         fi

         menu
         echo -n "Enter option [1-6]: "
         read option
         continue
         ;;
      5) echo ""
         while [ -z "$fname" ]
         do
             echo -n "Enter First Name (Type exit to end): "
             read fname

             if [ "$fname" = "exit" ]
             then
                 exit 0
             fi
         done

         while [ -z "$lname" ]
         do
             echo -n "Enter Last Name (Type exit to end) : "
             read lname

             if [ "$lname" = "exit" ]
             then
                 exit 0
             fi
         done

         # Remove extra spaces, if any
         fname=$(echo "$fname" | tr -s ' ')
         lname=$(echo "$lname" | tr -s ' ')

         # Delete line
         tmpfile=$(mktemp)
         grep -iwv "$fname:$lname" "$infile" > "$tmpfile"

         # Check if rows deleted in tmpfile
         orgirowcount=$(wc -l < "$infile")
         tmprowcount=$(wc -l < "$tmpfile")

         if [ "$orgirowcount" -eq "$tmprowcount" ]
         then
             echo ""
             echo "Info: No match found"

             menu
             echo -n "Enter option [1-6]: "
             read option
             continue
         else
             mv "$tmpfile" "$infile"
             echo ""
             echo "Info: Deleted phone"

             menu
             echo -n "Enter option [1-6]: "
             read option

             continue
         fi
         ;;
      6) echo ""
         exit 0
         ;;
      *) menu
         echo -n "Enter option [1-6]: "
         read option
    esac
done

echo ""

exit 0
