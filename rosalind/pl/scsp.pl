#!/usr/bin/perl

use strict;
use warnings;
use Algorithm::Diff 'traverse_sequences';

chomp(my $s = <>);
chomp(my $t = <>);
my @s = split //, $s;
my @t = split //, $t;

traverse_sequences(\@s, \@t, {
    MATCH => sub { print $s[$_[0]] },
    DISCARD_A => sub { print $s[$_[0]] },
    DISCARD_B => sub { print $t[$_[1]] }
  });
print "\n";
