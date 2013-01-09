#!/usr/bin/perl

use strict;
use warnings;
use Bio::DB::Fasta;

tie my %db, 'Bio::DB::Fasta', $ARGV[0];
my (%from, %to);
while (my ($v, $s) = each %db) {
  if (defined($s) && length($s) >= 3) {
    push $from{substr($s, -3)} ||= [], $v;
    push $to{substr($s, 0, 3)} ||= [], $v;
  }
}

while (my ($e, $frome) = each %from) {
  my $toe = $to{$e} || [];
  for my $s (@$frome) {
    for my $t (@$toe) {
      print "$s $t\n" if $db{$s} ne $db{$t};
    }
  }
}
