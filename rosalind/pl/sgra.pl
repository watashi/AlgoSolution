#!/usr/bin/perl

use strict;
use warnings;
use Rosalind 'spect';
use List::Util 'reduce';

sub longer {
  my ($a, $b) = @_;
  length($a) > length($b) ? $a : $b;
}

chomp(my @w = <>);
@w = sort { $a <=> $b } @w;

my @dp = ();
for my $i (0 .. $#w) {
  my $dp = '';
  for my $j (0 .. $#dp) {
    my $c = spect($w[$i] - $w[$j]);
    $dp = longer($dp, $dp[$j] . $c) if defined $c;
  }
  push @dp, $dp;
}

my $ans = reduce { longer($a, $b) } @dp;
print "$ans\n";
