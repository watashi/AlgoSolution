#!/usr/bin/perl

use strict;
use warnings;
use Rosalind '%codon';

chomp(my $dna = <>);
chomp(my @introns = <>);
for my $intron (@introns) {
  $dna =~ s/$intron//g;
}
$dna =~ s/T/U/g;
$dna =~ s/\w{3}/$codon{$&}/ge;
$dna =~ s/0.*//;
print "$dna\n";
