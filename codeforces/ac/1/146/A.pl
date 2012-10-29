use List::Util 'sum';

sub ds {
    sum split //, $_[0];
}

$l = <> >> 1;
$r = "([47]{$l})";
$_ = <>;
print /^$r$r$/ && ds($1) == ds($2) ? 'YES' : 'NO';

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1120259 	Jan 27, 2012 1:37:34 PM 	watashi 	146A - Lucky Ticket 	Perl 	Accepted 	60 ms 	1500 KB
