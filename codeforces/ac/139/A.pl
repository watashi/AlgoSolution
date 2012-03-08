$n = <>;
$_ = <>;
@_ = split;
$i = -1;
$n -= $_[++$i % 7] while $n > 0;
print $i % 7 + 1;
