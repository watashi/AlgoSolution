$_ = <>;
($n, $m) = split;
$_ = <>;
@_ = split;
($l, $r) = (0, 0);
$_{$_[$r++]} += 1 while $r < @_ && keys %_ < $m;

if (keys %_ < $m) {
    print '-1 -1';
} else {
    $_{$_[$l++]} -= 1 while $_{$_[$l]} > 1;
    ++$l;
    print "$l $r";
}
