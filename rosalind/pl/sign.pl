#!/usr/bin/perl

use strict;
use warnings;
use List::Util 'reduce';

our ($a, $b);

sub perm {
  my ($p, @a) = @_;
  unless (@a) {
    print "@$p\n";
  } else {
    for my $i (@a) {
      my @b = grep { $_ != $i } @a;
      perm([@$p, $i], @b);
      perm([@$p, -$i], @b);
    }
  }
}

while (my $n = <ARGV>) {
  my $m = reduce { $a * $b } (1 .. $n);
  $m *= 2 ** $n;
  print "$m\n";
  perm([], 1 .. $n);
}
