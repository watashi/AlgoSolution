#!/usr/bin/perl

use strict;
use warnings;
use Rosalind qw(%codon %nodoc revc);
use List::MoreUtils 'uniq';

my $re = '';
$re .= '(?:' . join('|', @{$nodoc{M}}) . ')';
$re .= '(?:\w{3})*?';
$re .= '(?:' . join('|', @{$nodoc{0}}) . ')';

chomp($_ = <>);
$_ = $_ . ':' . revc($_);
s/T/U/g;
while (/(?=($re))/g) {
  local $_ = $1;
  s/\w{3}/$codon{$&}/ge;
  s/0$//;
  push @_, $_;
}
@_ = uniq @_;
print join("\n", @_), "\n";

