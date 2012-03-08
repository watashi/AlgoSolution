string read() {
	return Stdio.stdin->gets();
}

int main() {
	read();
	array(string) a = read() / " ";
	read();
	array(string) b = read() / " ";
	mapping(int:int) c = ([]);
	foreach (b, string i) {
		++c[(int)i];
	}
	foreach (c; int i; int j) {
		if (j % 2 == 0) {
			continue;
		}
		for (int k = i - 1; k < sizeof(a); k += i) {
			a[k] = a[k] == "on" ? "off" : "on";
		}
	}
	write(a * " ");
	return 0;
}
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//669408 	Sep 5, 2011 5:41:40 PM 	watashi 	100E - Lamps in a Line 	Pike 	Accepted 	160 ms 	9300 KB
