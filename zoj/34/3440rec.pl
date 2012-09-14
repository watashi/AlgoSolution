#!/usr/bin/perl -w

use strict;
use warnings;

our (%rule, %regex);

sub regex {
    local $_ = shift;
    unless (exists $regex{$_}) {
        my $expr = qq["(?:$rule{$_})"];
        $expr =~ s/\[(\w*?)\]/$${\\regex($1)}/g;
        $regex{$_} = eval $expr or die;
    }
    $regex{$_};
}

do {
    chomp(my $n = <>);
    %rule = %regex = ();
    for (my $i = 0; $i < $n; ++$i) {
        chomp($_ = <>);
        /:=/ and $rule{$`} = $' or die;
    }
    my $virus = regex('virus');

    chomp(my $m = <>);
    for (my $i = 0; $i < $m; ++$i) {
        chomp($_ = <>);
        print /$virus/ ? "YES\n" : "NO\n";
    }
    print "\n";
} while (<>);

# 2012-09-07 15:55:32 | Accepted | 3440 | Perl | 220 | 544 | watashi | Source
