#include <cstdio>

int main() {
	int n, p = 0;

	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		p = (p + i) % n;
		printf("%d%c", p + 1, i == n - 1 ? '\n' : ' ');
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//208604 	Dec 5, 2010 7:45:25 PM 	watashi 	A - Ball Game 	GNU C++ 	Accepted 	30 ms 	1292 KB 

