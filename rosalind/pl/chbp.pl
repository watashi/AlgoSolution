#!/usr/bin/perl

use strict;
use warnings;
use IO::Scalar;
use Bio::TreeIO;
use Bio::Tree::Node;
use Bio::Tree::Tree;

sub complete {
  $_[0] ^ $_[1] ^ ('0' x length($_[1]));
}

my @leaf = split ' ', <>;
chomp(my @split = <>);
for (@split) {
  y/01/10/ if /^1/;
}

my %tree = ();
for my $i (0 .. $#leaf) {
  my $mask = '0' x @leaf;
  substr($mask, $i, 1) = '1';
  $tree{$mask} = Bio::Tree::Node->new(-id => $leaf[$i]);
}

for my $i (sort { ($a =~ y/1/1/) <=> ($b =~ y/1/1/) } @split) {
  for my $j (keys %tree) {
    if (($i & $j) eq $j && exists $tree{complete($i, $j)}) {
      $tree{$i} = Bio::Tree::Node->new(-descendents =>
        [delete @tree{$j, complete($i, $j)}]);
      last;
    }
  }
}

my $tree = Bio::Tree::Tree->new(-root =>
  Bio::Tree::Node->new(-descendents => [values %tree]));
my $io = IO::Scalar->new;
my $treeio = Bio::TreeIO->new(-format => 'newick', -input => $io);
$treeio->write_tree($tree);
print "${$io->sref}\n";
