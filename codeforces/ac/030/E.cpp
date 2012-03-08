#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 17;

int fail[MAXN], pos[MAXN], pal[MAXN], rmq[17][MAXN];

inline int bits(int x) {
	return 8 * sizeof(x) - __builtin_clz(x);
}

void gao(int n, char s[]) {
	reverse(s, s + n);
	fail[0] = 0;
	for (int i = 1; i < n; ++i) {
		fail[i] = fail[i - 1];
		while (fail[i] > 0 && s[i] != s[fail[i]]) {
			fail[i] = fail[fail[i] - 1];
		}
		if (s[i] == s[fail[i]]) {
			++fail[i];
		}
	}
	reverse(s, s + n);

	for (int i = 0; i < n; ++i) {
		pos[i] = n;
	}
	pos[0] = 0;
	for (int i = 0, j = 0; i < n; ) {
		if (s[i] == s[n - 1 - j]) {
			++i;
			++j;
			pos[j] = min(pos[j], i);
		} else if (j > 0) {
			j = fail[j - 1];
		} else {
			++i;
		}
	}

	for (int i = 0, j = 0, k = 0; i < n; ++i) {
		int l = i < k ? min(pal[j + j - i], k - i) : 1;
		while (0 <= i - l && i + l < n && s[i - l] == s[i + l]) {
			++l;
		}
		pal[i] = l;
		if (i + l > k) {
			j = i;
			k = i + l;
		}
	}

	for (int j = 0; j < n; ++j) {
		rmq[0][j] = j;
	}
	for (int i = 1; i < 17; ++i) {
		for (int j = 0; j + (1 << i) <= n; ++j) {
			rmq[i][j] = pal[rmq[i - 1][j]] >= pal[rmq[i - 1][j + (1 << (i - 1))]] ? rmq[i - 1][j] : rmq[i - 1][j + (1 << (i - 1))];
		}
	}
}

int query(int l, int r) {
	int i = bits(r - l) - 1;
	return pal[rmq[i][l]] >= pal[rmq[i][r - (1 << i)]] ? rmq[i][l] : rmq[i][r - (1 << i)];
}

char s[MAXN];

int main() {
	int n;
	pair<int, pair<int, int> > ans;

	scanf("%s", s);
	n = strlen(s);
	gao(n, s);
	ans = make_pair(-1, make_pair(-1, -1));
	for (int i = 0; i < n && pos[i] < n - i; ++i) {
//		printf("%d %d\n", pos[i], n - i);
		int s = pos[i], t = n - i, l = 1, r = (t - s + 1) / 2 + 1;
		while (l < r) {
			int m = (l + r) / 2;
			if (s + (m - 1) < t - (m - 1) && pal[query(s + (m - 1), t - (m - 1))] >= m) {
				l = m + 1;
			} else {
				r = m;
			}
		}
		--r;
		l = query(s + (r - 1), t - (r - 1));
//		printf("%d %d %d %d\n", s, t, l, r);
		ans = max(ans, make_pair(r * 2 - 1 + i * 2, make_pair(i, l - (r - 1))));
	}

//	printf("%d %d %d\n", ans.first, ans.second.first, ans.second.second);
	if (ans.second.first == 0) {
		puts("1");
		printf("%d %d\n", 1 + ans.second.second, ans.first - 2 * ans.second.first);
	} else {
		puts("3");
		printf("%d %d\n", 1 + pos[ans.second.first] - ans.second.first, ans.second.first);
		printf("%d %d\n", 1 + ans.second.second, ans.first - 2 * ans.second.first);
		printf("%d %d\n", 1 + n - ans.second.first, ans.second.first);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//421262 	May 1, 2011 5:44:41 PM 	watashi 	30E - Tricky and Clever Password 	GNU C++ 	Accepted 	50 ms 	11700 KB 
