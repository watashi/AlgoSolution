#!/usr/bin/perl

use strict;
use warnings;

$_ = <>;
@_ = split;
for (@_) {
  $_ = 1 - sqrt($_);
  $_ = 1 - $_ * $_;
}
print "@_\n";
