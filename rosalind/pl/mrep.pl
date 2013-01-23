#!/usr/bin/perl

use strict;
use warnings;

chomp(my $s = <>);
my @s = split //, $s;
my $n = @s;
push @s, '$';

my %g = ();
for my $i (0 .. $n - 20) {
  my $t = substr($s, $i, 20);
  $g{$t} //= [];
  push $g{$t}, $i;
}

my %ans = ();
for my $p (values %g) {
  for my $i (@$p) {
    for my $j (@$p) {
      next if $s[$i + 20] eq $s[$j + 20];
      my $k = 1;
      ++$k while $s[$i - $k] eq $s[$j - $k];
      --$k;
      $ans{substr($s, $i - $k, 20 + $k)} = 1;
    }
  }
}

for my $ans (keys %ans) {
  print "$ans\n";
}
