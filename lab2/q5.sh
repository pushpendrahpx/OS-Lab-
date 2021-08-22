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

case $choice in
1)  read -p "Please enter [num1] [num2] : " num1 num2
    num3=$(($num1+$num2))
    echo "result $num1 + $num2 = $num3"
    ;;
2)  read -p "Please enter [num1] [num2] : " num1 num2
    num3=$(($num1-$num2))
    echo "result $num1 - $num2 = $num3"
    ;;
3)  read -p "Please enter [num1] [num2] : " num1 num2
    num3=$(($num1*$num2))
    echo "result $num1 * $num2 = $num3"
    ;;
4)  read -p "Please enter [num1] [num2] : " num1 num2
    num3=$(($num1/$num2))
    echo "result $num1 / $num2 = $num3"
    ;;
5)  read -p "Please enter [num1] [num2] : " num1 num2
    num3=$(($num1%$num2))
    echo "result $num1 % $num2 = $num3"
    ;;
*) echo " -- Please Enter correct choice --"
    ;;
esac


# user want to continue same again ? lets ask him/her...
read -p "Wanna do one more time? [ y/n ]: " i
if [ $i != "y" ]
then
exit
fi

done