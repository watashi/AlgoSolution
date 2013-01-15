#!/usr/bin/perl

use strict;
use warnings;
use Bio::TreeIO;
use List::Util 'first';

sub dis {
  my ($x, $y, $z) = @_;
  return 0 if $x == $y;
  for my $i ($x->each_Descendent(), $x->ancestor()) {
    if ($i != $z) {
      my $d = dis($i, $y, $x);
      return $d + 1 if $d >= 0;
    }
  }
  return -1;
}

my @ans = ();
while (my $tree = <>) {
  my ($x, $y) = split ' ', <>;
  my $dummy = <>;
  my $treeio = Bio::TreeIO->new(
    -format => 'newick',
    -string => $tree);
  $tree = $treeio->next_tree;
  $x = first { ($_->id // '') eq $x } $tree->get_nodes;
  $y = first { ($_->id // '') eq $y } $tree->get_nodes;
  push @ans, dis($x, $y, $x);
}
print "@ans\n";
