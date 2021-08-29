#! /bin/bash

read -p "Please enter a number : " number
if [[ $number =~ ^[0-9] ]]
    then
        i=0;
        j=1;
        k=1;
        echo $i;
        count=2;
        while (($count <= $number))
        do
        
        k=$(($i+$j));
        j=$i;
        i=$k;
        ((count++))


        echo "$i "

        done;

    # echo Result is $output

fi