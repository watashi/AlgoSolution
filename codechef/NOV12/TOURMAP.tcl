#!/usr/bin/tclsh

set re [gets stdin]
for {set ri 1} {$ri <= $re} {incr ri} {
  set s 0
  set v {}
  set e {}
  set n [gets stdin]
  for {set i 1} {$i < $n} {incr i} {
    set line [gets stdin]
    scan $line "%s%s%d" a b c
    incr s $c
    dict set v $a 1
    dict set v $b 1
    dict set e $a [list $b $line]
  }

  dict for {i j} $e {
    dict unset v [lindex $j 0]
  }

  set v [dict keys $v]
  for {set i 1} {$i < $n} {incr i} {
    set j [dict get $e $v]
    set v [lindex $j 0]
    puts [lindex $j 1]
  }
  puts "$s$"
}

#Correct Answer
#Execution Time: 2.47

