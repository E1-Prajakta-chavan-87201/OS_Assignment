#!/bin/bash

echo -n -e "Enter the year"
read year

if [ `expr $year % 4` -eq 0 -a `expr $year % 100` -ne 0 -o `expr $year % 400` -eq 0 ]
then
	echo "$year is a leap year!"
else
	echo "$year is not a leap year!"
fi
