#!/usr/bin/perl

use strict;
use warnings;
use Inline 'CPP';
use List::Util 'min';
use List::MoreUtils 'pairwise';

our ($a, $b);

my @fact = (1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800);

sub getp {
  my @p = map { --$_ } split ' ', <>;
  my $m = (1 << @p) - 1;
  my $k = 0;
  for my $i (0 .. $#p) {
    $k += popcount($m & ((1 << $p[$i]) - 1)) * $fact[$#p - $i];
    $m ^= 1 << $p[$i];
  }
  return $k;
}

sub bfs4 {
  my @d = (9) x 3628800;
  my @q = ();
  $d[$_] = 0 for (@_);
  push @q, @_;

  my $h = 0;
  while ($h < @q) {
    my $s = $q[$h++];
    my $d = $d[$s] + 1;
    last if $d > 4;
    my @t = grep { $d[$_] > $d } gao(10, $s);
    $d[$_] = $d for (@t);
    push @q, @t;
  }
  return @d;
}

my @ans;
do {
  my @s = bfs4(getp);
  my @t = bfs4(getp);
  push @ans, min pairwise { $a + $b } @s, @t;
} while (<>);
print "@ans\n";

__DATA__
__CPP__

#include <algorithm>

using namespace std;

const int FACT[11] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};

int popcount(int n) {
  return __builtin_popcount(n);
}

int encode(int n, const int a[]) {
  int m = (1 << n) - 1, k = 0;
  for (int i = 0; i < n; ++i) {
    k += __builtin_popcount(m & ((1 << a[i]) - 1)) * FACT[n - 1 - i];
    m ^= 1 << a[i];
  }
  return k;
}

void decode(int n, int k, int a[]) {
  bool b[32];
  fill(b, b + n, true);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; ; ++j) {
      if (b[j]) {
        if (k < FACT[n - 1 - i]) {
          a[i] = j;
          b[j] = false;
          break;
        } else {
          k -= FACT[n - 1 - i];
        }
      }
    }
  }
}

void gao(int n, int s) {
  static int a[32];
  decode(n, s, a);
  Inline_Stack_Vars;
  Inline_Stack_Reset;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      reverse(a + i, a + j);
      Inline_Stack_Push(newSViv(encode(n, a)));
      reverse(a + i, a + j);
    }
  }
  Inline_Stack_Done;
}

