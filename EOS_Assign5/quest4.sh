
#!/bin/bash

echo -n -e "Enter the number:"
read n1

flag=0
i=2

while [ $i -lt $n1 ]
do
     if [ `expr $n1 % $i` -eq 0 ]
     then
             flag=1
     fi
     i=`expr $i + 1`
done
     if [ $flag -eq 0 ]
     then
	     echo "Prime number"
     else
	     echo "Not a prime number."
     fi
