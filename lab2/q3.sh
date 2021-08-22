#! /bin/bash

i="y" # for the first time

while [ $i = "y" ] 
do
echo "Shell Calculator"
echo "1. Addition
2. Subtraction
3. Multiplication
4. Division
5. Modulo"
read -p "Please Enter your choice : " choice

if [ $choice = 1 ]
    then
        read -p "Please enter [num1] [num2] : " num1 num2
        num3=$(($num1+$num2))
        echo "result $num1 + $num2 = $num3"

elif [ $choice = 2 ]
    then
        read -p "Please enter [num1] [num2] : " num1 num2
        num3=$(($num1-$num2))
        echo "result $num1 - $num2 = $num3"

elif [ $choice = 3 ]
    then
        read -p "Please enter [num1] [num2] : " num1 num2
        num3=$(($num1*$num2))
        echo "result $num1 * $num2 = $num3"

elif [ $choice = 4 ]
    then
        read -p "Please enter [num1] [num2] : " num1 num2
        num3=$(($num1/$num2))
        echo "result $num1 / $num2 = $num3"

elif [ $choice = 5 ]
    then
        read -p "Please enter [num1] [num2] : " num1 num2
        num3=$(($num1%$num2))
        echo "result $num1 % $num2 = $num3"

fi


# user want to continue same again ? lets ask him/her...
read -p "Wanna do one more time? [ y/n ]: " i
if [ $i != "y" ]
then
exit
fi

done