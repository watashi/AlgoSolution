#!/usr/bin/perl

use strict;
use warnings;
use Rosalind 'fasta';

my ($s, $t);
undef $/;
$_ = <>;
($_, $s, $_, $t) = fasta($_);

my %c = ();
for my $i (0 .. length($s) - 1) {
  ++$c{substr($s, $i, 1) . substr($t, $i, 1)};
}

my ($transition, $transversion) = (0, 0);
while (my ($k, $v) = each %c) {
  if ($k =~ /AG|GA|CT|TC/) {
    $transition += $v;
  } elsif ($k !~ /(.)\1/) {
    $transversion += $v;
  }
}
print $transition / $transversion, "\n";
