#!/usr/bin/perl
push @ARGV, 'log' unless @ARGV;
$s = 0;
while (<>) {
	if (/^Score = (.*)/) {
		print "+ $1\n";
		$s += $1;
	}
}
print "= $s\n";
