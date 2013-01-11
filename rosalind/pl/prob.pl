#!/usr/bin/perl

use strict;
use warnings;
use List::MoreUtils 'pairwise';

our ($a, $b);

sub log10 {
  my $x = shift;
  log($x) / log(10);
}

my $s = <>;
my $at = $s =~ y/AT/AT/;
my $cg = $s =~ y/CG/CG/;
my @choose = (1);
for (1 .. $at + $cg) {
  my @a = (0, @choose);
  my @b = (@choose, 0);
  @choose = pairwise { $a + $b } @a, @b;
}

my $t = <>;
my @ans = map { log10($_ / 2) * $cg + log10(0.5 - $_ / 2) * $at } (split ' ', $t);
print "@ans\n";
