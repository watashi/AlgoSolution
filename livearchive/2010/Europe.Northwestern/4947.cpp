#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	int re, n;
	bool flag;
	double alpha, beta, gamma, vmax, flue;
	double x, y, z, ans;
	vector<pair<double, double> > v;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%lf%lf%lf%lf", &alpha, &beta, &vmax, &flue);
		scanf("%d", &n);
		v.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%lf%lf", &x, &y);
			x /= 1000;
			y /= 1000;
		//	z = hypot(x, y);
			z = sqrt(x * x + y * y);
			gamma = y / x;
			if (y >= 0) {
				v.push_back(make_pair(0, z));
				flue -= beta * gamma * z;
			} else {
				v.push_back(make_pair(beta * -gamma / alpha, z));
			}
		}
		v.push_back(make_pair(1e100, 0));
		
		sort(v.begin(), v.end());
		for (int i = 0; i < (int)v.size(); ++i) {
			if (alpha * (v[i + 1].first - v[i].first) * v[i].second > flue) {
				v[i].first += max(0.0, flue / alpha / v[i].second);
				break;
			} else {
				flue -= alpha * (v[i + 1].first - v[i].first) * v[i].second;
				v[i + 1].second += v[i].second;
				v[i].second = 0;
			}
		}
		flag = false;
		ans = 0;
		for (int i = 0 ; i < (int)v.size(); ++i) {
			if (v[i].second > 0) {
				if (v[i].first <= 0) {
					flag = true;
				} else {
					ans += v[i].second / min(vmax, v[i].first);
				}
			}
		}
		if (flag || ans > 1e100) {
			puts("IMPOSSIBLE");
		} else {
			printf("%.6lf\n", ans);
		}
	}

	return 0;
}

// 看错题…… IDEA
/*
id => 1174277
pid => 4947
pname => Hill Driving
status => Accepted
lang => C++
time => 0.029
date => 2012-12-14 17:47:49
*/
