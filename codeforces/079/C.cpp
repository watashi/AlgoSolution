#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

void initFail(int len, const char pat[], int fail[]) {
	fail[0] = -1;
	for (int i = 1; i < len; ++i) {
		int k = fail[i - 1];
		while (k >= 0 && pat[k + 1] != pat[i]) {
			k = fail[k];
		}
		fail[i] = (pat[k + 1] == pat[i]) ? k + 1 : -1;
	}
}

void kmpFind(int len, const char pat[], const int fail[], const char str[], int r[]) {
	const char *p = str;
	int k = 0;
	while (*p != '\0') {
		if (*p == pat[k]) {
			++p;
			++k;
			if (k == len) {
	//			printf("[%d] = %d\n", p - str - len, len);
				r[p - str - len] = min(r[p - str - len], len);
				k = fail[k - 1] + 1;
			}
		} else if (k > 0) {
			k = fail[k - 1] + 1;
		} else {
			++p;
		}
	}
}

int main() {
	int l, m, n;
	pair<int, int> ans;
	static int f[MAXN], r[MAXN];
	static char s[MAXN], t[MAXN];

	scanf("%s", s);
	m = strlen(s);
	for (int i = 0; i <= m; ++i) {
		r[i] = m - i + 1;
	}

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", t);
		l = strlen(t);
		initFail(l, t, f);
		kmpFind(l, t, f, s, r);
	}

	ans = make_pair(-1, -1);
	for (int i = m - 1; i >= 0; --i) {
		r[i] = min(r[i], r[i + 1] + 1);
	//	printf("r[%d] = %d\n", i, r[i]);
		ans = max(ans, make_pair(r[i] - 1, i));
	}
	printf("%d %d\n", ans.first, ans.second);

	return 0;
}
