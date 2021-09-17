#! /bin/bash
allfiles=$(find . -type f -exec ls -al {} \; | sort -k 5 -n -r | sed 's/ \+/\t/g' | cut -f 9)

echo ' usage ./q3.sh [sizelargerthan]'

for filename in $allfiles
do

    echo "size of $filename = $(stat --printf="%s\n" $filename)";
done;