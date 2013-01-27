#!/usr/bin/perl

use strict;
use warnings;
use List::Util 'sum';

sub nok {
  my ($n, $k) = @_;
  my $ret = 1;
  for my $i (1 .. $k) {
    $ret *= $n + 1 - $i;
    $ret /= $i;
  }
  $ret;
}

sub nokp {
  my ($n, $k, $p) = @_;
  nok($n, $k) * $p ** $k * (1 - $p) ** ($n - $k);
}

sub next_generation {
  my ($n, @p) = @_;
  my @q = ();
  for my $i (0 .. $n) {
    next unless $p[$i];
    my $p = $i / $n;
    for my $j (0 .. $n) {
      $q[$j] += $p[$i] * nokp($n, $j, $p);
    }
  }
  @q;
}

my ($n, $m, $g, $k) = split / /, <>;
my @p = ();
$p[$m] = 1;
for (1 .. $g) {
  @p = next_generation(2 * $n, @p);
}
my $ans = sum(@p[0 .. 2 * $n - $k]);
print "$ans\n";
