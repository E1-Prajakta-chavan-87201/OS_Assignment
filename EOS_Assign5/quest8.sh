#!/bin/bash

echo -n -e "Enter the number: "
read num



i=1
while [ $i -le 10 ]
do
	res=`expr $i \* $num`
	echo "$num * $i = $res"

	i=`expr $i + 1`
done
