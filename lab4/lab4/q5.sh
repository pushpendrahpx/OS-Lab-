#! /bin/bash

echo "usage [ ./q5.sh <Directory Address> ] "

find $1 -type f -mmin -600 -ls