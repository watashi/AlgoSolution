#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 256;
const long long MOD = 1000000007LL;
const char* mat[7] = {
	".........",
	"....O....",
	"O.......O",
	"O...O...O",
	"O.O...O.O",
	"O.O.O.O.O",
	"OOO...OOO"};
int h[7], v[7];
char buf[4 * MAXN][4 * MAXN];
int dir[MAXN][MAXN];

void init() {
	for (int k = 0; k < 7; ++k) {
		h[k] = v[k] = 0;
		for (int j = 0; j < 9; ++j) {
			if (mat[k][j] == 'O') {
				h[k] |= 1 << j;
			}
		}
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (mat[k][3 * i + j] == 'O') {
					v[k] |= 1 << ((2 - j) * 3 + i);
				}
			}
		}
	}
/*
	for (int k = 0; k < 7; ++k) {
		for (int i = 0; i < 9; ++i) {
			putchar((h[k] & (1 << i)) ? 'X' : '.');
			if (i % 3 == 2) {
				puts("");
			}
		}
		puts("");
	}
	puts("===========");
	for (int k = 0; k < 7; ++k) {
		for (int i = 0; i < 9; ++i) {
			putchar((v[k] & (1 << i)) ? 'X' : '.');
			if (i % 3 == 2) {
				puts("");
			}
		}
		puts("");
	}
*/
}

int mask(int x, int y) {
	int z = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (buf[x + i][y + j] == 'O') {
				z |= 1 << (i * 3 + j);
			}
		}
	}
	return z;
}

long long tot[MAXN];
long long dp[MAXN];

int main() {
	int n, m;

	init();
	scanf("%d%d", &n, &m);
	for (int i = 0; i < 4 * n + 1; ++i) {
		scanf("%s", buf[i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int k = mask(i * 4 + 1, j * 4 + 1);
			dir[j][i] = 0;
			if (find(h, h + 7, k) != h + 7) {
				dir[j][i] |= 1;	// h
			}
			if (find(v, v + 7, k) != v + 7) {
				dir[j][i] |= 2;	// v
			}
	//		printf("[%d][%d] = %d\n", j, i, dir[j][i]);
		}
	}
/*
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			putchar(dir[i][j][" -|+"]);
		}
		puts("");
	}
*/
	fill(tot, tot + m + 1, 0);
	tot[0] = 1LL;
	for (int i = 0; i < m; ++i) {
		bool allv = n % 2 == 0;// true; WA⑨!!! 
		for (int j = 0; j < n && allv; ++j) {
			allv &= (dir[i][j] & 2) != 0;
		}
		if (allv) {
	//		printf("add %d\n", i);
			tot[i + 1] += tot[i];
		}
		
		if (i == 0) {
			continue;
		}

		fill(dp, dp + n + 1, 0);
		dp[0] = 1LL;
		for (int j = 0; j < n; ++j) {
			if ((dir[i][j] & 1) != 0 && (dir[i - 1][j] & 1) != 0) {
				dp[j + 1] += dp[j];
			}
			if (j > 0
					&& (dir[i][j] & 2) != 0
					&& (dir[i][j - 1] & 2) != 0
					&& (dir[i - 1][j] & 2) != 0
					&& (dir[i - 1][j - 1] & 2) != 0) {
				dp[j + 1] += dp[j - 1];
			}
			if (dp[j + 1] >= MOD) {
				dp[j + 1] -= MOD;
			}
		}
		
		allv = n % 2 == 0;// true; WA⑨!!! 
		for (int j = 0; j < n && allv; ++j) {
			allv &= (dir[i][j] & 2) != 0 && (dir[i - 1][j] & 2) != 0;
		}
		if (allv) {
			dp[n] = (dp[n] + MOD - 1) % MOD;
		}

	//	printf("mul %d %lld\n", i, dp[n]);
		tot[i + 1] = (tot[i + 1] + tot[i - 1] * dp[n]) % MOD;
	}
	printf("%d\n", (int)tot[m]);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//401868 	Apr 19, 2011 10:31:18 PM 	watashi 	D - Domino Carpet 	GNU C++ 	Accepted 	50 ms 	2600 KB 

