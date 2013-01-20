#!/usr/bin/perl

use strict;
use warnings;
use List::Util 'reduce';

our ($a, $b);

sub lcp {
  my ($a, $b) = @_;
  my $n = 0;
  ++$n while substr($a, $n, 1) eq substr($b, $n, 1);
  substr($a, 0, $n);
}

sub build {
  return unless @_;
  my %group = ();
  for (@_) {
    my $k = substr($_, 0, 1);
    $group{$k} //= [];
    push $group{$k}, $_;
  }
  while (my ($k, $v) = each %group) {
    my $lcp = reduce { lcp($a, $b) } @$v;
    my $n = length $lcp;
    print "$lcp\n";
    build(grep { length } map { substr($_, $n) } @$v);
  }
}

chomp(my $s = <>);
my @s = map { substr($s, $_) } 0 .. length($s) - 1;
my $sa = build(@s);

