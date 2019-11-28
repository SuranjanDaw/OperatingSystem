ls -l |grep ^-| tr -s ' '| cut -d ' ' -f9| grep ^[AEIOUaeiou] > vowel
cat vowel
