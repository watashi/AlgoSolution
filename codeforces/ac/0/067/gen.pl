@a = qw(L L L L L L L L R R R R R R R R =);
for (1 .. 999) {
	print $a[rand(@a)];
}
