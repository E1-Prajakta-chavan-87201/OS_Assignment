#!/bin/bash

echo -n -e "Enter a number: "
read num

if [ $num -ge 0 ]
then
	echo "$num is positive!"
else
	if [ $num -lt 0 ]
	then
	       echo "$num is negative!"
	fi
fi	

