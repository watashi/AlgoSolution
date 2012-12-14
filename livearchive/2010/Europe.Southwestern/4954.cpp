#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;

double gao(double w, vector<double> v) {
	double r = w / 2;
	sort(v.begin(), v.end());
	for (int i = 0; i < (int)v.size(); ++i) {
		if (v[i] <= r + EPS) {
			r = max(r, v[i] + w);
		} else {
			break;
		}
	}
	return r;
}

int main() {
	int nx, ny;
	double w;
	vector<double> vx, vy;

	while (scanf("%d%d%lf", &nx, &ny, &w) != EOF && nx > 0 && ny > 0) {
		vx.resize(nx);
		for (int i = 0; i < nx; ++i) {
			scanf("%lf", &vx[i]);
		}
		vy.resize(ny);
		for (int i = 0; i < ny; ++i) {
			scanf("%lf", &vy[i]);
		}
		puts(gao(w, vx) >= 75 + w / 2 && gao(w, vy) >= 100 + w / 2 ? "YES" : "NO");
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//904126 	4954 	Lawn mower 	Accepted 	C++ 	0.028 	2011-10-11 13:21:35
/*
id => 1174209
pid => 4954
pname => Lawn mower
status => Accepted
lang => C++
time => 0.016
date => 2012-12-14 17:38:55
*/
