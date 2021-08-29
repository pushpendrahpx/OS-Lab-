#! /bin/bash

if [ -f $1 ]
    then
        echo "You entered a file's name"
elif [ -d $1 ]
    then 
        echo "You entered a Directory's name"
else
    echo "You entered something else"
fi
