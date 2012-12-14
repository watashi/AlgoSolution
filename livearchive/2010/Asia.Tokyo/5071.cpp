#include <queue>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 256;
const double EPS = 1e-8;
const double INF = 1e99;

int x[MAXN], y[MAXN];
double k[MAXN];
double d[MAXN][MAXN];

double _hypot(double x, double y) {
	return sqrt(x * x + y * y);
}

int go(int i, int j) {
	if (i % 2 != 0) {
		return i + j;
	} else {
		return i + j + j;
	}
}

int main() {
	int n, m;
	int a, b, l, r, s, t;
	double c, e;

	while (scanf("%d", &n) != EOF && n > 0) {
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &x[i], &y[i]);
		}
		for (int i = 1; i < n; ++i) {
			k[i] = _hypot(1.0 * (x[i] - x[i - 1]) / (y[i] - y[i - 1]), 1.0);
		}
		m = 2 * (n - 1);
		for (int i = 0; i <= m; ++i) {
			for (int j = 0; j <= m; ++j) {
				d[i][j] = INF;
			}
		}

		priority_queue<pair<double, pair<int, int> > > pq;
		pq.push(make_pair(d[0][m] = 0, make_pair(0, m)));
		while (!pq.empty()) {
			a = pq.top().second.first;
			b = pq.top().second.second;
			c = -pq.top().first;
			// printf("[%d, %d] = %lf\n", a, b, c);
			pq.pop();
			if (c != d[a][b]) {
				continue;
			} else if (a == b) {
				printf("%.10lf\n", c);
				break;
			} else {
				s = a % 2 == 0 ? y[a / 2] : y[b / 2];
				for (int i = -1; i <= 1; ++i) {
					for (int j = -1; j <= 1; ++j) {
						l = go(a, i);
						r = go(b, j);
						if (l < 0 || l > m || r < 0 || r > m) {
							continue;
						}
						
						if (i == 0 && r % 2 == 0 && y[r / 2] == s) {
							t = s;
						} else if (j == 0 && l % 2 == 0 && y[l / 2] == s) {
							t = s;
						} else if (i == 0 || j == 0) {
							continue;
						} else if (y[l / 2] <= s && y[r / 2] <= s) {
							t = max(y[l / 2], y[r / 2]);
						} else if (y[l / 2] >= s && y[r / 2] >= s) {
							t = min(y[l / 2], y[r / 2]);
						} else {
							continue;
						}
						
						if (s == t) {
							e = 0;
							if (a % 2 == 0 && l % 2 == 0) {
								e += fabs(x[a / 2] - x[l / 2]);
							}
							if (b % 2 == 0 && r % 2 == 0) {
								e += fabs(x[b / 2] - x[r / 2]);
							}
						} else {
							e = fabs(s - t) * (k[(l - i + 1) / 2] + k[(r - j + 1) / 2]);
						}
						
						if (y[l / 2] != t) {
							l -= i;
						}
						if (y[r / 2] != t) {
							r -= j;
						}
						if (d[l][r] > c + e + EPS) {
							d[l][r] = c + e;
							pq.push(make_pair(-d[l][r], make_pair(l, r)));
						}
					}
				}
			}
		}
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//771922  	2011-04-28 11:04:29 	Accepted	0.066	Minimum	26909	C++	5071 - The Two Men of the Japanese Alps
/*
id => 1174402
pid => 5071
pname => The Two Men of the Japanese Alps
status => Accepted
lang => C++
time => 0.022
date => 2012-12-14 18:55:55
*/
