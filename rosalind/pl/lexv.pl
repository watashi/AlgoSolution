#!/usr/bin/perl

use strict;
use warnings;

my @alphabet = split ' ', <>;
my $length = <>;

sub gen {
  my ($n, $s) = @_;
  print "$s\n" if $s ne '';
  return if $n == 0;
  for my $c (@alphabet) {
    gen($n - 1, $s . $c);
  }
}

gen($length, '');
