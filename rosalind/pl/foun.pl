#!/usr/bin/perl

use strict;
use warnings;
use List::MoreUtils 'pairwise';

our ($a, $b);

my ($n, $m) = split ' ', <>;
my @choose = (1);
for my $i (1 .. 2 * $n) {
  my @a = (0, @choose);
  my @b = (@choose, 0);
  @choose = pairwise { $a + $b } @a, @b;
}

sub probability {
  my ($k, $p) = @_;
  $choose[$k] * $p ** $k * (1 - $p) ** (2 * $n - $k);
}

my @ans = ();
my @a = split ' ', <>;
for (@a) {
  my @p = (0) x (2 * $n + 1);
  $p[$_] = 1;
  for my $k (0 .. $m - 1) {
    my @q = (0) x @p;
    for my $i (0 .. $#p) {
      my $p = $i / (2 * $n);
      for my $j (0 .. $#q) {
        $q[$j] += $p[$i] * probability($j, $p);
      }
    }
    @p = @q;
    $ans[$k] //= [];
    push @{$ans[$k]}, $p[0];
  }
}

for my $ans (@ans) {
  my @tmp = map { log($_) / log(10) } @$ans;
  print "@tmp\n";
}

