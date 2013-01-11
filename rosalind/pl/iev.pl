#!/usr/bin/perl

use strict;
use warnings;

sub p {
  my ($a, $b) = @_;
  1 - $a =~ y/a/a/ * $b =~ y/a/a/ / 4;
}

my @x = <DATA>;
my @y = split ' ', <>;
my $n = 0;
for my $i (0 .. $#y) {
  $n += p(split '-', $x[$i]) * $y[$i];
}
printf "%f\n", 2 * $n;

__DATA__
AA-AA
AA-Aa
AA-aa
Aa-Aa
Aa-aa
aa-aa
