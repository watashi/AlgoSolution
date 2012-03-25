USING: io kernel math math.parser math.ranges sequences shuffle rpn ;

100 { } new-resizable
readln string>number
2 10000 [a,b] [
    [ 2dup mod zero? ] [ dup -rot / -rot 2dup swap push swapd ] while drop
] each
drop [ number>string ] map "*" join print
