#!/usr/bin/tclsh

proc gao {a b} {
  if {$a eq "?" || $a eq $b} {
    return $b
  } else {
    return *
  }
}

gets stdin re
for {set ri 1} {$ri <= $re} {incr ri} {
  for {set i 0} {$i < 4} {incr i} {
    gets stdin buf
    for {set j 0} {$j < 4} {incr j} {
      set a($i,$j) [string index $buf $j]
    }
  }
  gets stdin

  set draw 1
  set win ?
  for {set i 0} {$i < 4} {incr i} {
    for {set j 0} {$j < 4} {incr j} {
      if {$a($i,$j) eq "."} {
        set draw 0
      }
      foreach {di dj} {0 1 1 0 1 1 1 -1} {
        set win T
        for {set k 0} {$k < 4} {incr k} {
          set x [expr $i + $k * $di]
          set y [expr $j + $k * $dj]
          if {$x < 0 || $x >= 4 || $y < 0 || $y >= 4 || $a($x,$y) eq "."} {
            set win ?
            break
          } elseif {$win eq "T"} {
            set win $a($x,$y)
          } elseif {$a($x,$y) ne "T" && $a($x,$y) ne $win} {
            set win ?
            break
          }
        }
        if {$win ne "?"} { break }
      }
      if {$win ne "?"} { break }
    }
    if {$win ne "?"} { break }
  }

  puts -nonewline "Case #$ri: "
  if {$win ne "?"} {
    puts "$win won"
  } elseif {$draw} {
    puts "Draw"
  } else {
    puts "Game has not completed"
  }
}
