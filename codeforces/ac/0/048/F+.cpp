#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 500500;

struct Company {
	int w, c, a;
} com[MAXN];

inline bool operator<(const Company& lhs, const Company& rhs) {
	return (long long)lhs.c * rhs.w < (long long)rhs.c * lhs.w;
}

struct Real {
	long long i;	// [0, inf)
	double f;	// [0, 1)

	void _adjust() {
		static double _i;
		f = modf(f, &_i);
		i += llrint(_i);
	}
	
	explicit Real(long long a = 0, long long b = 1) : i(a / b), f(a % b / (double)b) {
	}
	
	Real operator+=(const Real& o) {
		i += o.i;
		f += o.f;
		_adjust();
		return *this;
	}
	
	void show() {
		_adjust();
//		printf("%lld%.20lf\n", i / 10, i % 10 + f);
		printf("%I64d%.20lf\n", i / 10, i % 10 + f);
	}
};

Real gao(int n, long long w, Company a[]) {
	if (w == 0) {
		return Real();
	} else if (n == 1) {
		return Real(w * a->c, a->w);
	} else {
		int i = 0;
		int j = n - 1;
		long long sw = 0;
		long long sc = 0;
		Company b = a[rand() % n];

		while (i <= j) {
			while (a[i] < b) {
				sw += a[i].w;
				sc += a[i].c;
				++i;
			}
			while (b < a[j]) {
				--j;
			}
			if (i <= j) {
				sw += a[j].w;
				sc += a[j].c;
				swap(a[i++], a[j--]);
			}
		}

		if (sw <= w) {
			Real ret(sc);
			ret += gao(n - i, w - sw, a + i);
			return ret;
		} else {
			return gao(i, w, a);
		}
	}
}

int main() {
	int n, m, w;
	Real ans;

	scanf("%d%d%d", &n, &m, &w);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &com[i].w);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &com[i].c);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &com[i].a);
	}
	for (int i = 0; i < n; ++i) {
		ans += gao(m, w, com);
		for (int j = 0; j < m; ++j) {
			com[j].c -= com[j].a;
		}
	}
	ans.show();

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//218850 	Dec 13, 2010 5:21:11 PM 	watashi 	F - Snow sellers 	GNU C++ 	Accepted 	4910 ms 	7176 KB
