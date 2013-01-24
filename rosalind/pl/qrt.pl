#!/usr/bin/perl

use strict;
use warnings;

sub indices {
  my ($s, $t) = @_;
  my @p = ();
  my $p = 0;
  while (($p = index $s, $t, $p) >= 0) {
    push @p, $p++;
  }
  @p;
}

sub pair {
  my @ret = ();
  for my $i (0 .. $#_) {
    for my $j (0 .. $i - 1) {
      push @ret, "$_[$j] $_[$i]";
    }
  }
  @ret;
}

my @s = split ' ', <>;
my %s = ();
while (<>) {
  my @a = indices $_, '1';
  my @b = indices $_, '0';
  for my $a (pair @a) {
    for my $b (pair @b) {
      $s{$a lt $b ? "$a $b" : "$b $a"} = 1;
    }
  }
}

for (keys %s) {
  printf "{%s, %s} {%s, %s}\n", map { $s[$_] } split;
}

