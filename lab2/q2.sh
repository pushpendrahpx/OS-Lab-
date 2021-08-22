#! /bin/bash

if [ $1 ] && [ $2 ] && [ $3 ]
    then
        echo "Starting ..."
else
    echo "Please provide 3 command line parameters"
    exit
fi

echo -n "larger number is : "
if [ $1 -gt $2 ] && [ $1 -gt $3 ]
    then
        echo $1
elif [ $2 -gt $3 ] && [ $2 -gt $1 ]
    then
        echo $2
else
    echo $3
fi