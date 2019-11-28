if [ $# -ne 2 ]; then
  echo Input files absent
else
  ls $1 > temp
  while read line
  do
    ls $2 | grep $line> temp1
    if [ -s temp1 ]; then
      cat temp1
      rm $2/$line
    fi
    echo x=$line
  done < temp
fi
