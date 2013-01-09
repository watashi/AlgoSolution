#!/usr/bin/perl -w

use strict;
use warnings;
use List::Util 'sum';
use List::MoreUtils 'pairwise';

sub gets {
  chomp(my $s = <ARGV>);
  [split //, $s];
}

our ($a, $b);
my ($s, $t) = (gets, gets);
print sum(pairwise { $a ne $b } @$s, @$t), "\n";
