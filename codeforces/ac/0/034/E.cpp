#include <set>
#include <cmath>
#include <cstdio>
#include <utility>

using namespace std;

const double EPS = 1e-8;

int main() {
	int n, a, b;
	double t, dt, tmp, x[20], v[20], m[20];
	set<pair<int, int> > done;

	scanf("%d%lf", &n, &t);
	for (int i = 0; i < n; ++i) {
		scanf("%lf%lf%lf", &x[i], &v[i], &m[i]);
	}
	while (t > 0) {
		dt = t;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (done.count(make_pair(i, j)) == 0 && fabs(v[i] - v[j]) > EPS) {
					tmp = (x[j] - x[i]) / (v[i] - v[j]);
					if (tmp > -EPS && tmp < dt) {
						dt = tmp;
						a = i;
						b = j;
					}
				}
			}
		}
		if (dt > EPS) {
			done.clear();
			t -= dt;
		}
		done.insert(make_pair(a, b));
		for (int i = 0; i < n; ++i) {
			x[i] += v[i] * dt;
		}
		if (t > EPS) {
			tmp = ((m[a] - m[b]) * v[a] + 2 * m[b] * v[b]) / (m[a] + m[b]);
			v[b] = ((m[b] - m[a]) * v[b] + 2 * m[a] * v[a]) / (m[a] + m[b]);
			v[a] = tmp;
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%.10lf\n", x[i]);
	}

	return 0;
}

// WA21: more than one collision at the same time
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//230180 	Dec 27, 2010 11:59:16 AM 	watashi 	E - Collisions 	GNU C++ 	Accepted 	30 ms 	1308 KB
