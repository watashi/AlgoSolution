#!/usr/bin/tclsh

proc gao {s} {
    foreach c [split $s {}] {
        dict incr d $c
    }
    return $d
}

set re [gets stdin]
for {set ri 1} {$ri <= $re} {incr ri} {
    set x [gao [gets stdin]]
    set y [gao [gets stdin]]
    set s 0
    dict for {k v} $y {
        if {[dict exists $x $k]} {
            set s [expr $s + $v]
        }
    }
    puts $s
}

#Correct Answer
#Execution Time: 0.55
