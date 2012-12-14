#include <cstdio>
#include <algorithm>

using namespace std;
	
char buf[1 << 20];
int cnt[1 << 20], idx[1 << 20];

int main() {
	int re, n, m, l, p, q;
	long long ans;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d%d%s", &n, &m, &l, buf);
		if (l == n) {
			ans = 0;
		} else if (m == n) {
			ans = -1;
		} else {
			cnt[0] = 0;
			for (int i = 1; i <= l; ++i) {
				if (buf[i - 1] == '1') {
					cnt[i] = cnt[i - 1] + 1;
					idx[cnt[i] - 1] = i - 1;
				} else {
					cnt[i] = cnt[i - 1];
				}
			}
			p = 0;
			ans = l - m;
			while (p < l - n) {
				q = idx[cnt[min(l, p + m)] - n];
				if (p < q) {
					p = q;
					ans += n;
				} else {
					ans = -1;
					break;
				}
			}
		}
		if (ans == -1) {
			puts("IMPOSSIBLE");
		} else {
			printf("%lld\n", ans);
		}
	}

	return 0;
}

/*
id => 1174283
pid => 4953
pname => Wormly
status => Accepted
lang => C++
time => 0.222
date => 2012-12-14 17:49:00
*/
