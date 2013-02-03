#!/usr/bin/perl

use strict;
use warnings;
use List::Util 'sum';

chomp(my @dna = <>);
my @len = sort { $b <=> $a } map { length } @dna;
my $sum = sum @len;
my $acc = 0;

my %ans = (50 => undef, 75 => undef);

for (@len) {
  $acc += $_;
  for my $rate (keys %ans) {
    if (!defined($ans{$rate}) && $acc * 100 >= $rate * $sum) {
      $ans{$rate} = $_;
    }
  }
}

my @ans = map { $ans{$_} } sort keys %ans;
print "@ans\n";
