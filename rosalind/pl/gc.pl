#!/usr/bin/perl

use strict;
use warnings;
use Bio::DB::Fasta;

my @ans = ('', 0);
tie my %db, 'Bio::DB::Fasta', $ARGV[0];
while (my ($k, $v) = each %db) {
  if (defined($v)) {
    my $gc = $v =~ y/GC/GC/;
    $gc = $gc * 100 / length($v);
    if ($gc > $ans[1]) {
      @ans = ($k, $gc);
    }
  }
}
printf "%s\n%.6f%%\n", @ans;
