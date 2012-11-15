#!/usr/bin/tclsh

set mod 1000000007

proc gcd {a b} {
  if {$b == 0} {
    return [list $a 1 0]
  } else {
    foreach {g x y} [gcd $b [expr {$a % $b}]] {
      return [list $g $y [expr {$x - $a / $b * $y}]]
    }
  }
}

for {set i 1} {$i <= 2500} {incr i} {
  foreach {g x y} [gcd $i $mod] {
    set inv($i) $x
  }
}

proc foo {n m} {
  global mod
  global inv
  set x 1
  set y $x
  for {set i 1} {$n > 0 && $m > 0} {incr i; incr n -1; incr m -1} {
    set x [expr {$x * $n * $m * $inv($i) * $inv($i) % $mod}]
    incr y $x
  }
  return [expr {$y % $mod}]
}

proc bar {n m} {
  global mod
  global inv
  set x [expr {$n + 1}]
  set y $x
  for {set i 1; set j 2} {$n > 0 && $m > 0} {incr i; incr j; incr n -1; incr m -1} {
    set x [expr {$x * $n * $m * $inv($j) * $inv($i) % $mod}]
    incr y $x
  }
  return [expr {$y % $mod}]
}

set re [gets stdin]
for {set ri 1} {$ri <= $re} {incr ri} {
  set s [gets stdin]
  set n [string length $s]
  set four [expr $n - [string length [string map {4 {}} $s]]]
  set seven [expr $n - [string length [string map {7 {}} $s]]]
  set ans 0
  if {$seven == 0} {
    incr ans
  } else {
    incr ans [foo $four [expr $seven - 1]]
    if {$four >= 2} {
      incr ans [expr [bar [expr $four - 2] [expr $seven - 1]]]
    }
  }
  puts [expr $ans % $mod]
}

#Correct Answer
#Execution Time: 0.77

