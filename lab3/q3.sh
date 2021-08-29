#! /bin/bash
echo "Number of files in $1 directory is "
ls $1 -Ap | grep -v /$ | wc -l
# ls 