#!/usr/bin/perl

use strict;
use warnings;
use List::Util 'max';
use List::MoreUtils 'firstidx';

sub subset {
  my ($a, $b) = @_;
  ($a & $b) eq $b;
}

sub consisten {
  my ($a, $b) = @_;
  my $ca = $a =~ y/01/10/r;
  my $cb = $b =~ y/01/10/r;
  for my $i ($a, $ca) {
    for my $j ($b, $cb) {
      return 1 if subset($i, $j);
    }
  }
  return 0;
}

chomp(my @s = <>);
my @c = (0) x @s;
for my $i (0 .. $#s) {
  for my $j (0 .. $i - 1) {
    unless (consisten($s[$i], $s[$j])) {
      ++$c[$i];
      ++$c[$j];
    }
  }
}

my $c = max @c;
my $p = firstidx { $_ == $c } @c;
splice(@s, $p, 1);
print join("\n", @s), "\n";
