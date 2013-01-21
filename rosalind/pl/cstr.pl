#!/usr/bin/perl

chomp(my @s = <>);
my @c = split //, $s[0];
my %t = ();
for my $i (0 .. $#c) {
  my $t = join('', map { substr($_, $i, 1) eq $c[$i] ? 1 : 0 } @s);
  $t{$t} = 1;
}
for (keys %t) {
  print "$_\n" if y/1/1/ > 1 && y/0/0/ > 1;
}
