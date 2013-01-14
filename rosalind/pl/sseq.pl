#!/usr/bin/perl

use strict;
use warnings;

chomp(my $s = <>);
chomp(my $t = <>);
my $p = 0;
my @p = ();
for my $c (split //, $t) {
  $p = index($s, $c, $p) + 1;
  push @p, $p;
}
print "@p\n";
