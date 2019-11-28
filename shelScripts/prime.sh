read a
n=$(($a / 2))
count=0
for (( i=2;i<$n;i=$i + 1 ))
do
  m=`expr $a % $i`
  if [ $m -eq 0 ]; then
    count=`expr $count + 1`
  fi
done
echo $count
if [ $count -eq 0 ]; then
  echo $a is prime
else
  echo $a is NOT prime
fi
