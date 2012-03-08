#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 20;

inline int L(int p) { return p << 1; }
inline int R(int p) { return L(p) ^ 1; }

struct SegTree {
	int m;
	long long s[MAXN + MAXN];
	
	void init(int n) {
		m = 1;
		while (m < n) {
			m <<= 1;
		}
		fill(s, s + m + m, 0LL);
	}

	void add(int i, long long v) {
		i += m;
		while (i > 0) {
			s[i] += v;
			i >>= 1;
		}
	}

	long long sum(int p, int pl, int pr, int l, int r) {
		if (pl == l && pr == r) {
			return s[p];
		} else {
			int pm = (pl + pr) / 2;
			if (r <= pm) {
				return sum(L(p), pl, pm, l, r);
			} else if (pm <= l) {
				return sum(R(p), pm, pr, l, r);
			} else {
				return sum(L(p), pl, pm, l, pm) + sum(R(p), pm, pr, pm, r);
			}
		}
	}
} s1, s2;

map<int, int> mp;
int a[MAXN];

int main() {
	int n, m;
	long long ans;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		mp[a[i]];
	}
	
	m = 1;
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
		it->second = m++;
	}
	s1.init(m);
	s2.init(m);

	ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		a[i] = mp[a[i]];
		ans += s2.sum(1, 0, s2.m, 0, a[i]);
		s2.add(a[i], s1.sum(1, 0, s1.m, 0, a[i]));
		s1.add(a[i], 1);
	}
//	printf("%lld\n", ans);
	printf("%I64d\n", ans);

	return 0;
}

