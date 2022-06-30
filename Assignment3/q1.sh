#!/bin/bash
function fun(){
	for item in ls "$1"/*
	do
		if [ -d $item ];then
			echo "$items"
			fun "$item"
			((dir=dir+1))
		elif [ -f $item ];then
			names=$(echo $item | cut -f 1 -d '.')
	        	echo "$names"
			((file=file+1))
		fi
	done
}
path=""
file=0
dir=0
if [ -d "$1" ];then
	path=$1
else
	path="/tmp"
fi
echo "base path $path"
fun $path $file $dir
echo "No of files : $file"
echo "No of dirs: $dir"
