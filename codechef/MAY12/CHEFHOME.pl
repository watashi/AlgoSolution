#!/usr/bin/perl

use strict;
use warnings;
use Math::BigInt;

sub gao {
    my $n = scalar @_;
    if ($n % 2 != 0) {
        return Math::BigInt->bone();
    } else {
        $n /= 2;
        @_ = sort { $a <=> $b } @_;
        return Math::BigInt->new($_[$n] - $_[$n - 1] + 1);
    }
}

chomp(my $re = <STDIN>);
for my $ri (1 .. $re) {
    chomp(my $n = <STDIN>);
    my (@x, @y);
    for my $i (1 .. $n) {
        $_ = <STDIN>;
        @_ = split;
        push @x, $_[0];
        push @y, $_[1];
    }
    print gao(@x) * gao(@y), "\n";
}

# 997990 	1 min ago 	A Home for Chef	2.98	6.3M 	PERL
