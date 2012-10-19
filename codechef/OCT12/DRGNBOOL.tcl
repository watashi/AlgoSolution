#!/usr/bin/tclsh

proc readPair {a b} {
  upvar $a x $b y
  set pair [split [gets stdin]]
  set x [lindex $pair 0]
  set y [lindex $pair 1]
}

set re [gets stdin]
for {set ri 1} {$ri <= $re} {incr ri} {
  readPair n m

  set d {}
  for {set i 0} {$i < $n} {incr i} {
    readPair c l
    dict incr d $l -$c
  }
  for {set j 0} {$j < $m} {incr j} {
    readPair c l
    dict incr d $l $c
  }

  set s 0
  dict for {k v} $d {
    if {$v < 0} {
      set v 0
    }
    incr s $v
  }
  puts $s
}

#Correct Answer
#Execution Time: 5.52

