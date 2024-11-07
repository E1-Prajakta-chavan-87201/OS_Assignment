#!/bin/bash

echo "Enter the name"
read path

if [ -e $path ]
then
	if [ -d $path ]
	then
		echo "File is directory!"
		
		cd $path
		ls -S
	fi

	if [ -f $path ]
	then
		echo "Regular file."
                du -sh $path
		
	fi
else
	echo "File doesn't exist"
fi
