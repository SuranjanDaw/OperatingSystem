count=0
while read line
do
  size=`echo $line |tr -s ' '|cut -d ' ' -f1`
  if [ -z $size ]; then
    echo 'field is null'
  elif [ $size -gt 100 ]; then
    echo `echo $line`
    count=`expr $count + 1`
  fi
done < $1
if [ $count -ne 0 ]; then
echo number of lines is $count
else
  echo No  such file
fi
