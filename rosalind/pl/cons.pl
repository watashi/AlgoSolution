#!/usr/bin/perl

use strict;
use warnings;
use List::Util 'reduce';

sub best {
  my $c = shift;
  reduce { $c->{$a} >= $c->{$b} ? $a : $b } keys %{$c};
}

my @c = ();
while (<>) {
  chomp;
  my @s = split //;
  for my $i (0 .. $#s) {
    $c[$i] ||= {};
    ++$c[$i]{$s[$i]};
  }
}

for my $c (@c) {
  print best($c);
}
print "\n";
for my $k (qw(A C G T)) {
  print "$k:";
  for my $c (@c) {
    print ' ', $c->{$k} || 0;
  }
  print "\n";
}
