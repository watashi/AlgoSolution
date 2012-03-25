USING: io kernel math math.parser ;

0
readln string>number
[ dup zero? not ] [ 5 /i dup swapd + swap ] while drop
number>string print
