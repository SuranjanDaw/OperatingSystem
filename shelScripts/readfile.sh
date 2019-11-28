filename=$1
count=0
while read line
do
  let count++
  echo count:$count::$line
done < $filename
echo -e '\n Number of lines read is '$count
