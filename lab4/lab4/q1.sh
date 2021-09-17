#! /bin/bash

d=$(date +%H)
if [[ $d -lt 12  && $d -gt 4 ]]; then

    echo "Good Morning";

elif [[ $d -lt 16  && $d -gt 11 ]]; then

    echo "Good Afternoon";


elif [[ $d -lt 22  && $d -gt 15 ]]; then

    echo "Good Evening";

fi
