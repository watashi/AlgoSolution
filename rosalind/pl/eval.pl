#!/usr/bin/perl

use strict;
use warnings;

sub probability {
  my ($gc, $dna) = @_;
  (0.5 - $gc / 2) ** ($dna =~ y/AT/AT/)
      * ($gc / 2) ** ($dna =~ y/GC/GC/);
}

chomp(my $n = <>);
chomp(my $s = <>);
my @p = split ' ', <>;
for my $p (@p) {
  $p = probability($p, $s) * ($n - length($s) + 1);
}
print "@p\n";
