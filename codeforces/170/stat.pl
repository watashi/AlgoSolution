#!/usr/bin/perl -w

use strict;
use warnings;
use List::Util 'reduce';

undef $/;
$_ = <>;
my @case = ();
while (/(.*?)\e\[1;34m(.*?)\e\[0m/sg) {
    my ($stderr, $result) = ($1, $2);
    my %case = ();
    $case{id} = $#case + 2;
    $case{real} = $1 if $stderr =~ /real\s+0m([\d.]+)s/;
    $case{user} = $1 if $stderr =~ /user\s+0m([\d.]+)s/;
    if ($stderr =~ /score\s+=\s+(\d+);\s+counter\s+=\s+((?!0)\d+)/) {
        $case{score} = $1;
        $case{counter} = $2;
    }
    if ($result =~ /points=([\d.]+),\s+w=(\d+),\s+h=(\d+),\s+n=(\d+)/) {
        $case{points} = int($1 * 10 + 0.5);
        $case{w} = $2;
        $case{h} = $3;
        $case{n} = $4;
    }
    push @case, \%case;
}

#for my $case (@case) {
#    printf "#%d: %dx%d @%d => %d (%f)\n",
#        $case->{id}, $case->{w}, $case->{h}, $case->{n}, $case->{score}, $case->{user};
#}

print "total: ", scalar @case, "\n";
my @fail = grep { not exists $_->{points} or $_->{points} != $_->{score} } @case;
print "fail: ", scalar @fail, "\n";

sub maxby($@) {
    my ($key, @arr) = @_;
    $_ = reduce { $a->{$key} > $b->{$key} ? $a : $b } @arr;
    return $_->{$key};
}

print "maxreal: ", maxby('real', @case) , "\n";
print "maxuser: ", maxby('user', @case) , "\n";
print "maxn: ", maxby('n', @case) , "\n";
