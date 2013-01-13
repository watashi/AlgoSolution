#!/usr/bin/perl

use strict;
use warnings;
use List::MoreUtils 'pairwise';

our ($a, $b);

sub log10 {
  my $x = shift;
  log($x) / log(10);
}

my ($n, $r) = split ' ', <>;
my $s = <>;
my $at = $s =~ y/AT/AT/;
my $cg = $s =~ y/CG/CG/;
my $p = log10($r / 2) * $cg + log10(0.5 - $r / 2) * $at;
print 1 - (1 - 10 ** $p) ** $n, "\n";

