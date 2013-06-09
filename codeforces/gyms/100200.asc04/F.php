<?php
if (getenv('USER') == 'watashi') {
  $STDIN = STDIN;
} else {
  $STDIN = fopen('positive.in', 'r');
  $STDOUT = fopen('positive.out', 'w');
  ob_start(function($buffer) {
    global $STDOUT;
    fwrite($STDOUT, $buffer);
  });
}

$n = fgets($STDIN) + 0;
$a = fgets($STDIN);
foreach (explode(' ', $a) as $i) {
  if ($i < 0) {
    $n -= 2;
  }
}
echo max($n, 0), "\n";
