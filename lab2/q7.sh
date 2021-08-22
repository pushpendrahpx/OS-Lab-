#! /bin/bash

sets=(11 1 1 1 1 1)

sum=0

for ((i=0; i < ${#sets[@]}; i++))
do
    sum=$(($sum+${sets[$i]}))
done


echo "sum is $sum"
