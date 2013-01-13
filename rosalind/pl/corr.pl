#!/usr/bin/perl

use strict;
use warnings;
use Rosalind 'revc';
use List::Util 'minstr';

sub nomarlize {
  my $seq = shift;
  minstr $seq, revc($seq);
}

my %db = ();
chomp(my @seq = <>);

for my $seq (@seq) {
  ++$db{nomarlize($seq)};
}

for my $seq (@seq) {
  next if $db{nomarlize($seq)} > 1;
  my $s = $seq;
  my $n = length $s;
  LOOP:
  for my $p (0 .. $n - 1) {
    my $c = substr($s, $p, 1);
    for my $i (qw(A C G T)) {
      next if $i eq $c;
      substr($s, $p, 1) = $i;
      last LOOP if ($db{nomarlize($s)} // 0) > 1;
    }
    substr($s, $p, 1) = $c;
  }
  # ++$db{nomarlize($s)};
  print $seq, '->', $s, "\n";
}
