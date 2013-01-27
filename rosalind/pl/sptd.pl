#!/usr/bin/perl

use strict;
use warnings;
no warnings 'recursion';
use Bio::TreeIO;
use Bit::Vector::Overload;

my @leaf = split ' ', <>;
my %leaf = ();
for my $i (0 .. $#leaf) {
  $leaf{$leaf[$i]} = $i;
}

my $treeio = Bio::TreeIO->new(-format => 'newick', -input => \*ARGV);
my $t1 = $treeio->next_tree;
my $t2 = $treeio->next_tree;

sub dfs {
  my ($p, $q) = @_;
  my $s = Bit::Vector->new(scalar @leaf);
  $s ^= $leaf{$p->id} if defined($p->id);
  for my $i ($p->each_Descendent) {
    $s ^= dfs($i, $q);
  }
  $q->{$s & 0 ? $s : ~$s} = 1;
  return $s;
}

my ($s1, $s2) = ({}, {});
dfs($t1->get_root_node, $s1);
dfs($t2->get_root_node, $s2);
my $ans = keys(%$s1) + keys(%$s2);
for my $k (keys %$s1) {
  $ans -= 2 if exists $s2->{$k};
}
print "$ans\n";
