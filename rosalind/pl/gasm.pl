#!/usr/bin/perl

use strict;
use warnings;
use Rosalind 'revc';
use constant CHARSET => qw(A C G T);
no warnings 'recursion';

sub dfs {
  my ($v, $d) = @_;
  for my $w (map { substr($v, 1) . $_ } CHARSET) {
    next unless exists $d->{$w};
    my $p = $d->{$w};
    $d->{$w} = $v;
    my $t = $p ? $v : dfs($w, $d);
    return $t if $t;
    delete $d->{$w};
  }
  return undef;
}

chomp(my @s = <>);
push @s, map { revc $_ } @s;

for my $k (reverse 0 .. length($s[0])) {
  my %v = ();
  for my $s (@s) {
    for my $i ($k .. length($s)) {
      $v{substr($s, $i - $k, $k)} = undef;
    }
  }
  my $v = each %v;
  $v = dfs($v, \%v);
  if ($v) {
    my @v = (substr($v, -1));
    for (my $w = $v{$v}; $w ne $v; $w = $v{$w}) {
      push @v, substr($w, -1);
    }
    print join('', reverse @v), "\n";
    last;
  }
}
