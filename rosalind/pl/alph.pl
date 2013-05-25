#!/usr/bin/perl

use strict;
use warnings;
use Bio::TreeIO;
use List::Util qw(max first);
use Rosalind 'fasta';

sub dfs {
  my ($n, $v) = @_;
  return if $v->is_Leaf;

  my @cnt = ();
  for my $w ($v->each_Descendent) {
    dfs($n, $w);
    my @dna = $w->get_tag_values('dna');
    for my $i (0 .. $n - 1) {
      for (split //, $dna[$i]) {
        ++$cnt[$i]{$_};
      }
    }
  }

  my @dna = ();
  for my $i (0 .. $n - 1) {
    my $v = max values $cnt[$i];
    my $k = join '', grep { $cnt[$i]{$_} == $v } keys $cnt[$i];
    push @dna, $k;
  }
  $v->set_tag_value('dna', @dna);
}

sub gao {
  my ($n, $v) = @_;

  my @a = $v->get_tag_values('dna');
  my @b = $v->ancestor ? $v->ancestor->get_tag_values('dna') : ('?') x $n;
  my $ret = 0;
  for my $i (0 .. $n - 1) {
    if (index($a[$i], $b[$i]) >= 0) {
      $a[$i] = $b[$i];
    } else {
      $a[$i] = substr($a[$i], 0, 1);
      ++$ret;
    }
  }
  $v->set_tag_value('dna', @a);

  for my $w ($v->each_Descendent) {
    $ret += gao($n, $w);
  }
  return $ret;
}

chomp(my $tree = <>);
my $treeio = Bio::TreeIO->new(-format => 'newick', -string => $tree);
$tree = $treeio->next_tree;

undef $/;
my %fasta = fasta(scalar <>);
for my $node ($tree->get_nodes) {
  if (exists $fasta{$node->id}) {
    $node->set_tag_value('dna', split(//, $fasta{$node->id}));
  }
}

my $n = max map { length } values %fasta;
dfs($n, $tree->get_root_node);
print gao($n, $tree->get_root_node) - $n, "\n";
for my $node ($tree->get_nodes) {
  unless ($node->is_Leaf) {
    my $id = $node->id;
    my $ans = join '', $node->get_tag_values('dna');
    print ">$id\n$ans\n";
  }
}

