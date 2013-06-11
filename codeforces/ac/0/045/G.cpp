#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 6000;
const int MAXM = MAXN * (MAXN + 1) / 2 + 1;

bool p[MAXM];
int c[MAXN];

int main() {
	for (int i = 2; i < MAXM; ++i) {
		p[i] = !p[i];
		if (i < MAXN && p[i]) {
			for (int j = i + i; j < MAXM; j += i) {
				p[j] = true;
			}
		}
	}

	int n, s;

	scanf("%d", &n);
	s = n * (n + 1) / 2;
	fill(c + 1, c + n + 1, 1);
	if (p[s]) {
	} else if (s % 2 == 0) {
		for (int i = 3; i <= n; i += 2) {
			if (p[i] && p[s - i]) {
				c[i] = 2;
				break;
			}
		}
	} else if (p[s - 2]) {
		c[2] = 2;
	} else {
		c[1] = c[2] = 3;
		s -= 3;
		for (int i = 3; i <= n; i += 2) {
			if (p[i] && p[s - i]) {
				c[i] = 2;
				break;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		printf("%d%c", c[i], i == n ? '\n' : ' ');
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//413362 	Apr 28, 2011 2:03:27 AM 	watashi 	45G - Prime Problem 	GNU C++ 	Accepted 	670 ms 	19000 KB 
