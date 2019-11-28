echo enter first number
read n1
echo enter second number
read n2

if [ $n1 -gt $n2 ]
then
  echo $n1 is greater
elif [ $n1 -lt $n2 ]
then
  echo $n2 is greater
else
  echo both have same value $n2 = $n1
fi
