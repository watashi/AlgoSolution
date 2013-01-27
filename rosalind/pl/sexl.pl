#!/usr/bin/perl

use strict;
use warnings;

my @p = split ' ', <>;
@p = map { 2 * $_ * (1 - $_) } @p;
print "@p\n";
