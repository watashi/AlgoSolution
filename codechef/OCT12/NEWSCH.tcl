#!/usr/bin/tclsh

set mod 1000000007
set bin {}

proc mul {a b} {
  global mod
  set c {{0 0} {0 0}}
  foreach i {0 1} {
    foreach j {0 1} {
      set t 0
      foreach k {0 1} {
        incr t [expr [lindex $a $i $k] * [lindex $b $k $j]]
      }
      lset c $i $j [expr $t % $mod]
    }
  }
  return $c
}

proc init {a} {
  global bin
  lappend bin {{1 0} {0 1}}
  lappend bin $a
  for {set i 2} {$i < 32} {incr i} {
    lappend bin [mul [lindex $bin end] [lindex $bin end]]
  }
}

proc power {b} {
  global bin
  set c [lindex $bin 0]
  for {set i 1} {$i < 32 && $b > 0} {incr i} {
    if {$b % 2 > 0} {
      set c [mul $c [lindex $bin $i]]
    }
    set b [expr $b / 2]
  }
  return $c
}

set re [gets stdin]
init {{0 1} {3 2}}
for {set ri 1} {$ri <= $re} {incr ri} {
  set n [gets stdin]
  incr n -1
  set y [power $n]
  puts [expr 4 * [lindex $y 1 0] % $mod]
}

#Correct Answer
#Execution Time: 2.99

