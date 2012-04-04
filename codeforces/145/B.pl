$_ = <>;
($a, $b, $ab, $ba) = split;
$t = $ba > $ab || $ba == $a;
($a, $b, $ab, $ba) = ($b, $a, $ba, $ab) if $t;

if ($ab == $ba + 1) {
    $s = '47' x $ab;
} elsif ($ab == $ba) {
    $s = '47' x $ab . '4';
} else {
    $a = 0;
}
$a -= $ba;
$b -= $ab - 1;

if ($t) {
    $s =~ y/47/74/;
    ($a, $b) = ($b, $a);
}

if ($a > 0 && $b > 0) {
    $s =~ s/4/'4' x $a/e;
    $s =~ s/7(?=4*$)/'7' x $b/e;
} else {
    $s = '-1';
}

print $s;
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1152080 	Feb 6, 2012 5:06:57 AM 	watashi 	145B - Lucky Number 2 	Perl 	Accepted 	230 ms 	9000 KB
