#!/usr/bin/tclsh
set re [gets stdin]
while {$re > 0} {
    incr re -1
    set n [gets stdin]
    set m [expr int(sqrt($n))]
    while {$n % $m} {
        incr m -1
    }
    set n [expr $n / $m]
    puts [expr $n - $m]
}
# Time limit exceeded
