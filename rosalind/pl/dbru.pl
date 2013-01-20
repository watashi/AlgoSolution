#!/usr/bin/perl

use strict;
use warnings;
use Rosalind 'revc';

chomp(my @e = <>);
my %e = map { $_ => 1, revc($_) => 1 } @e;
@e = keys %e;
for my $e (@e) {
  printf "(%s, %s)\n", substr($e, 0, -1), substr($e, 1);
}
