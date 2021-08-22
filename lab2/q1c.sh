#! /bin/bash

args=("$@")
n1=${args[0]}
n2=${args[1]}
n3=$(($n1+$n2))
echo $n3
