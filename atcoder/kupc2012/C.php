<?php
function read_array() {
    $a = split(' ', fgets(STDIN));
    return array_map('intval', $a);
}

list($n, $m) = read_array();
$a = array();
for ($i = 0; $i < $m; ++$i) {
    $b = read_array();
    array_shift($b);
    foreach ($b as $j) {
        $a[$j] = $i;
    }
}

list($q) = read_array();
$c = array();
for ($i = 0; $i < $q; ++$i) {
    list($x, $y) = read_array();
    if ($a[$x] === $a[$y]) {
        $c[$x] = 1;
        $c[$y] = 1;
    }
}
echo count($c) . "\n";

