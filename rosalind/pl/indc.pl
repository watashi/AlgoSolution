#!/usr/bin/perl

use strict;
use warnings;
use Math::BigInt;

my $n = <>;
$n *= 2;
my @ans = ();
for my $k (reverse 1 .. $n) {
  push @ans, $ans[-1] + Math::BigInt->bnok($n, $k);
}
@ans = reverse @ans;
@ans = map { (log($_->bsstr) - $n * log(2)) / log(10) } @ans;
print "@ans\n";
