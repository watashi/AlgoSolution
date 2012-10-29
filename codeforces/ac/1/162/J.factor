USING: io kernel math sequences system ;

0
readln [
    40 number= [ 1 + ] [ 1 - ] if
    dup 0 < [ 1 - ] [ ] if
] each
zero? [ "YES" ] [ "NO" ] if print
