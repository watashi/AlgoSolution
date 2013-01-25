#!/usr/bin/perl

use strict;
use warnings;
use constant MOD => 2 ** 27 - 1;

chomp(my $s = <>);
chomp(my $t = <>);

my @s = split //, $s;
my @t = split //, $t;

my @dp = 0 .. @t;
my @ans = (1) x @t;
for my $i (0 .. $#s) {
  for my $j (reverse 0 .. @t) {
    ++$dp[$j];
    next if $j == 0;
    my $tmp = $dp[$j - 1] + ($s[$i] ne $t[$j - 1]);
    if ($dp[$j] > $tmp) {
      $dp[$j] = $tmp;
      $ans[$j] = $ans[$j - 1];
    } elsif ($dp[$j] == $tmp) {
      $ans[$j] += $ans[$j - 1];
      $ans[$j] %= MOD;
    }
  }
  for my $j (1 .. @t) {
    my $tmp = $dp[$j - 1] + 1;
    if ($dp[$j] > $tmp) {
      $dp[$j] = $tmp;
      $ans[$j] = $ans[$j - 1];
    } elsif ($dp[$j] == $tmp) {
      $ans[$j] += $ans[$j - 1];
      $ans[$j] %= MOD;
    }
  }
}
print "$ans[-1]\n";

