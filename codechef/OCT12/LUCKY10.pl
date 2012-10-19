#!/usr/bin/perl

use strict;
use warnings;

sub scan {
  my @ret = (0) x 4;
  chomp($_ = <STDIN>);
  $ret[0] = y/0123//d;
  $ret[1] = y/4//d;
  $ret[2] = y/56//d;
  $ret[3] = y/7//d;
  return @ret;
}

my $re = <STDIN>;
for (my $ri = 1; $ri <= $re; ++$ri) {
  my @a = scan;
  my @b = scan;
  my ($seven, $four) = (0, 0);
  { my $d = min $a[3], $b[2]; $a[3] -= $d; $b[2] -= $d; $seven += $d; }
  { my $d = min $a[3], $b[0]; $a[3] -= $d; $b[0] -= $d; $seven += $d; }
  { my $d = min $a[3], $b[1]; $a[3] -= $d; $b[1] -= $d; $seven += $d; }
  { my $d = min $a[3], $b[3]; $a[3] -= $d; $b[3] -= $d; $seven += $d; }
  { my $d = min $a[2], $b[3]; $a[2] -= $d; $b[3] -= $d; $seven += $d; }
  { my $d = min $a[0], $b[3]; $a[0] -= $d; $b[3] -= $d; $seven += $d; }
  { my $d = min $a[1], $b[3]; $a[1] -= $d; $b[3] -= $d; $seven += $d; }
  { my $d = min $a[0], $b[1]; $a[0] -= $d; $b[1] -= $d; $four += $d; }
  { my $d = min $a[1], $b[0]; $a[1] -= $d; $b[0] -= $d; $four += $d; }
  { my $d = min $a[1], $b[1]; $a[1] -= $d; $b[1] -= $d; $four += $d; }
  print '7' x $seven . '4' x $four, "\n";
}

#Correct Answer
#Execution Time: 5.24

