#include <stdio.h>

int main(void) {
	char ch;
	int n, m, l, r, t, i;

	scanf("%d%d", &n, &m);
	l = 0;
	r = n + 1;
	for (i = 0; i < m; ++i) {
		scanf(" To the %c%*s of %d", &ch, &t);
		if (ch == 'r' && l < t) {
			l = t;
		}
		if (ch == 'l' && r > t) {
			r = t;
		}
	}
	if (r - l <= 1) {
		puts("-1");
	} else {
		printf("%d\n", r - l - 1);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//292248 	Feb 20, 2011 10:41:51 AM 	watashi 	60A - Where Are My Flakes? 	GNU C++ 	Accepted 	30 ms 	1300 KB
