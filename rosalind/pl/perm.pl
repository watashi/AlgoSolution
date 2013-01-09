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
      push $p, $i;
      perm($p, grep { $_ != $i } @a);
      pop $p;
    }
  }
}

while (my $n = <ARGV>) {
  my $m = reduce { $a * $b } (1 .. $n);
  print "$m\n";
  perm([], 1 .. $n);
}
