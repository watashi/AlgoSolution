#!/usr/bin/perl

use strict;
use warnings;

sub gao {
  my ($a, $b) = @_;
  my $ret = {};
  for my $i (keys $a) {
    for my $j (keys $b) {
      for my $ii (split //, $i) {
        for my $jj (split //, $j) {
          $ret->{$ii . $jj} += $a->{$i} * $b->{$j} / 4;
        }
      }
    }
  }
  $ret;
}

$_ = <>;
my ($n, $m) = split;
my $p = {'Aa' => 1};
for (1 .. $n) {
  $p = gao($p, {'Aa' => 1});
}
$p = $p->{Aa} + $p->{aA};
# $p == 0.5
$p = $p * $p;

my @choose = [1];
for my $i (1 .. (1 << $n)) {
  push @choose, [1];
  for my $j (1 .. $i - 1) {
    push $choose[$i], $choose[$i - 1][$j - 1] + $choose[$i - 1][$j];
  }
  push $choose[$i], 1;
}
my $ans = 0;
for my $i ($m .. (1 << $n)) {
  $ans += $choose[1 << $n][$i] * $p ** $i * (1 - $p) ** ((1 << $n) - $i);
}
print "$ans\n";
