#!/usr/bin/perl

use strict;
use warnings;
use List::Util 'max';

my @d = sort { $a <=> $b } split ' ', <>;
my $d = pop @d;
my @p = (0, $d);

sub gao {
  return 1 unless @_;
  for my $p ($d - $_[-1], $_[-1]) {
    my @a = ();
    my @b = sort { $b <=> $a } map { abs($_ - $p) } @p;
    for (@_) {
      if (@b && $_ == $b[-1]) {
        pop @b;
      } else {
        push @a, $_;
      }
    }
    unless (@b) {
      push @p, $p;
      return 1 if gao(@a);
      pop @p;
    }
  }
  return 0;
}

gao(@d);
@p = sort { $a <=> $b } @p;
print "@p\n";
