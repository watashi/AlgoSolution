USING: io kernel sequences math math.parser math.primes ;

"YES"
readln
[ dup empty? not ] [
    dup string>number prime?
    [ ] [ nip "NO" swap ] if
    rest
] while
drop print
