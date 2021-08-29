#! /bin/bash

echo "Number of lines : "
wc $1 -l
echo "Number of word : "
wc $1 -w
echo "Number of characters : "
wc $1 -c
