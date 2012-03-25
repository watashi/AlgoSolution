USING: io kernel math math.parser ;

2
readln string>number
[ 2 /mod swap dup zero? not ] loop drop
[ number>string write dup 2 number= not ] loop drop
nl
