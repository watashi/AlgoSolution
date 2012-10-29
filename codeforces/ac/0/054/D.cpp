#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXL = 128;
const int SIGMA = 26;

int fail[MAXL];
int dfa[MAXL][SIGMA];
pair<int, int> pre[MAXL][MAXL];

void dump(int i, int j) {
	if (i > 0) {
		dump(i - 1, pre[i][j].first);
		putchar('a' + pre[i][j].second);
	}
}

int main() {
	int n, m, s;
	char c[MAXL];

	scanf("%d%d%s", &n, &s, c + 1);
	m = (int)strlen(c + 1);
	for (int i = 0; i <= m; ++i) {
		fail[i] = i < 2 ? 0 : dfa[fail[i - 1]][c[i] - 'a'];
		for (int j = 0; j < s; ++j) {
			if (c[i + 1] - 'a' == j) {
				dfa[i][j] = i + 1;
			} else {
				dfa[i][j] = dfa[fail[i]][j];
			}
		}
	}

	memset(c, '0', sizeof(c));
	scanf("%s", c + m);
	memset(pre, 0xff, sizeof(pre));
	pre[0][0].first = -2;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (pre[i][j].first == -1 || (c[i] == '1') ^ (j == m)) {
				pre[i][j].first = -1;
				continue;
			}
			for (int k = 0; k < s; ++k) {
				if (pre[i + 1][dfa[j][k]].first == -1) {
					pre[i + 1][dfa[j][k]] = make_pair(j, k);
				}
			}
		}
	}

	s = -1;
	for (int j = 0; j <= m; ++j) {
		if (pre[n][j].first != -1 && (c[n] == '0') ^ (j == m)) {
			s = j;
			break;
		}
	}
	if (s == -1) {
		puts("No solution");
	} else {
		dump(n, s);
	}

	return 0;
}

/*
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
248525 	Jan 13, 2011 7:20:11 PM 	watashi 	54D - Writing a Song 	GNU C++ 	Accepted 	30 ms 	1400 KB
*/
