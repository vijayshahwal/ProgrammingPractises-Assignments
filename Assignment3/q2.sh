#! /bin/bash

n=5
arr=(10 8 20 100 12) 

echo "Orignal array is: ${arr[*]}"
for (( i = 0; i < $n-1; i++ ))
do
    for ((j = 0; j < $n-1-$i; j++ ))
    do
        if [[ ${arr[$j]} -gt ${arr[$j+1]} ]]
        then
            temp=${arr[$j]}
            arr[$j]=${arr[$j+1]}
            arr[$j+1]=$temp
        fi
    done
done
echo "array after sorting: ${arr[*]}"
