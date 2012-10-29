$n = <>;
$_ = <>;
@a = (0, split);
for (0 .. $n) {
    $b[$a[$_]] = $_;
}
print "@b[1 .. $n]";
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1127827 	Jan 31, 2012 9:46:14 AM 	watashi 	136A - Presents 	Perl 	Accepted 	50 ms 	1200 KB
