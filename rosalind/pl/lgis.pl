#!/usr/bin/perl

use strict;
use warnings;

sub lis (&\@) {
  my ($lt, $a) = @_;
  my ($caller_a, $caller_b) = do {
    my $pkg = caller;
    no strict 'refs';
    (\*{$pkg . '::a'}, \*{$pkg . '::b'});
  };

  my @dp = ();
  my @pre = ();
  for my $i (0 .. $#$a) {
    my ($l, $r) = (0, scalar @dp);
    while ($l < $r) {
      my $m = int(($l + $r) / 2);
      (*$caller_a, *$caller_b) = \($$a[$dp[$m]], $$a[$i]);
      if ($lt->()) {
        $l = $m + 1;
      } else {
        $r = $m;
      }
    }
    if ($r < @dp) {
      (*$caller_a, *$caller_b) = \($$a[$i], $$a[$dp[$r]]);
      next unless $lt->();
    }
    $dp[$r] = $i;
    $pre[$i] = $r == 0 ? -1 : $dp[$r - 1];
  }
  my @ret = ();
  for (my $i = $dp[-1]; $i >= 0; $i = $pre[$i]) {
    push @ret, $i;
  }
  return @$a[reverse @ret];
}

chomp(my $n = <>);
my @a = split ' ', <>;
print join(' ', lis { $a < $b } @a), "\n";
print join(' ', lis { $b < $a } @a), "\n";
