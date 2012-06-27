#!/usr/bin/tclsh
set re [gets stdin]
for {set ri 1} {$ri <= $re} {incr ri} {
    set nc [split [gets stdin]]
    set m 0
    foreach a [split [gets stdin]] {
        incr m $a
    }
    if {$m <= [lindex $nc 1]} {
        puts "Yes"
    } else {
        puts "No"
    }
}
