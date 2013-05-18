#!/usr/bin/perl
undef $/;
@a = ();
for $file (@ARGV) {
	open FH, "<$file";
	$_ = <FH>;
	$i = 0;
	$s = 0;
	while (/Score\s*=\s*(.*)/g) {
		$a[$i++] .= $1 . ' ';
		$s += $1;
	}
	$a[$i] .= $s . ' ';
}
for (@a) {
	@_ = split;
	for $i (reverse (1 .. $#_)) {
		$_[$i] -= $_[$i - 1];
	}
	$_ = join("\t", @_);
}
print join("\n", @a), "\n";
