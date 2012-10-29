gets stdin line
puts stdout [expr {[regexp {^([a-z0-9]+\.)*[a-z0-9]{2,3}$} $line] == 1 ? YES : NO}]
