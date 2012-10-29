proc cmp {a b} {
	set a1 [lindex $a 1]
	set b1 [lindex $b 1]
	if {$a1 > $b1} {
		return -1
	} elseif {$a1 < $b1} {
		return 1
	} else {
		return [string compare [lindex $a 0] [lindex $b 0]]
	}
}

gets stdin n
for {set i 0} {$i < $n} {incr i} {
	gets stdin line
	lappend a [split $line]
}
set a [lsort -command cmp $a]
for {set i 0} {$i < $n} {set i $j} {
	for {set j $i} {$j < $n && [lindex [lindex $a $i] 1] == [lindex [lindex $a $j] 1]} {incr j} {
	}
	for {set k $i} {$k < $j} {incr k} {
		if {$i + 1 == $j} {
			puts stdout "$j [lindex [lindex $a $k] 0]"
		} else {
			puts stdout "[expr $i + 1]-$j [lindex [lindex $a $k] 0]"
		}
	}
}
