int main() {
	constant in = Stdio.stdin;
	in->gets();
	array(int) a = (array(int))(in->gets() / ",");
	int b = 1;
	foreach (a, int i) {
		foreach (a, int j) {
			if (i % j != 0 && j % i != 0) {
				b = 0;
			}
		}
	}
	write((b ? "" : "NOT ") + "FRIENDS");
	return 0;
}
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//669387 	Sep 5, 2011 5:35:14 PM 	watashi 	100B - Friendly Numbers 	Pike 	Accepted 	190 ms 	6500 KB
