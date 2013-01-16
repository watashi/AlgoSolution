#!/usr/bin/perl

use strict;
use warnings;
use Bio::TreeIO;

my %ans = ();

sub dfs {
  my ($n, $v, $p) = @_;
  my $s = '0' x $n;
  substr($s, $v->id, 1) = '1' if defined($v->id);
  for my $i ($v->each_Descendent(), $v->ancestor()) {
    if ($i && (!$p || $i != $p)) {
      $s |= dfs($n, $i, $v);
    }
  }
  $ans{$s} = 1;
  return $s;
}

my $tree = Bio::TreeIO->new(-format => 'newick', -string => scalar <>)->next_tree;
my @node = grep { defined $_->id } $tree->get_nodes;
my $n = 0;
for my $node (sort { $a->id cmp $b->id } @node) {
  $node->id($n++);
}
dfs($n, $tree->get_root_node);
for my $i (keys %ans) {
  my $m = $i =~ y/0/0/;
  print "$i\n" if 1 < $m && $m < $n - 1;
}
