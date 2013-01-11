#!/usr/bin/perl

use strict;
use warnings;

sub comm {
  my ($a, $b) = @_;
  my $n = length($a) < length($b) ? length($a) : length($b);
  --$n while $n > 0 && substr($a, -$n) ne substr($b, 0, $n);
  $n;
}

chomp(my @s = <>);

while (@s > 1) {
  my @k = (-1, -1, -1);
  for my $i (0 .. $#s) {
    for my $j (0 .. $#s) {
      if ($i != $j) {
        my $n = comm($s[$i], $s[$j]);
        if ($n > $k[0]) {
          @k = ($n, $i, $j);
        }
      }
    }
  }
  push @s, $s[$k[1]] . substr($s[$k[2]], $k[0]);
  undef $s[$k[1]];
  undef $s[$k[2]];
  @s = grep { $_ } @s;
}

print "$s[0]\n";

