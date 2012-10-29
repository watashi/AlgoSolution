int read() {
	return (int)Stdio.stdin->gets();
}

int main() {
	array(int) a = ({1});
	int n = read();
	for (int i = 0; i < n; ++i) {
		int b = read();
		a += ({0});
		for (int j = i; j >= 0; --j) {
			a[j + 1] += a[j];
			a[j] *= b;
		}
	}
	for (int i = n; i >= 0; --i) {
		if (a[i] != 0) {
			if (a[i] < 0) {
				write("-");
			} else if (i < n) {
				write("+");
			}
			if (i == 0) {
				write("%d", abs(a[i]));
			} else if (abs(a[i]) != 1) {
				write("%d*", abs(a[i]));
			}
			if (i > 0) {
				write("X");
				if (i > 1) {
					write("^%d", i);
				}
			}
		}
	}
	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//669425 	Sep 5, 2011 5:48:52 PM 	watashi 	100F - Polynom 	Pike 	Accepted 	130 ms 	6500 KB 
