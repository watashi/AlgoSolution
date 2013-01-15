#!/usr/bin/perl

use strict;
use warnings;

package Node {
  sub new {
    my $class = shift;
    my $ret = {
      parent => undef,
      children => [],
    };
    bless $ret, $class;
    $ret;
  }

  sub set_parent {
    my ($self, $parent, $off, $len) = @_;
    $self->parent($parent);
    $self->off($off);
    $self->len($len);
  }

  sub add_child {
    my ($self, $child) = @_;
    push $self->children, $child;
  }

  sub AUTOLOAD {
    my $self = shift;
    my $name = $Node::AUTOLOAD =~ s/.*://r;
    return if $name eq 'DESTROY';
    $self->{$name} = shift if @_;
    return $self->{$name};
  }
}

sub dfs {
  my $p = shift;
  $p->count(@{$p->children} ? 0 : 1);
  for my $c (@{$p->children}) {
    $c->depth($p->depth + $c->len);
    dfs($c);
    $p->count($p->count + $c->count);
  }
}

sub show {
  my ($p, $s) = @_;
  my $lambda = sub {
    use feature 'current_sub';
    my $p = shift;
    if ($p->parent) {
      __SUB__->($p->parent);
      print substr($s, $p->off, $p->len);
    }
  };
  $lambda->($p);
  print "\n";
}

chomp(my $s = <>);
chomp(my $k = <>);
my %node = ();

while (<>) {
  my ($p, $c, $off, $len) = split;
  $p = ($node{$p} ||= Node->new);
  $c = ($node{$c} ||= Node->new);
  $c->set_parent($p, $off - 1, $len);
  $p->add_child($c);
}

my $root = undef;
for my $p (values %node) {
  $root = $p unless $p->parent;
}
$root->depth(0);
dfs($root);

my $best = undef;
for my $p (values %node) {
  $best = $p if $p->count >= $k && (!$best || $p->depth > $best->depth);
}
show($best, $s);
