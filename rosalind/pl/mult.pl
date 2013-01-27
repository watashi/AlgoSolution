#!/usr/bin/perl

use strict;
use warnings;
use List::Util 'min';
use List::MoreUtils 'uniq';
use constant MIN_VALUE => -1000000007;

chomp(my @s = <>);
my %dp = ();
my %pre = ();

sub gao {
  my $key = "@_";
  return $dp{$key} if exists $dp{$key};
  my ($dp, $pre) = (\$dp{$key}, \$pre{$key});
  $$dp = MIN_VALUE;
  for my $i (0 .. (1 << @s) - 1) {
    my @i = map { ($i >> $_) & 1 } 0 .. $#s;
    my @j = map { $_[$_] - $i[$_] } 0 .. $#s;
    next if min(@j) < 0;

    my @k = map { $i[$_] ? substr($s[$_], $j[$_], 1) : '-'  } 0 .. $#s;
    my %k = ();
    ++$k{$_} for @k;
    my $k = gao(@j) - @k * (@k - 1) / 2;
    $k += $_ * ($_ - 1) / 2 for (values %k);

    if ($$dp < $k) {
      $$dp = $k;
      $$pre = $i;
    }
  }
  $$dp;
}

my @init = (0) x @s;
$dp{"@init"} = 0;

my @pos = map { length($s[$_]) } 0 .. $#s;
my $ans = gao(@pos);
my @ans = ('') x @s;
while (my $mask = $pre{"@pos"}) {
  for (0 .. $#s) {
    if (($mask >> $_) & 1) {
      --$pos[$_];
      $ans[$_] .= substr($s[$_], $pos[$_], 1);
    } else {
      $ans[$_] .= '-';
    }
  }
}
@ans = map { scalar reverse $_ } @ans;
print join("\n", $ans, @ans), "\n";


