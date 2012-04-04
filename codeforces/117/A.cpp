#include <cstdio>

int gao(int n, int k, int t) {
	int m = 2 * (n - 1);
	int x = t / m * m;
	int y = t % m;
	if (k >= 1 + y) {
		x += k - 1;
	} else if (k <= n - (y - (n - 1))) {
		x += (n - 1) + (n - k);
	} else {
		x += m + k - 1;
	}
	return x;
}

int main() {
	int n, m, a, b, c;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		if (a != b) {
			c = gao(m, a, c);
			c = gao(m, b, c);
		}
		printf("%d\n", c);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//735754 	Oct 3, 2011 3:56:03 PM 	watashi 	117A - Elevator 	GNU C++0x 	Accepted 	170 ms 	1300 KB
//735753 	Oct 3, 2011 3:55:51 PM 	watashi 	117A - Elevator 	GNU C++ 	Accepted 	170 ms 	1300 KB 
