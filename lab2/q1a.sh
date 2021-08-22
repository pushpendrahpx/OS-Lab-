#! /bin/bash

read -p "Please Enter Number 1 : " num1
read -p "Please Enter number 2 : " num2
num3=$(($num1+$num2)) # expressions
echo "Addition ($num1 + $num2) = $num3"