#!/usr/bin/perl

use strict;
use warnings;
use Bio::TreeIO;

my @geno = ([0], [0, 1], [1]);

sub gao {
  my $tree = shift;
  my @ret = (0, 0, 0);
  if ($tree->id) {
    ++$ret[$tree->id =~ y/a/a/];
  } else {
    my ($l, $r) = $tree->each_Descendent;
    my @l = gao($l);
    my @r = gao($r);
    for my $i (0 .. $#l) {
      for my $j (0 .. $#r) {
        for my $ii (@{$geno[$i]}) {
          for my $jj (@{$geno[$j]}) {
            $ret[$ii + $jj] += ($l[$i] * $r[$j]) / (@{$geno[$i]} * @{$geno[$j]});
          }
        }
      }
    }
  }
  @ret;
}

chomp(my $tree = <>);
$tree = Bio::TreeIO->new(-format => 'newick', -string => $tree)->next_tree;
print "@${\[gao($tree->get_root_node)]}\n";
