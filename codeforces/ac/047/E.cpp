#include <cmath>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;
const double g2 = 9.8 / 2;

typedef pair<double, int> PDI;
typedef pair<double, double> PDD;

inline double h(double v, double t) {
	return (v - g2 * t) * t;
}

int main() {
	int n, m;
	double v, vx, vy, yt;
	vector<PDI> a;
	vector<PDD> z, p;

	scanf("%d%lf", &n, &v);
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf", &a[i].first);
		a[i].second = i;
	}
	scanf("%d", &m);
	z.resize(m);
	for (int i = 0; i < m; ++i) {
		scanf("%lf%lf", &z[i].first, &z[i].second);
	}
	sort(a.begin(), a.end());
	sort(z.begin(), z.end());
	p.resize(n);

	m = 0;
	for (int i = 0; i < n; ++i) {
		PDD& r = p[a[i].second];
		vx = v * cos(a[i].first);
		vy = v * sin(a[i].first);
		while (m < (int)z.size()) {
			yt = h(vy, z[m].first / vx);
			if (yt < -EPS) {
				r = make_pair(vx * vy / g2, 0);
				break;
			} else if (yt < z[m].second + EPS) {
				r = make_pair(z[m].first, yt);
				break;
			} else {
				++m;
			}
		}
		if (m == (int)z.size()) {
			r = make_pair(vx * vy / g2, 0);
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%.9lf %.9lf\n", p[i].first, p[i].second);
	}
	
	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//213245 	Dec 11, 2010 12:51:53 AM 	watashi 	E - Cannon 	GNU C++ 	Accepted 	390 ms 	3196 KB 
