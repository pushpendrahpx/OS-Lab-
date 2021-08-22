#! /bin/bash

sets=(1 3 4 5 2 5 2 6 94 2 5 2 9)


for ((i=0; i < ${#sets[@]}; i++))
do

    for((j=0; j < ${#sets[@]}; j++))
    do
        if [ ${sets[$i]} -gt ${sets[$j]} ]
        then
            tmp=${sets[$i]}
            sets[$i]=${sets[$j]}
            sets[$j]=$tmp
        fi

    done

done



for i in ${sets[@]}
    do  
        echo -n "$i "
done

