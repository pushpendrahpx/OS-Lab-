#! /bin/bash

read -p "Please enter a number : " number
if [[ $number =~ ^[0-9] ]]
    then
        i=1;
        output=1;
        while (($i <= $number))
        do

        output=$(($output*$i))
        ((i++))




        done;

    echo Result is $output

fi