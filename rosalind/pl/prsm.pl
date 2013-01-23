#!/usr/bin/perl

use strict;
use warnings;
use Rosalind 'mass';

chomp(my $n = <>);
my @s = ();
for (1 .. $n) {
  chomp(my $s = <>);
  push @s, $s;
}

my $max = -1;
my $ans = undef;

my @w = ();
while (my $w = <>) {
  push @w, $w;
}

sub partial_sum {
  for my $i (1 .. $#_) {
    $_[$i] += $_[$i - 1];
  }
  @_;
}

for my $s (@s) {
  my %h = ();
  for my $i (@w) {
    for my $j (mass($s), mass(reverse $s)) {
      ++$h{sprintf "%f", $i - $j};
    }
  }
  while (my ($k, $v) = each %h) {
    if ($max < $v) {
      $max = $v;
      $ans = $s;
    }
  }
}
print "$max\n$ans\n";
