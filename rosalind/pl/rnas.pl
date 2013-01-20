#!/usr/bin/perl

use strict;
use warnings;
use bigint try => 'GMP';
use List::Util 'sum';

my %tab = (
  A => 'U',
  C => 'G',
  G => 'CU',
  U => 'AG',
);

chomp(my $s = <>);
my @s = split //, $s;
my @dp = ();
for (0 .. @s) {
  push @dp, [(1) x @s];
}

for my $k (4 .. $#s) {
  for my $j ($k .. $#s) {
    my $i = $j - $k;
    my $t = $tab{$s[$i]};
    $dp[$i][$j] = $dp[$i + 1][$j] + sum map {
        index($t, $s[$_]) >= 0 ? $dp[$i + 1][$_ - 1] * $dp[$_ + 1][$j] : 0
      } $i + 4 .. $j;
  }
}

print $dp[0][$#s], "\n";

