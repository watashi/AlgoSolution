gets stdin line
set a [split $line]
set b [lsort -integer -indices $a]
set c {-1 -1 -1}
foreach i {0 1 2} {
	lset c [lindex $b $i] [expr 3 - $i]
}
puts stdout [join $c]
