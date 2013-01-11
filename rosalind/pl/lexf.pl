#!/usr/bin/perl

use strict;
use warnings;
use List::Util 'reduce';

our ($a, $b);

my $alphabet = [split ' ', <>];
my $n = <>;
my $ans = reduce {
  @_ = ();
  for my $i (@$a) {
    for my $j (@$b) {
      push @_, $i . $j;
    }
  }
  [@_];
} ($alphabet) x $n;
print join("\n", @$ans), "\n";
