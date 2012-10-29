#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int SIGMA = 26;
const int MAXN = 100100;
const int INF = 1000000000;

int main() {
	int n, s, z, t, w[SIGMA][SIGMA];
	char a[MAXN], b[MAXN], c[MAXN], x, y;

	for (int i = 0; i < SIGMA; ++i) {
		for (int j = 0; j < SIGMA; ++j) {
			w[i][j] = INF;
		}
		w[i][i] = 0;
	}
	scanf("%s%s%d", a, b, &n);
	for (int i = 0; i < n; ++i) {
		scanf(" %c %c%d", &x, &y, &z);
		x -= 'a';
		y -= 'a';
		w[x][y] = min(w[x][y], z);
	}
	for (int k = 0; k < SIGMA; ++k) {
		for (int i = 0; i < SIGMA; ++i) {
			for (int j = 0; j < SIGMA; ++j) {
				w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
			}
		}
	}

	n = strlen(a);
	s = strlen(b) == n ? 0 : INF;
	for (int i = 0; i < n && s < INF; ++i) {
		z = INF;
		for (int j = 0; j < SIGMA; ++j) {
			t = w[a[i] - 'a'][j] + w[b[i] - 'a'][j];
			if (t < z) {
				z = t;
				c[i] = 'a' + j;
			}
		}
		s += z;
	}
	
	if (s < INF) {
		c[n] = '\0';
		printf("%d\n%s\n", s, c);
	} else {
		puts("-1");
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//242453 	Jan 8, 2011 10:25:23 PM 	watashi 	B - String Problem 	GNU C++ 	Accepted 	30 ms 	1588 KB 
