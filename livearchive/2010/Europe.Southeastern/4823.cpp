#include <cstdio>

using namespace std;

const int MAXN = 1024;

bool a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];

int main() {
	int n, t;

	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				scanf("%d", &t);
				a[i][j] = b[i][j] = (t % 2 != 0);
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 2; j <= n; ++j) {
				a[i][j] ^= a[i][j - 1];
			}
		}
		for (int j = 1; j <= n; ++j) {
			for (int i = 2; i <= n; ++i) {
				b[i][j] ^= b[i - 1][j];
			}
		}
		for (int i = 0; i <= n; ++i) {
			c[i][0] = c[0][i] = false;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (!a[i][j] && !c[i - 1][j]) {
					c[i][j] = true;
				} else if (!b[i][j] && !c[i][j - 1]) {
					c[i][j] = true;
				} else {
					c[i][j] = false;
				}
			//	printf("%d[%d%d] ", c[i][j], a[i][j], b[i][j]);
			}
			// puts("");
		}
		puts(c[n][n] ? "W" : "L");
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714954  	2011-01-04 03:32:23 	Accepted	0.340	3460	26909	C++	4823 - Game
/*
id => 1174242
pid => 4823
pname => Game
status => Accepted
lang => C++
time => 0.159
date => 2012-12-14 17:43:43
*/
