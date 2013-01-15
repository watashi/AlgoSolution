#!/usr/bin/perl

use strict;
use warnings;

my @trie = ({});
while (<>) {
  my $p = $trie[0];
  while (/\w/g) {
    unless (exists $p->{$&}) {
      push @trie, {};
      $p->{$&} = $#trie;
    }
    $p = $trie[$p->{$&}];
  }
}

for my $i (0 .. $#trie) {
  while (my ($k, $v) = each %{$trie[$i]}) {
    printf "%d %d %s\n", $i + 1, $v + 1, $k;
  }
}
