#!/usr/bin/perl

use strict;
use warnings;
use List::MoreUtils 'pairwise';
use Math::Int64 'int64';

our ($a, $b);
our $mod = 1000000;

my @choose = ([int64(1)]);
for (1 .. 1000) {
  my @a = (0, @{$choose[-1]});
  my @b = (@{$choose[-1]}, 0);
  push @choose, [pairwise { ($a + $b) % $mod } @a, @b]
}

my @dp = (0, 1);
for my $i (2 .. 1000) {
  $dp[$i] = 0;
  for my $j (1 .. $i - 1) {
    $dp[$i] = ($dp[$i] + $choose[$i - 1][$j - 1] * $dp[$j] * $dp[$i - $j]) % $mod;
  }
}

while (<>) {
  print "$dp[$_ - 1]\n";
}
