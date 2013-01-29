#!/usr/bin/bash

function count {
  for c in {a..z}
  do
    s=${1//[!$c]/}
    echo ${#s}
  done
}

function beauty {
  for i in `seq 26`
  do
    echo $i
  done
}

read re
for ri in `seq $re`
do
  read s
  ans=`paste -d '*' <(count "${s,,}" | sort -n) <(beauty) | paste -s -d '+' | bc`
  echo "Case #$ri: $ans"
done
