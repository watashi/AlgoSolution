#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int a, b, c, d, n, x, y;

	scanf("%d", &n);
	a = b = c = d = -0x80000000;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x, &y);
		a = max(a, x + y);
		b = max(b, x - y);
		c = max(c, y - x);
		d = max(d, -x - y);
	}
	printf("%d\n", a + b + c + d + 4);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//229408 	Dec 24, 2010 11:15:48 AM 	watashi 	C - Happy Farm 5 	GNU C++ 	Accepted 	80 ms 	1292 KB
