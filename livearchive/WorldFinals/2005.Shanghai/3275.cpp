#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const char * const dz = "NESW";

int abs_(int x) {
	return x > 0 ? x : -x;
}

PII go(const vector<PII>& e, int d) {
	int x = 0, y = 0;
	for (vector<PII>::const_iterator it = e.begin(); d > 0 && it != e.end(); ++it) {
		int t = min(d, it->second);
		x += t * dx[it->first];
		y += t * dy[it->first];
		d -= t;
	}
	return make_pair(x, y);
}

inline int signum(int x) {
	if (x > 0) {
		return 1;
	} else if (x < 0) {
		return -1;
	} else {
		return 0;
	}
}

inline void next(int n, int& x) {
	++x;
	if (x == n) {
		x = 0;
	}
}

inline void prev(int n, int& x) {
	--x;
	if (x < 0) {
		x += n;
	}
}

inline PII operator-(const PII& lhs, const PII& rhs) {
	return PII(lhs.first - rhs.first, lhs.second - rhs.second);
}

bool gao(int n, const vector<pair<int, PII> >& v, int s, int t, int d) {
	PII p1 = v[s].second, p2 = v[t].second;
	while (d > 0) {
		while (p1 == v[s].second) {
			next(n, s);
		}
		while (p2 == v[t].second) {
			prev(n, t);
		}
		PII d1 = v[s].second - p1, d2 = v[t].second - p2;
		if (signum(d1.first) != signum(d2.first) || signum(d1.second) != signum(d2.second)) {
			return false;
		}
		int t = min(abs_(d1.first) + abs_(d1.second), abs_(d2.first) + abs_(d2.second));
		p1.first += t * signum(d1.first);
		p1.second += t * signum(d1.second);
		p2.first += t * signum(d2.first);
		p2.second += t * signum(d2.second);
		d -= t;
	}
	return true;
}

const int MAXN = 256;
const int INF = 1024;
int w[MAXN][MAXN];

int main() {
	char ch;
	bool flag;
	int ri = 0, n;
	int m;
	vector<PII> e;
	vector<pair<int, PII> > v;

	while (scanf("%d", &n) != EOF && n > 0) {
		m = 0;
		e.resize(n);
		v.resize(n + n);
		for (int i = 0; i < n; ++i) {
			scanf(" %c%d", &ch, &e[i].second);
			e[i].first = find(dz, dz + 4, ch) - dz;
			v[i].first = m;
			m += e[i].second;
		}
		for (int i = 0; i < n; ++i) {
			v[n + i].first = (v[i].first + m / 2) % m;
		}
		for (int i = 0; i < n + n; ++i) {
			v[i].second = go(e, v[i].first);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		
		n = v.size();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				w[i][j] = INF;
			}
			w[i][i] = 0;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (v[j].first - v[i].first < m / 2 && gao(n, v, i, (j + n / 2) % n, v[j].first - v[i].first)) {
					w[i][j] = 1;
				}
			}
		}

		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
				}
			}
		}
		flag = false;
		for (int i = 0; i < n / 2; ++i) {
			if (w[i][i + n / 2] <= 3) {
				flag = true;
				break;
			}
		}
		printf("Polygon %d: %s\n", ++ri, flag ? "Possible" : "Impossible");
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//725278  	2011-01-24 17:06:30 	Accepted	0.002	Minimum	26909	C++	3275 - Tiling the Plane

/*
id => 1174320
pid => 3275
pname => Tiling the Plane
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:53:48
*/
