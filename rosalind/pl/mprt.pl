#!/usr/bin/perl -nl

use strict;
use warnings;
use LWP::Simple;

my $fasta = get "http://www.uniprot.org/uniprot/$_.fasta";
my ($key, $value) = split "\n", $fasta, 2;
my @pos = ();
$value =~ s/\W//g;
while ($value =~ /(?=N[^P][ST][^P])/g) {
  push @pos, pos($value) + 1;
}
print "$_\n@pos" if @pos > 0;
