#!/bin/bash

for kk in $(ls)
do
	if [ -f $kk ]
	then
		echo $kk is a file
	else
		echo $kk is dir
	fi
done
	
