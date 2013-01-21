#!/usr/bin/perl

use strict;
use warnings;
use feature 'switch';
use constant INF => 1000000007;
use Algorithm::Diff 'sdiff';

chomp(my $s = <>);
chomp(my $t = <>);

my @s = split //, $s;
my @t = split //, $t;

my @dp = ();
my @pre = ();

$dp[0][0] = 0;
for my $i (0 .. @s) {
  for my $j (0 .. @t) {
    $dp[$i][$j] //= INF;
    if ($i > 0 && $dp[$i][$j] > $dp[$i - 1][$j] + 1) {
      $dp[$i][$j] = $dp[$i - 1][$j] + 1;
      $pre[$i][$j] = '-';
    }
    if ($j > 0 && $dp[$i][$j] > $dp[$i][$j - 1] + 1) {
      $dp[$i][$j] = $dp[$i][$j - 1] + 1;
      $pre[$i][$j] = '+';
    }
    if ($i > 0 && $j > 0) {
      my $k = $s[$i - 1] ne $t[$j - 1];
      if ($dp[$i][$j] > $dp[$i - 1][$j - 1] + $k) {
        $dp[$i][$j] = $dp[$i - 1][$j - 1] + $k;
        $pre[$i][$j] = $k ? 'c' : 'u';
      }
    }
  }
}

($s, $t) = ('', '');
while (@s || @t) {
  given ($pre[@s][@t]) {
    when ('-') {
      $s .= pop @s;
      $t .= '-';
    }
    when ('+') {
      $s .= '-';
      $t .= pop @t;
    }
    default {
      $s .= pop @s;
      $t .= pop @t;
    }
  }
}
printf "%d\n%s\n%s\n", $dp[-1][-1], scalar(reverse $s), scalar(reverse $t);

=begin WA
my ($d, $x, $y) = (0, '', '');
for (sdiff [split //, $s], [split //, $t]) {
  ++$d if $_->[0] ne 'u';
  $x .= $_->[1] || '-';
  $y .= $_->[2] || '-';
}
print "$d\n$x\n$y\n";
=end
