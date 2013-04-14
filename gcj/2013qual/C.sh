#!/usr/bin/zsh

read re
for ri in `seq $re`
do
  read a b
  c=0
  for i in `seq 50`
  do
    j=`echo $i | rev`
    if [ $i = $j ]
    then
      ((s=i*i))
      t=`echo $s | rev`
      if [ $a -le $s -a $s -le $b -a $s = $t ]
      then
        ((c=c+1))
      fi
    fi
  done
  echo "Case #$ri: $c"
done
