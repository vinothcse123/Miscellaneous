#!/usr/bin/bash

#while loop

a=10

while [ $a -gt 5 ]
do
   echo $a
   a=`expr $a - 1`
#a=$((a-1)) Doesnot work on many shells
done


a=10

#for loop

echo "Demo of for loop"

for V_OUTER_VAR in 10 20 30
do
   for V_INNER_VAR in 40 50
   do
     echo "Iter: $V_OUTER_VAR $V_INNER_VAR"
     if [ $V_OUTER_VAR -eq 10 -a $V_INNER_VAR -eq 40 ]; then
         echo "Breaking..."
         break 2 # breaks two loops
     fi
   done
done




