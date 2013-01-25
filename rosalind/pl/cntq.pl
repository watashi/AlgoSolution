#!/usr/bin/perl

use strict;
use warnings;
use Bio::TreeIO;
use Math::Int64 'int64';
use constant MOD => int64(1000000);

sub choose2 {
  my $n = int64($_[0]);
  $n * ($n - 1) / 2 % MOD;
}

sub dfs {
  my $tree = shift;
  my $size = int64(defined($tree->id) ? 1 : 0);
  my $pair = int64(0);
  for ($tree->each_Descendent) {
    my $subsize = dfs($_);
    $pair += $size * $subsize;
    $size += $subsize;
  }
  $tree->set_tag_value('size', $size);
  $tree->set_tag_value('pair', $pair % MOD);
  $size;
}

sub gao {
  my ($tree, $total, $other) = @_;
  my $parent = choose2($total - $tree->get_tag_values('size')) - $other;
  my $count = $parent * $tree->get_tag_values('pair');
  my $sibling = int64(0);
  for ($tree->each_Descendent) {
    my $size2 = choose2($_->get_tag_values('size'));
    $count += $sibling * $size2;
    $sibling += $size2;
    $other += $size2;
  }
  for ($tree->each_Descendent) {
    $count += gao($_, $total, $other - choose2($_->get_tag_values('size')));
  }
  $count % MOD;
}

chomp(my $n = <>);
chomp(my $tree = <>);
$tree = Bio::TreeIO->new(-format => 'newick', -string => $tree)->next_tree;
# $tree->nodelete(1);
my $root = $tree->get_root_node;
dfs($root);
print gao($root, $n, 0), "\n";
