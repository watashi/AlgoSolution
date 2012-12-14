#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 42;
const int MAXM = 16 * 1025;

char dp[MAXN][MAXN][MAXM];

inline void upd(char& lhs, char rhs) {
	lhs = min<char>(2, lhs + rhs);
}

int main() {
	int ri = 0, m, m1, m0, n;
	char str[80];

	while (scanf("%d%d%s", &m, &m1, str) == 3 && m > 0) {
		printf("Case #%d: ", ++ri);
		m0 = m - m1;
		n = (int)strlen(str);
		if (m0 < 0 || m0 > count(str, str + n, '0')) {
			puts("NO");
			continue;
		}
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;
		for (int i = 0; i < n; ++i) {
			if (str[i] == '0') {	// 0
				for (int j = 1; j <= m0; ++j) {
					for (int k = 1; k <= m; ++k) {
						upd(dp[i + 1][j][k], dp[i][j - 1][k - 1]);
					}
				}
			}
			if (str[i] == '1') {
				if (str[i + 1] == '\0') {	// 1$
					for (int j = 0; j <= m0; ++j) {
						for (int k = 1; k <= m; ++k) {
							upd(dp[i + 1][j][k], dp[i][j][k - 1]);
						}
					}
				} else if (str[i + 1] == '0') {	// 10
					for (int j = 1; j <= m0; ++j) {
						for (int k = 2; k <= m; ++k) {
							upd(dp[i + 2][j][k], dp[i][j - 1][k - 2]);
						}
					}
				} else if (str[i + 1] == '1') {
					if (str[i + 2] == '\0') {	// 11$
						for (int j = 0; j <= m0; ++j) {
							for (int k = 2; k <= m; ++k) {
								upd(dp[i + 2][j][k], dp[i][j][k - 2]);
							}
						}
					} else if (str[i + 2] == '0') {	// 110
						for (int j = 1; j <= m0; ++j) {
							for (int k = 3; k <= m; ++k) {
								upd(dp[i + 3][j][k], dp[i][j - 1][k - 3]);
							}
						}
					}
				}
				int c = 1;
				int ii = i + 1;
				while (c <= m1 && ii <= n) {
					if (c >= 3) {
						if (str[ii] == '\0') {	// 1{3,}$
							for (int j = 0; j <= m0; ++j) {
								for (int k = c; k <= m; ++k) {
									upd(dp[ii][j][k], dp[i][j][k - c]);
								}
							}
						} else if (str[ii] == '0') {	// 1{3,}0
							for (int j = 1; j <= m0; ++j) {
								for (int k = c + 1; k <= m; ++k) {
									upd(dp[ii + 1][j][k], dp[i][j - 1][k - c - 1]);
								}
							}
						}
					}
					c *= 2;
					if (str[ii++] == '1') {
						c += 1;
					}
				}
			}
		}
		switch (dp[n][m0][m]) {
		case 0: puts("NO"); break;
		case 1: puts("YES"); break;
		case 2: puts("NOT UNIQUE"); break;
		}
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//726002  	2011-01-25 18:41:52 	Accepted	2.479	28640	26909	C++	3565 - Bit Compressor
/*
id => 1174028
pid => 3565
pname => Bit Compressor
status => Accepted
lang => C++
time => 0.889
date => 2012-12-14 17:12:32
*/
