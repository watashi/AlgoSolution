use strict;
use warnings;

my $n = <STDIN>;
my %h = ();
for (1 .. $n) {
  $_ = <STDIN>;
  ++$h{$_};
}
my $m = 0;
for (values %h) {
  $m = $_ if $_ > $m;
}
print "$m\n";
