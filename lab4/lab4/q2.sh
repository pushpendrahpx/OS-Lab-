#! /bin/bash

n=$(grep -cx '\s*' $1)
((n++))
echo $n