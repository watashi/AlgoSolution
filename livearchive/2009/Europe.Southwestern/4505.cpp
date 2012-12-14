#include <cstdio>

int main() {
	bool blank = false;
	int n, m, a, b;
	char op[80];

	while (scanf("%d", &n) != EOF && n > 0) {
		if (blank) {
			puts("");
		} else {
			blank = true;
		}
		a = b = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%s%d", op, &m);
			if (op[0] == 'D') {
				b += m;
				printf("DROP 2 %d\n", m);
			} else if (a >= m) {
				a -= m;
				printf("TAKE 1 %d\n", m);
			} else {
				if (a > 0) {
					m -= a;
					printf("TAKE 1 %d\n", a);
				}
				a = b;
				b = 0;
				printf("MOVE 2->1 %d\n", a);
				a -= m;
				printf("TAKE 1 %d\n", m);
			}
		}
	}

	return 0;
}
// 714990  	2011-01-04 06:30:20 	Accepted	0.004	Minimum	26909	C++	4505 - Working at the Restaurant
/*
id => 1174100
pid => 4505
pname => Working at the Restaurant
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:22:13
*/
