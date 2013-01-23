#!/usr/bin/perl

use strict;
use warnings;
# use constant LIMIT => 2012;
# use diagnostics -verbose;
# no warnings 'recursion';

chomp(my $s = <>);
my $n = length $s;

my $den = 0;
for my $i (1 .. $n) {
  my $j = $n + 1 - $i;
  if ((4 ** $i) < $j) {
    $den += 4 ** $i;
  } else {
    $den += (1 + $j) * $j / 2;
    last;
  }
}

=begin WA/TLE

sub dup {
  my ($limit, $todo) = @_;
  # printf "dup(%d, %s)\n", $limit, join(':', @$todo);
  my %group = ();
  for (@$todo) {
    if ($_ < @s) {
      $group{$s[$_]} //= [];
      push $group{$s[$_]}, $_ + 1;
    }
  }
  my $ret = 0;
  for (values %group) {
    if ($#$_ > 0) {
      $ret += $#$_;
      $ret += dup($limit - 1, $_) if $limit > 0;
    }
  }
  $ret;
}

my $m = (1 + @s) * @s / 2 - dup(LIMIT, [0 .. $#s]);
# print "$m / $n\n";
print $m / $n, "\n";

=cut

use List::Util 'sum';
use Inline CPP => 'DATA';

my $sa = SuffixArray->new;
$sa->init($n, $s);
my @height = $sa->get_height();
my $num = (1 + $n) * $n / 2 - sum @height;

# print "$num/$den\n";
print $num / $den, "\n";

__DATA__
__CPP__

#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 20;

pair<int, int> suffix[MAXN];

bool _cmp(int i, int j) {
  return suffix[i] < suffix[j];
}

void _return(int n, const int* a) {
  inline_stack_vars;
  inline_stack_reset;
  for (int i = 0; i < n; ++i) {
    inline_stack_push(newSViv(a[i]));
  }
  inline_stack_done;
}

struct SuffixArray {
  int n, sa[MAXN], rank[MAXN], height[MAXN], h[MAXN];

  void init(int n, const char* a) {
    this->n = n;
    sa[0] = 0;
    for (int i = 0; i < n; ++i) {
      rank[i] = a[i];
    }
    for (int m = 1; m < n; m <<= 1) {
      for (int i = 0; i < n; ++i) {
        sa[i] = i;
        suffix[i] = make_pair(rank[i], i + m < n ? rank[i + m] : -1);
      }
      sort<int*>(sa, sa + n, _cmp);
      for (int i = 0; i < n; ++i) {
        if (i == 0 || (suffix[sa[i]] != suffix[sa[i - 1]])) {
          rank[sa[i]] = i;
        } else {
          rank[sa[i]] = rank[sa[i - 1]];
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      if (rank[i] == 0) {
        h[i] = 0;
      } else {
        int x = i, y = sa[rank[i] - 1], z = max(0, h[i - 1] - 1);
        while (x + z < n && y + z < n && a[x + z] == a[y + z]) {
          ++z;
        }
        h[i] = z;
      }
    }
    for (int i = 0; i < n; ++i) {
      height[i] = h[sa[i]];
    }
  }

  void get_sa()     { _return(n, sa);     }
  void get_rank()   { _return(n, rank);   }
  void get_height() { _return(n, height); }
};

