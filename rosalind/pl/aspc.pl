#!/usr/bin/perl

use strict;
use warnings;
use Math::BigInt only => 'GMP';

my ($n, $m) = split ' ', <>;
my $s = Math::BigInt->bzero;
for my $k ($m .. $n) {
  $s += Math::BigInt->bnok($n, $k);
}
$s %= 1000000;
print "$s\n";
