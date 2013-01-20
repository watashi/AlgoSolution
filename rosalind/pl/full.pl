#!/usr/bin/perl

use strict;
use warnings;
use Rosalind qw(mass spect);

my $w = <>;
my $ans = '';

my @t = sort { $a <=> $b } <>;
my @s = reverse splice @t, 0, @t / 2;
my $s = pop @s;
pop @t;

while (@s && @t) {
  if (spect($s[-1] - $s)) {
    $ans .= spect($s[-1] - $s);
    $s = pop @s;
    pop @t;
  } else {
    ($s[-1], $t[-1]) = ($t[-1], $s[-1]);
    @s = sort { $b <=> $a } @s;
    @t = sort { $a <=> $b } @t;
  }
}
print "$ans\n";

