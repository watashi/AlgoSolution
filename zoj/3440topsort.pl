#!/usr/bin/perl -w

use strict;
use warnings;

our $regex_virus;

do {
    chomp(my $n = <>);
    my %r = ();
    for (my $i = 0; $i < $n; ++$i) {
        chomp($_ = <>);
        /:=/ and $r{$`} = {re => $', in => 0, out => {}} or die;
    }

    for (keys %r) {
        while ($r{$_}{'re'} =~ /\[(\w*?)\]/g) {
            next if exists $r{$1}{'out'}{$_};
            $r{$1}{'out'}{$_} = 1;
            ++$r{$_}{'in'};
        }
    }

    my @q = grep {$r{$_}{'in'} == 0} keys %r;
    while (@q) {
        my $s = shift @q;
        $r{$s}{'re'} =~ s/\[(\w*?)\]/\$\{regex_$1\}/g;
        {
            no strict 'vars';
            eval "our \$\{regex_$s\} = \"(?:$r{$s}{'re'})\"" or die;
        }
        for (keys %{$r{$s}{'out'}}) {
            push @q, $_ unless --$r{$_}{'in'};
        }
    }

#   print "$regex_virus\n";
    chomp(my $m = <>);
    for (my $i = 0; $i < $m; ++$i) {
        chomp($_ = <>);
        print /$regex_virus/ ? "YES\n" : "NO\n";
    }
    print "\n";
} while (<>);

# 2012-09-07 15:55:38 | Accepted | 3440 | Perl | 240 | 544 | watashi | Source
