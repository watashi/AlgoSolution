#!/usr/bin/perl

use strict;
use warnings;
use Algorithm::Diff 'LCS_length';

chomp(my $s = <>);
chomp(my $t = <>);
my @s = split //, $s;
my @t = split //, $t;
print @s + @t - 2 * LCS_length(\@s, \@t), "\n";
