#!/bin/bash
declare -i FLIP=$(($RANDOM%2))

if (( $FLIP==1 ));then
	echo -ne '\007' 
	cat heads.txt
	echo "heads"
else
	echo -ne '\007'
	cat tails.txt
	echo "tails"
fi















