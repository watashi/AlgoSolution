#!/usr/bin/tclsh

proc gao {l r} {
  global s
  global dp
  if {[catch { set dp($l,$r) } ret] == 0} {
    return $ret
  }
  switch -exact [expr $r - $l] {
    0 { set ret 1 }
    1 {
      set ret [expr {
        [lindex $s $l] ne "(" && [lindex $s $l] ne ")"
      }]
    }
    2 {
      set ret [expr {
        [gao $l [expr $l + 1]] && [gao [expr $r - 1] $r] ||
        [lindex $s $l] eq "(" && [lindex $s $r-1] eq ")" ||
        [lindex $s $l] eq ":"
      }]
    }
    default {
      set ret [expr {
        [lindex $s $l] eq "(" && [lindex $s $r-1] eq ")" &&
        [gao [expr $l + 1] [expr $r - 1]]
      }]
      for {set m [expr $l + 1]} {!$ret && $m < $r} {incr m} {
        set ret [expr { [gao $l $m] && [gao $m $r] }]
      }
    }
  }
  set dp($l,$r) $ret
}

set re [gets stdin]
for {set ri 1} {$ri <= $re} {incr ri} {
  set s [gets stdin]
  set s [regexp -all -inline {[()]|:[^(:)]*} $s]
  array unset dp
  set ans [gao 0 [llength $s]]
  puts "Case #$ri: [expr $ans ? YES : NO]"
}
