#!/usr/bin/perl

use strict;
use warnings;
use Algorithm::Diff 'LCS';

chomp(my $s = <>);
chomp(my $t = <>);
my @s = split //, $s;
my @t = split //, $t;
print LCS(\@s, \@t), "\n";
