#!/usr/bin/perl

use strict;
use warnings;
use List::Util 'min';

chomp(my $s = <>);
chomp(my $t = <>);

my @s = split //, $s;
my @t = split //, $t;

my @dp = 0 .. @t;
for my $i (0 .. $#s) {
  for my $j (reverse 0 .. $#t) {
    $dp[$j + 1] = min $dp[$j + 1] + 1, $dp[$j] + ($s[$i] ne $t[$j]);
  }
  ++$dp[0];
  for my $j (0 .. $#t) {
    $dp[$j + 1] = min $dp[$j + 1], $dp[$j] + 1;
  }
}
print "$dp[-1]\n";
