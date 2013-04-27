#!/usr/bin/perl

use strict;
use warnings;

local $" = '';

sub gen {
  my ($n, $m, @a) = @_;
  my @ret = ();
  if ($n == 0) {
    push @ret, [@a];
  } else {
    for my $i (2 .. $m) {
      push @ret, gen($n - 1, $i, @a, $i);
    }
  }
  @ret;
}

chomp(my $re = <>);
for my $ri (1 .. $re) {
  print "Case #$ri:\n";
  my ($r, $n, $m, $k) = split ' ', <>;
  # print "$n $m $k";
  my @todo = gen($n, $m);

  my %tab = ();
  my %prod = ();
  for (@todo) {
    my @a = @$_;
    my $c = 1 << $n;
    for my $i (0 .. $c - 1) {
      my $p = 1;
      for my $j (0 .. $n - 1) {
        $p *= $a[$j] if $i & (1 << $j);
      }
      $tab{"@a"}{$p} += 1 / $c;
      $prod{$p} = 1;
    }
  }

  for (1 .. $r) {
    my @res = split ' ', <>;
    my %res = ();
    for (@res) {
      $res{$_} += 1 / $k;
    }
    # while (my ($k, $v) = each %res) {
    #  print "$k => $v\n";
    # }

    my ($guess, $score) = ('', 100);
    while (my ($k, $v) = each %tab) {
      my $s = 0;
      for my $p (keys %prod) {
        my $x = $res{$p} // 0;
        my $y = $v->{$p} // 0;
        if ($x > 0 && $y == 0) {
          $s = 100;
          last;
        } else {
          $s += ($x - $y) ** 2;
        }
      }
      # print "$k: $s\n";
      ($guess, $score) = ($k, $s) if $s < $score;
    }
    print "$guess\n";
  }
}
