#!/usr/bin/perl

use strict;
use warnings;
use integer;
use List::Util 'min';

sub subs ($$) {
  my ($n, $s) = @_;
  map { substr($s, $_, $n) => 1 } (0 .. length($s) - $n);
}

sub comm (\%\%) {
  my ($a, $b) = @_;
  map { exists $b->{$_} ? ($_ => 1) : () } keys $a;
}

chomp(my @s = <>);
my $l = 0;
my $r = min map { length } @s;
my $ans = '';
while ($l < $r) {
  my $m = ($l + $r) / 2;
  my %h = subs($m, $s[0]);
  for my $s (@s[1 .. $#s]) {
    my %t = subs($m, $s);
    %h = comm(%h, %t);
  }
  my $k = each %h;
  if (defined($k)) {
    $ans = $k;
    $l = $m + 1;
  } else {
    $r = $m;
  }
}
print "$ans\n";
