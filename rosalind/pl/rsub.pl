#!/usr/bin/perl

use strict;
use warnings;
use Bio::TreeIO;
use Rosalind 'fasta';

sub gao {
  my ($v, %s) = @_;
  my @c = $v->get_tag_values('dna');
  my %t = ();
  for my $i (0 .. $#c) {
    my $key = "$i $c[$i]";
    $t{$key} = $s{$key} // $v;
  }
  for (keys %s) {
    my ($i, $s, $t) = split;
    if (!defined($t)) {
      if ($c[$i] ne $s) {
        $t{"$i $s $c[$i]"} = $v;
      }
    } else {
      if ($c[$i] eq $s) {
        my $w = $s{$_};
        printf "%s %s %d %s->%s->%s\n",
          $w->id, $v->id, $i + 1, $s, $t, $s;
      } elsif ($c[$i] eq $t) {
        $t{$_} = $s{$_};
      }
    }
  }
  for my $w ($v->each_Descendent) {
    gao($w, %t);
  }
}

chomp(my $tree = <>);
my $treeio = Bio::TreeIO->new(-format => 'newick', -string => $tree);
$tree = $treeio->next_tree;

undef $/;
my %fasta = fasta(scalar <>);
for my $node ($tree->get_nodes) {
  $node->set_tag_value('dna', split(//, $fasta{$node->id}));
}

gao($tree->get_root_node);
