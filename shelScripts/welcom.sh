echo welcome::$USER
echo name ::$LOGNAME
echo $(date)
set `date`
echo para--$1:: para2--$2::para3--$3::para4--$4::para5--$5::para6--$6::
last $LOGNAME | head -5 | tr -s ' '| cut -d ' ' -f4-11
