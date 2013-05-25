#!/usr/bin/perl

use strict;
use warnings;

my $n = <>;
my @p = split ' ', <>;
@p = map { $n * $_ } @p;
print "@p\n";
