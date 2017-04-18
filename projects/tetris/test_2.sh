#!/bin/bash

MAX=60
ARR=( $(eval echo {1..${MAX}}) )

for i in ${ARR[*]} ; do 
    # delete from the current position to the start of the line
    printf "\e[2K"
    # print '[' and place '=>' at the $i'th column
    printf "[\e[%uC=>" ${i}
    # place trailing ']' at the ($MAX+1-$i)'th column
    printf "\e[%uC]" $((${MAX}+1-${i}))
    # print trailing '100%' and move the cursor one row up
    printf " 100%% \e[1A\n"
    sleep 0.1
done
printf "\n"
