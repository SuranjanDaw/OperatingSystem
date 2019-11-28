echo enter first number
read n1
div=$(($n1 % 2))
if [ $div -eq 0 ]; then
  echo $n1 is even
elif [ $div -ne 0 ]; then
  echo $n1 is odd
fi
