#!/usr/bin/perl

use strict;
use warnings;
use Rosalind 'fasta';
use List::Util 'sum';
use List::MoreUtils 'pairwise';

our ($a, $b);

sub diff {
  my ($s, $t) = @_;
  sum pairwise { $a eq $b ? 0 : 1 } @$s, @$t;
}

undef $/;
$_ = <>;
my @fasta = fasta($_);
my $n = scalar @fasta / 2;
@fasta = @fasta[map { $_ * 2 + 1 } (0 .. $n - 1)];

for (@fasta) {
  $_ = [split //];
}

for my $i (@fasta) {
  @_ = ();
  for my $j (@fasta) {
    push @_, diff($i, $j) / @$i;
  }
  print "@_\n";
}
