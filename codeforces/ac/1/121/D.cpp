#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct BigInteger {
	static const int LEN = 4;
	static const long long MOD;
	long long a[LEN];

	explicit BigInteger(long long x) {
		fill(a + 1, a + LEN, 0LL);
		a[0] = x;
		for (int i = 0; a[i] >= MOD; ++i) {
			a[i + 1] += a[i] / MOD;
			a[i] %= MOD;
		}
	}

	BigInteger(const BigInteger& o) {
		copy(o.a, o.a + LEN, a);
	}

	void operator+=(const BigInteger& o) {
		for (int i = 0; i < LEN; ++i) {
			a[i] += o.a[i];
			while (a[i] >= MOD) {
				++a[i + 1];
				a[i] -= MOD;
			}
		}
	}

	void operator-=(const BigInteger& o) {
		for (int i = 0; i < LEN; ++i) {
			a[i] -= o.a[i];
			while (a[i] < 0) {
				--a[i + 1];
				a[i] += MOD;
			}
		}
	}

	bool operator<=(const BigInteger& o) {
		for (int i = LEN - 1; i >= 0; --i) {
			if (a[i] != o.a[i]) {
				return a[i] < o.a[i];
			}
		}
		return true;
	}

	void dump() const {
		for (int i = LEN - 1; i >= 0; --i) {
			printf("%08lld,", a[i]);
		}
		puts("");
	}
};

BigInteger operator*(const BigInteger& a, const BigInteger& b) {
	BigInteger c(0);
	for (int i = 0; i < BigInteger::LEN; ++i) {
		for (int j = 0; j <= i; ++j) {
			c.a[i] += a.a[j] * b.a[i - j];
		}
		if (c.a[i] >= BigInteger::MOD) {
			c.a[i + 1] += c.a[i] / BigInteger::MOD;
			c.a[i] %= BigInteger::MOD;
		}
	}
	return c;
}

const long long BigInteger::MOD = 100000000LL;
const long long INF = 4444444444444444444LL;
vector<long long> lucky;

void gen(int n, long long m) {
	lucky.push_back(m);
	if (n > 0) {
		gen(n - 1, m * 10 + 4);
		gen(n - 1, m * 10 + 7);
	}
}

void init() {
	lucky.clear();
	gen(18, 0);
	lucky.push_back(INF);
	sort(lucky.begin(), lucky.end());
	//printf("%d %lld\n", (int)lucky.size(), lucky.back());
}

const int MAXN = 100100;

int main() {
//	(BigInteger(INF)).dump();
//	(BigInteger(222222222222LL) * BigInteger(222222222222LL)).dump();
//	(BigInteger(1000000000000000LL)).dump();
//	(BigInteger(1000000000000000LL) * BigInteger(20LL)).dump();

	int n, ans;
	long long m, l, r, d, cl, cr;
	multiset<long long> w;
	vector<pair<long long, long long> > v;

	init();
	cin >> n >> m;

	BigInteger bm(m);
	BigInteger bs(0);

	d = lucky.back();
	for (int i = 0; i < n; ++i) {
		cin >> l >> r;
		bs += BigInteger(l);
		d = min(d, r - l);
		v.push_back({l, r});
	}
	sort(v.rbegin(), v.rend());
	//for (int i = 0; i < BigInteger::LEN; ++i) {
	//			printf(">%08lld\n", bs.a[i]);
	//		}
	//		puts("");

	ans = 0;
	l = r = 1;
	cl = n;
	cr = 0;
	while (l < (int)lucky.size() && r < (int)lucky.size()) {
		while (!v.empty() && v.back().first <= lucky[l]) {
			bs -= BigInteger(v.back().first - lucky[l - 1]);
			w.insert(v.back().second);
			v.pop_back();
			--cl;
		}
		bs -= BigInteger(cl) * BigInteger(lucky[l] - lucky[l - 1]);
	//	if (lucky[l] == 4444444444LL || lucky[l] == 44444444LL) {
	//		for (int i = 0; i < BigInteger::LEN; ++i) {
	//			printf(">%08lld\n", bs.a[i]);
	//		}
	//		puts("");
	//	}
		while (r < (int)lucky.size() && lucky[r] - lucky[l] <= d && bs <= bm) {
			bs += BigInteger(cr) * BigInteger(lucky[r] - lucky[r - 1]);
			while (!w.empty() && *w.begin() < lucky[r]) {
				bs += BigInteger(lucky[r] - *w.begin());
				w.erase(w.begin());
				++cr;
			}
			if (bs <= bm) {
				++r;
				ans = max(ans, (int)(r - l));
			}
		}
		++l;
	}
	printf("%d\n", ans);

	return 0;
}


