gets stdin line
set path {}
foreach dir [split $line /] {
	if {$dir == ".."} {
		set idx [expr [llength $path] - 1]
		set path [lreplace $path $idx $idx]
	} elseif {$dir != "."} {
		lappend path $dir
	}
	if {[llength $path] == 0} {
		puts stdout -1
		exit
	}
}
set path [join $path /]
if {$path == ""} {
	set path /
}
puts stdout $path
