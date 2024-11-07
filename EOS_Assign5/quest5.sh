#!/bin/bash

echo -n -e "Enter the 1st number:"
read n1

echo -n -e "Enter the 2nd number:"
read n2

echo -n -e "Enter the 3rd number:"
read n3

if [ $n1 -gt $n2 ]
then
	if [ $n1 -gt $n3 ]
	then
		echo "$n1 is the greatest number!"
	else 
		echo "$n3 is the greatest number!"
	fi
else
	if [ $n2 -gt $n3 ]
	then
		echo "$n2 is the greatest."
	else
	        echo "$n3 is the greatest."
       fi
fi       

	
