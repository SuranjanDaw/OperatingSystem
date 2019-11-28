ls -l | grep ^-| tr -s ' '| cut -d ' ' -f5,9 > temp5
sum=0
while read line
do
  size=`echo $line | tr -s ' '| cut -d ' ' -f1`
  name=`echo $line | tr -s ' '| cut -d ' ' -f2`
  echo Name is $name
  sum=`expr $sum + $size`
done < temp5

echo total size is $sum
