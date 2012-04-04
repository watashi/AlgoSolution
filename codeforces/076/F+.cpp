#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	int n, x, t, u, v;
	vector<long long> b;
	vector<pair<long long, long long> > a;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x, &t);
		a.push_back(make_pair(x, t));
	}
	scanf("%d", &v);
	a.push_back(make_pair(0, 0));
	for (int i = 0; i < (int)a.size(); ++i) {
		a[i] = make_pair(a[i].first + v * a[i].second, -(a[i].first - v * a[i].second));
	}
	sort(a.rbegin(), a.rend());

	u = v = 0;
	for (int i = 0; i < (int)a.size(); ++i) {
		x = -a[i].second;
		t = upper_bound(b.begin(), b.end(), x) - b.begin();
		if (t == (int)b.size()) {
			b.push_back(x);
		} else {
			b[t] = x;
		}
		if (a[i] == make_pair(0LL, 0LL)) {
			u = max(u, t);
		} else {
			v = max(v, t + 1);
		}
	}
	printf("%d %d\n", u, v);

	return 0;
}

// 问题转为最多有多少个相似的等腰三角形相互嵌套，又可以转为LIS……
//
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//457318 	May 17, 2011 1:07:07 AM 	watashi 	76F - Tourist 	GNU C++ 	Accepted 	110 ms 	4500 KB 
