
if [ $# -ne  0 ]; then
   ls -l $1 |tr -s ' ' | cut -d ' ' -f6,7,8,9
elif [ $# -eq 0 ]; then
  echo file not provided
fi
