#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
const int INF = 1000000007;

struct Ans {
	int m, s, n, t;
	int toInt() const {
		if (m + n > 9) {
			return INF;
		} else {
			int ret = 0;
			for (int i = 0; i < m; ++i) {
				ret *= 10;
				ret += s;
			}
			for (int i = 0; i < n; ++i) {
				ret *= 10;
				ret += t;
			}
			return ret;
		}
	}
};

const Ans inf = {INF, 9, INF, 9};

bool operator<(const Ans& lhs, const Ans& rhs) {
	if (lhs.m + lhs.n != rhs.m + rhs.n) {
		return lhs.m + lhs.n < rhs.m + rhs.n;
	} else if (lhs.s != rhs.s) {
		return lhs.s < rhs.s;
	} else if (lhs.m > rhs.m) {
		return lhs.s < rhs.t;
	} else if (lhs.m < rhs.m) {
		return lhs.t < rhs.s;
	} else {
		return lhs.t < rhs.t;
	}
}

void init(int m, int d, int x[], int& begin, int& end) {
	int t;

	fill(x, x + m, -1);
	t = d % m;
	end = 1;
	while (x[t] == -1) {
		x[t] = end++;
		t = (t * 10 + d) % m;
	}
	begin = x[t];
}

// find first x > y
inline int next(int x, int y, int begin, int end) {
	if (x > y) {
		return x;
	} else if (x < begin) {
		return -1;
	} else {
		return x + ((y - x) / (end - begin) + 1) * (end - begin);
	}
}

int begin[10], end[10], x[10][MAXN];

Ans gao(int n, int s, int t) {
	int d = s < t ? t - s : s - t;
	Ans ret = inf, tmp;

	tmp.s = s;
	tmp.t = t;
	for (int i = 0; i < n; ++i) {
		tmp.n = 0;
		for (int j = 0; j < 2; ++j) {
			tmp.n = next(x[d][i], tmp.n, begin[d], end[d]);
			tmp.m = next(x[s][s > t ? i : (n - i) % n], tmp.n, begin[s], end[s]);
			if (tmp.m == -1 || tmp.n == -1) {
				break;
			}
			tmp.m -= tmp.n;
			if (tmp.toInt() != n) {
				ret = min(ret, tmp);
				break;
			}
		}
	}

	return ret;
}

int main() {
	int n;
	Ans ans;

	while (scanf("%d", &n) != EOF && n > 0) {
		for (int i = 1; i <= 9; ++i) {
			init(n, i, x[i], begin[i], end[i]);
		}
		ans = inf;
		for (int i = 1; i <= 9; ++i) {
			for (int j = 0; j <= 9; ++j) {
				if (i != j) {
					ans = min(ans, gao(n, i, j));
				}
			}
		}
		printf("%d: %d %d %d %d\n", n, ans.m, ans.s, ans.n, ans.t);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//726001  	2011-01-25 18:40:39 	Accepted	2.842	4312	26909	C++	3564 - Bipartite Numbers
/*
id => 1174029
pid => 3564
pname => Bipartite Numbers
status => Accepted
lang => C++
time => 0.725
date => 2012-12-14 17:12:40
*/
