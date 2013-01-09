#!/usr/bin/perl

my $s = <>;
my $t = <>;
my @p = ();
chomp($s, $t);
while ($s =~ /(?=$t)/g) {
  my $p = pos $s;
  push @p, $p;
}
@p = map { $_ + 1 } @p;
print "@p\n";
