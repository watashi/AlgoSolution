#!/usr/bin/perl

use strict;
use warnings;

my ($k, $m, $n) = split /\s+/, <>;
my $s = $k + $m + $n;
my $x = 0;
$x += $k * ($s - 1);
$x += $m * $k;
$x += $m * ($m - 1) * 0.75;
$x += $m * $n * 0.5;
$x += $n * $k;
$x += $n * $m * 0.5;
my $y = $s * ($s - 1);
print $x / $y;
