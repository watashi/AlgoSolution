#!perl -pl

INIT {
  $_ = <>;
}

$: = y/:/:/;
s/::/':' x (9 - $:)/e if /::/;
$_ = join ':', map { '0' x (4 - length) . $_ } (split ':', $_, -1);
