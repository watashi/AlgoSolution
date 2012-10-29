USING: io kernel math math.parser ascii sequences strings ;

readln string>number
readln string>number
swap
iota [
    drop
    readln [ dup digit? [ 48 - ] [ 55 - ] if ] map
    0 [ pick rot * + ] reduce
] map
sum

100 "" new-resizable
[ over zero? not ] [
    2over swap mod
    dup 10 < [ 48 + ] [ 55 + ] if
    over push
    swap pick /i swap
] while
dup empty? [ 48 over push ] [ ] if
reverse >string print
2drop
