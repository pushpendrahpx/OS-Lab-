#! /bin/bash

read -p "Please enter a upper number : " number
if [[ $number =~ ^[0-9] ]]
    then
        i=0;
        while (($i <= $number))
        do
        
        echo "$i "
        i=$(($i+2))


        done;

    # echo Result is $output

fi