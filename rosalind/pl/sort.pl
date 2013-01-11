#!/usr/bin/perl

use strict;
use warnings;
use Inline 'CPP';
use List::Util 'min';
use List::MoreUtils 'pairwise';

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

my $s = getp;
my $t = getp;
my @tab = gao(10, $t);
my @ans = ();
while ($s != $t) {
  push @ans, $tab[$s * 2 + 1];
  $s = $tab[$s * 2];
}
print scalar @ans, "\n";
for (@ans) {
  printf "%d %d\n", ($_ >> 16) + 1, $_ & 0xFF;
}

__DATA__
__CPP__

#include <cstring>
#include <algorithm>

using namespace std;

const int FACT[11] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};

struct array {
  int a[3628800];
  array() { memset(a, 0xff, sizeof(a)); }
  int get(int i) { return a[i]; }
  void set(int i, int j) { a[i] = j; }
};

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
  static bool b[32];
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
  static int p[3628800];
  static int q[3628800];
  static int r[3628800];
  int head = 0, tail = 0;

  fill(p, p + FACT[n], -1);
  p[s] = s;
  q[tail++] = s;
  while (head < tail) {
    int s = q[head++];
    decode(n, s, a);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        reverse(a + i, a + j);
        int t = encode(n, a);
        if (p[t] == -1) {
          p[t] = s;
          r[t] = (i << 16) ^ j;
          q[tail++] = t;
        }
        reverse(a + i, a + j);
      }
    }
  }

  Inline_Stack_Vars;
  Inline_Stack_Reset;
  for (int i = 0; i < FACT[n]; ++i) {
    Inline_Stack_Push(newSViv(p[i]));
    Inline_Stack_Push(newSViv(r[i]));
  }
  Inline_Stack_Done;
}

