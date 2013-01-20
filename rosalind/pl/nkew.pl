#!/usr/bin/perl

use strict;
use warnings;
use Bio::Tree::Node;
use Bio::TreeIO;
use List::Util 'first';

sub sp {
  my ($v, $t, $p) = @_;
  my @w = ();
  return 0 if $v == $t;
  for my $w ($v->each_Descendent) {
    push @w, [$w, $w->branch_length];
  }
  if ($v->ancestor) {
    push @w, [$v->ancestor, $v->branch_length];
  }
  for (@w) {
    my ($w, $e) = @$_;
    next if $w == $p;
    my $ret = sp($w, $t, $v);
    return $ret + $e if $ret != -1;
  }
  -1;
}

my @ans = ();
while (<>) {
  my $tree = Bio::TreeIO->new(-format => 'newick', -string => $_)->next_tree;
  my ($s, $t) = split ' ', <>;
  my $eof = !defined(<>);
  $s = first { ($_->id // '') eq $s } $tree->get_nodes;
  $t = first { ($_->id // '') eq $t } $tree->get_nodes;
  push @ans, sp($s, $t, $s);
  last if $eof;
}
print "@ans\n";

