#!/usr/bin/perl

use strict;
use warnings;
use Bit::Vector::Overload;

sub readset {
  my $n = shift;
  my $set = Bit::Vector->new($n);
  my $_ = <>;
  y/{}/()/;
  for my $i (eval "$_") {
    $set->Bit_On($i - 1);
  }
  $set;
}

sub showset {
  my $set = shift;
  my ($start, $min, $max) = (0, undef, undef);
  my @pos = ();
  while ($start < $set->Size &&
      (($min, $max) = $set->Interval_Scan_inc($start))) {
    $start = $max + 2;
    push @pos, $min .. $max;
  }
  print '{', join(', ', map { $_ + 1} @pos), "}\n";
}

chomp(my $n = <>);
my $a = readset($n);
my $b = readset($n);
for my $i ($a | $b, $a & $b, $a & ~$b, $b & ~$a, ~$a, ~$b) {
  showset($i);
}
