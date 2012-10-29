#include <cstdio>
#include <vector>
#include <cstdlib>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 128;

vector<int> v, w;
vector<pair<int, PII> > e[MAXN];

void no() {
	puts("NO");
	exit(0);
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

bool gao(int i) {
	for (int j = 0; j < (int)e[i].size(); ++j) {
		int b = e[i][j].first;
		int c = e[i][j].second.first;
		int d = e[i][j].second.second;
		int e;
		if (v[i] % c != 0) {
			return false;
		}
		e = v[i] / c;
		if (d % e != 0) {
			return false;
		}
		e = d / e * c;
		if (v[b] == 0) {
			v[b] = e;
			if (gcd(v[i], v[b]) != c || !gao(b)) {
				return false;
			}
		} else if (v[b] != e) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, m, a, b, c, d;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		--a;
		--b;
		if (d % c != 0) {
			no();
		} else {
			d /= c;
		}
		e[a].push_back(make_pair(b, make_pair(c, d)));
		e[b].push_back(make_pair(a, make_pair(c, d)));
	}
	v = vector<int>(n, 0);

	for (int i = 0; i < n; ++i) {
		if (v[i] != 0) {
			continue;
		} else if (e[i].empty()) {
			v[i] = 1;
		} else {
			b = e[i][0].first;
			c = e[i][0].second.first;
			d = e[i][0].second.second;
			w = v;
			for (int j = 1; j * j <= d; ++j) {
				if (d % j == 0 && gcd(j, d / j) == 1) {
					v[i] = j * c;
					v[b] = d / j * c;
					if (gao(i) && gao(b)) {
						break;
					} else {
						v = w;
					}
					if (d / j > j) {
						v = w;
						v[i] = d / j * c;
						v[b] = j * c;
						if (gao(i) && gao(b)) {
							break;
						} else {
							v = w;
						}
					}
				}
			}
			if (v[i] == 0) {
				no();
			}
		}
	}

	puts("YES");
	for (int i = 0; i < n; ++i) {
		printf("%d ", v[i]);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//292300 	Feb 20, 2011 11:18:12 AM 	watashi 	60C - Mushroom Strife 	GNU C++ 	Accepted 	30 ms 	1600 KB 
