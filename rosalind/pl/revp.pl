#!/usr/bin/perl

use strict;
use warnings;

my $str = <>;
my $end = length($str);
for my $off (0 .. $end - 1) {
  for my $len (4 .. 12) {
    if ($off + $len <= $end) {
      my $tmp = substr($str, $off, $len);
      my $rev = reverse($tmp);
      $rev =~ y/ACGT/TGCA/;
      printf "%d %d\n", $off + 1, $len if $tmp eq $rev;
    }
  }
}
