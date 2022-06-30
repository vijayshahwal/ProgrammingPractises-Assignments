#!/bin/bash
limit=5 # seconds to wait for timeout
file=$1
timeout=$(awk "BEGIN{srand(); print srand() + $limit}")
echo $timeout
until [ -s "$file" ] || [ $(awk "BEGIN{srand();print srand()}") -gt $timeout ]
do
	sleep 1
done
if ! [ -s "$file" ]
then
	# timed-out
	exit 1
else
	cat $file
fi
