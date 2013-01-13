#!/usr/bin/perl

use strict;
use warnings;
use Math::BigInt;

my ($n, $k) = split ' ', <>;
my $ans = Math::BigInt->bnok($n, $k) * Math::BigInt->bfac($k) % 1000000;
print "$ans\n";
