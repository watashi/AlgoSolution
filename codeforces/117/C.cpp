#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 5050;

int v[MAXN];
bool e[MAXN][MAXN];

void gao(int n, int i) {
	v[i] = 1;
	for (int j = 0; j < n; ++j) {
		if (e[i][j]) {
			if (v[j] == 0) {
				gao(n, j);
			} else if (v[j] == 1) {
				throw j;
			}
		}
	}
	v[i] = 2;
}

int main() {
	int n;
	char buf[MAXN];

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", buf);
		v[i] = 0;
		for (int j = 0; j < n; ++j) {
			e[i][j] = buf[j] == '1';
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!v[i]) {
			try {
				gao(n, i);
			} catch (int c) {
				for (int a = 0; a < n; ++a) {
					for (int b = 0; b < n; ++b) {
						if (e[a][b] && e[b][c] && e[c][a]) {
							printf("%d %d %d\n", a + 1, b + 1, c + 1);
							return 0;
						}
					}
				}
			}
		}
	}
	puts("-1");
	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//735800 	Oct 3, 2011 4:16:46 PM 	watashi 	117C - Cycle 	GNU C++0x 	Accepted 	500 ms 	26600 KB 
