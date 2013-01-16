#!/usr/bin/perl

use strict;
use warnings;

my @a = split ' ', <>;
my @b = split ' ', <>;
my %s = ();
for my $i (@a) {
  for my $j (@b) {
    my $d = sprintf '%.6f', $i - $j;
    ++$s{$d};
  }
}

my ($x, $y) = (-1, -1);
while (my ($k, $v) = each %s) {
  if ($v > $x) {
    ($x, $y) = ($v, $k);
  }
}
printf "%d\n%.6f\n", $x, abs($y);
