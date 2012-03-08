gets stdin line
set tokens [split $line]
set n [lindex $tokens 0]
set m [lindex $tokens 1]
set p [lindex $tokens 2]
incr p -1
set i [expr $p % $n]
set j [expr $p / $n]
puts stdout [expr $i * $m + $j + 1]
