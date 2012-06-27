#!/usr/bin/tclsh

set re [gets stdin]
for {set ri 1} {$ri <= $re} {incr ri} {
    set n [gets stdin]
    set m -1
    for {set i 0} {$i < 28 && $i <= $n} {incr i 4} {
        if {($n - $i) % 7 == 0} {
            set m [expr $n - $i]
            break
        }
    }
    puts $m
}

# Correct Answer
# Execution Time: 0.45
