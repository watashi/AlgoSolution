#!/usr/bin/perl

use strict;
use warnings;

INIT {
  if ($ENV{'USER'} ne 'watashi') {
    open STDIN, '<', 'positive.in';
    open STDOUT, '>', 'positive.out';
  }
}

my $n = <STDIN>;
my $s = <STDIN>;
$n -= 2 * ($s =~ y/-/-/);
$n = 0 if $n < 0;
print "$n\n";
