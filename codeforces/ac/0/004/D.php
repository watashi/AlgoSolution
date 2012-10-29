<?php

class Envelope {
	public $w, $h, $i, $p;
	public function __construct($w, $h, $i) {
		$this->w = $w;
		$this->h = $h;
		$this->i = $i;
		$this->p = NULL;
	}
}

function cmp($a, $b) {
	if ($a->w != $b->w) {
		return $a->w < $b->w ? -1 : 1;
	} else if ($a->h != $b->h) {
		return $a->h > $b->h ? -1 : 1;
	} else {
		return 0;
	}
}

fscanf(STDIN, "%d%d%d", $n, $w, $h);
$a = Array();
for ($i = 1; $i <= $n; ++$i) {
	fscanf(STDIN, "%d%d", $wi, $hi);
	if ($wi > $w && $hi > $h) {
		array_push($a, new Envelope($wi, $hi, $i));
	}
}

usort($a, 'cmp');
$b = Array();
foreach ($a as $ai) {
	$l = 0;
	$r = count($b);
	while ($l < $r) {
		$m = ($l + $r) / 2;
		if ($ai->h > $b[$m]->h) {
			$l = $m + 1;
		} else {
			$r = $m;
		}
	}
	$ai->p = ($r == 0 ? NULL : $b[$r - 1]);
	$b[$r] = $ai;
}

echo count($b) . "\n";
if (count($b) > 0) {
	$c = Array();
	for ($p = array_pop($b); $p != NULL; $p = $p->p) {
		array_unshift($c, $p->i);
	}
	print implode($c, ' ') . "\n";
}

/*
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
200597 	Nov 29, 2010 10:10:00 PM 	watashi 	D - Mysterious Present 	PHP 	Accepted 	1590 ms 	7648 KB 
*/
