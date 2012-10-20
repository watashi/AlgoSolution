#!/usr/bin/perl

use strict;
use warnings;

my $digits = <STDIN>;
$digits =~ s/\D//g;

my $n = <STDIN>;
my @a = ();
for (1 .. $n) {
  chomp($_ = <STDIN>);
  eval "tr/$digits/0-9/";
  push @a, $_;
}

@a = sort { $a <=> $b } @a;
for (@a) {
  eval "tr/0-9/$digits/";
  print "$_\n";
}
