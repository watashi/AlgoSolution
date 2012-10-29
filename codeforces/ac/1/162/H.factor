USING: io kernel ascii sequences ;

t
readln [
    swap [ ch>upper f ] [ ch>lower t ] if swap
] map
print drop
