$t = <>;
for (1 .. $t) {
  $g = <>;
  for (1 .. $g) {
    $_ = <>;
    ($i, $n, $q) = split;
    ++$n if $i != $q;
    print int($n / 2), "\n";
  }
}
