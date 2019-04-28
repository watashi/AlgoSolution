#!/usr/bin/perl

open FL, "<$ARGV[0]";
open FR, "<$ARGV[1]";
my ($ac, $total) = (0, 0);
while (<FL>) {
  ++$total;
  ++$ac if <FR> eq $_;
}
print "$ac / $total";

