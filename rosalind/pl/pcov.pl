#!/usr/bin/perl

use strict;
use warnings;

chomp(my @v = <>);
my $k = length($v[0]) - 1;
my $ans = pop @v;
while (@v) {
  for my $i (0 .. $#v) {
    if (substr($ans, -$k) eq substr($v[$i], 0, $k)) {
      $ans .= substr($v[$i], -1);
      splice @v, $i, 1;
      last;
    }
  }
}
print substr($ans, $k), "\n";
