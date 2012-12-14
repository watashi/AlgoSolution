#include <set>
#include <cctype>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<long long, long long> PII;
const int MAXN = 1024;
const long long MOD1 = 1000000007LL;
const long long MOD2 = 1000000009LL;

int c2i(char ch) {
	if (isupper(ch)) {
		return ch - 'A';
	} else if (islower(ch)) {
		return ch - 'a' + 26;
	} else if (isdigit(ch)) {
		return ch - '0' + 52;
	} else if (ch == '+') {
		return 62;
	} else if (ch == '/') {
		return 63;
	} else {
		return -1;
	}
}

bool test(int i, int j) {
	return ((i >> j) & 1) != 0;
}

void read(int r, int c, bool a[MAXN][MAXN]) {
	static char buf[MAXN];
	for (int i = 0; i < r; ++i) {
		scanf("%s", buf);
		for (int j = 0; j < c; ++j) {
			a[i][j] = test(c2i(buf[j / 6]), 5 - j % 6);
		}
	}
}

void revx(int n, bool b[MAXN][MAXN]) {
	for (int i = 0; i + i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			swap(b[i][j], b[n - 1 - i][j]);
		}
	}
}

void revy(int n, bool b[MAXN][MAXN]) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j + j < n; ++j) {
			swap(b[i][j], b[i][n - 1 - j]);
		}
	}
}

void revz(int n, bool b[MAXN][MAXN]) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			swap(b[i][j], b[j][i]);
		}
	}
}

void next(PII& p, bool b) {
	p.first <<= 1;
	p.second <<= 1;
	if (b) {
		p.first ^= 1;
		p.second ^= 1;
	}
	p.first %= MOD1;
	p.second %= MOD2;
}

long long bin1[MAXN * MAXN], bin2[MAXN * MAXN];
bool a[MAXN][MAXN], b[MAXN][MAXN];
PII h[MAXN][MAXN];

int main() {
	int r, c, n, m;
	PII code;
	set<PII> st;

	bin1[0] = bin2[0] = 1LL;
	for (int i = 1; i < MAXN * MAXN; ++i) {
		bin1[i] = bin1[i - 1] * 2 % MOD1;
		bin2[i] = bin2[i - 1] * 2 % MOD2;
	}
	while (scanf("%d%d%d", &c, &r, &n) != EOF && n > 0) {
		read(r, c, a);
		read(n, n, b);
		st.clear();
		for (int x = 0; x < 2; ++x) {
			for (int y = 0; y < 2; ++y) {
				for (int z = 0; z < 2; ++z) {
					code = make_pair(0LL, 0LL);
					for (int i = 0; i < n; ++i) {
						for (int j = 0; j < n; ++j) {
							next(code, b[i][j]);
						}
					}
					st.insert(code);
					revz(n, b);
				}
				revy(n, b);
			}
			revx(n, b);
		}

		for (int i = 0; i < r; ++i) {
			code = make_pair(0LL, 0LL);
			for (int j = 0; j < c; ++j) {
				next(code, a[i][j]);
				if (j >= n && a[i][j - n]) {
					code.first = (code.first - bin1[n] + MOD1) % MOD1;
					code.second = (code.second - bin2[n] + MOD2) % MOD2;
				}
				h[i][j] = code;
			}
		}
		m = 0;
		for (int j = n - 1; j < c; ++j) {
			code = make_pair(0LL, 0LL);
			for (int i = 0; i < r; ++i) {
				code.first = code.first * bin1[n] + h[i][j].first;
				code.second = code.second * bin2[n] + h[i][j].second;
				if (i >= n) {
					code.first -= h[i - n][j].first * bin1[n * n];
					code.second -= h[i - n][j].second * bin2[n * n];
				}
				code.first = (code.first % MOD1 + MOD1) % MOD1;
				code.second = (code.second % MOD2 + MOD2) % MOD2;
				if (i >= n - 1 && st.count(code) > 0) {
					++m;
				}
			}
		}
		printf("%d\n", m);
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//885842 	5074 	Where's Wally 	Accepted 	C++ 	1.304 	2011-09-20 11:56:50
/*
id => 1174077
pid => 5074
pname => Where's Wally
status => Accepted
lang => C++
time => 1.982
date => 2012-12-14 17:18:58
*/
