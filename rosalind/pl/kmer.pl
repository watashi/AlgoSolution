#!/usr/bin/perl

use strict;
use warnings;
use List::Util 'reduce';

our ($a, $b);

my $key = <>;
my $seq = join('', <>);
$seq =~ s/\W//g;

my @ans = (0) x (4 ** 4);
while ($seq =~ /(?=(\w{4}))/g) {
  my $ord = $1;
  $ord =~ y/ACGT/0-3/;
  ++$ans[reduce { $a * 4 + $b } split //, $ord];
}
print "@ans\n";
