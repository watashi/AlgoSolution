proc isprime n {
	for {set i 2} {$i * $i <= $n} {incr i} {
		if {$n % $i == 0} {
			return false
		}
	}
	return true
}

gets stdin n
for {set l $n} {![isprime $l]} {incr l -1} {
}
for {set r $n} {![isprime $r]} {incr r} {
}
puts stdout "$l $r"
