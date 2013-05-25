#!/usr/bin/perl
# see gcon.pl

use strict;
use warnings;
use List::Util 'max';
use constant MIN_SCORE => -1000000007;
use constant GAP_OPEN => -12;
use constant GAP_CONT => -1;
use Rosalind ':score';

my $score = score(BLOSUM64);
chomp(my $s = <>);
chomp(my $t = <>);

my @s = split //, $s;
my @t = split //, $t;

my @dp1 = (0, (MIN_SCORE) x @t);
my @dp2 = (MIN_SCORE) x @dp1;
for my $i (0 .. $#s) {
  for my $j (reverse 0 .. $#t) {
    $dp2[$j + 1] = max($dp1[$j + 1] + GAP_OPEN, $dp2[$j + 1] + GAP_CONT);
    $dp1[$j + 1] = max($dp1[$j], $dp2[$j]) + $score->{$s[$i]}{$t[$j]};
  }
  $dp2[0] = max($dp1[0] + GAP_OPEN, $dp2[0] + GAP_CONT);
  $dp1[0] = MIN_SCORE;
  my $k = MIN_SCORE;
  for my $j (0 .. $#t) {
    $k = max($k, $dp1[$j] - $j * GAP_CONT, $dp2[$j] - $j * GAP_CONT);
    $dp1[$j + 1] = max($dp1[$j + 1], $k + GAP_OPEN + $j * GAP_CONT);
  }
}
print max($dp1[-1], $dp2[-1]), "\n";

