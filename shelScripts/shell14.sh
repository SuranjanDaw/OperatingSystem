echo $1
echo enter
read word
grep ^$word $1 > temp4
cat temp4
