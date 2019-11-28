echo enter number
read m
sum=0
for(( i=$m;i>0;i=$i/10 ))
do
  m=`expr $i % 10`
  sum=`expr $m + $sum`
done
echo sum is $sum
