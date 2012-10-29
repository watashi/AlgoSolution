if ($ENV{USER} ne 'watashi') {
  push @ARGV, 'input.txt';
  open STDOUT, '>output.txt';
}

$n = <>;
$_ = <>;
$y = y/-/-/;
@a = grep {$_} split;
$y += $n - @a;
pop @a;

($m, $x) = ($n, 0);
for (@a) {
  $y += /-/ ? -1 : 1;
  $m = $y if $y < $m;
}
print $m;
