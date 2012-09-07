use Math::BigInt only => 'GMP', ':constant';
$d = 10 ** 108;
$t = $d * $d;
@a = (undef);
@c = (1, 1);
for $n (1 .. 100) {
    $s = 2 * $d;
    @b = ();
    for $i (1 .. $n - 1) {
        push @b, $c[$i - 1] + $c[$i];
        $s += ($t / $b[-1])->bsqrt();
    }
    @c = (1, @b, 1);
    push @a, substr(($s * $d)->bround(101), 0, 101);
    $a[-1] =~ s/./$&\./;
}
print "$a[$_]\n" while (<>);

# 2012-09-07 15:56:47 | Accepted | 3445 | Perl | 1450 | 1208 | watashi | Source
