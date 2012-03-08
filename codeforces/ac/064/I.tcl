proc cmp {a b} {
	global rules
	foreach rule $rules {
		set field [lindex $rule 0]
		set order [lindex $rule 1]
		set cmp [string compare [lindex $a $field] [lindex $b $field]]
		if {$cmp < 0} {
			return [expr {$order == "ASC" ? -1 : 1}]
		} elseif {$cmp > 0} {
			return [expr {$order == "ASC" ? 1 : -1}]
		}
	}
	return 0
}

gets stdin line
set fields [split $line]
gets stdin line
foreach rule [split $line ,] {
	scan $rule " %s %s" field order
	lappend rules [list [lsearch $fields $field] $order]
}

while true {
	gets stdin line
	if {$line == ""} {
		break
	}
	lappend records [split $line]
}

foreach record [lsort -command cmp $records] {
	puts stdout [join $record]
}
