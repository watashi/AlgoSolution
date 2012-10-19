#!/usr/bin/perl

use strict;
use warnings;
use List::Util qw(max);
no warnings qw(uninitialized);

my $re = <STDIN>;
for my $ri (1 .. $re) {
  my @w;
  my $n = <STDIN>;
  for my $i (0 .. $n - 1) {
    $_ = <STDIN>;
    my ($s, $e, $c) = split;
    $w[$s][$e] = max $w[$s][$e], $c;
  }

  my @dp;
  my $ans = 0;
  for my $i (0 .. 48) {
    $ans = max $ans, $dp[$i];
    for my $j ($i + 1 .. 48) {
      $dp[$j] = max $dp[$j], $dp[$i] + $w[$i][$j];
    }
  }

  print "$ans\n";
}

#Correct Answer
#Execution Time: 1.71

