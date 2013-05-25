#!/usr/bin/perl

use strict;
use warnings;

sub euler {
  my ($g, $v) = @_;
  if (exists $g->{$v}) {
    my @ret = ();
    for my $w (keys $g->{$v}) {
      unless (--$g->{$v}{$w}) {
        delete $g->{$v}{$w};
        delete $g->{$v} unless %{$g->{$v}};
      }
      for (euler($g, $w)) {
        push $_, $v;
        push @ret, $_;
      }
      ++$g->{$v}{$w};
    }
    return @ret;
  } else {
    return %$g ? () : ([]);
  }
}

chomp(my @e = <>);
my $k = length($e[0]) - 1;

my @v = ();
my %v = ();
for my $e (@e) {
  $v{substr($e, 0, $k)} = 1;
  $v{substr($e, 1)} = 1;
}
my $n = 0;
for my $v (keys %v) {
  push @v, $v;
  $v{$v} = $n++;
}

my %g = ();
for my $e (@e) {
  my $s = $v{substr($e, 0, $k)};
  my $t = $v{substr($e, 1)};
  ++$g{$s}{$t};
}

my @ans = euler(\%g, $v{substr($e[0], 0, $k)});
@ans = map { join '', map { substr($v[$_], 0, 1) } reverse @$_ } @ans;
@ans = grep { /^$e[0]/ } @ans;
print join("\n", @ans), "\n";
