#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

struct Point {
	int x;
	int y;
	int i;
} p[MAXN];

int tag[MAXN];

int sqr(int x) {
	return x * x;
}

int ans;
Point u, v;

void gao(int n, Point p[]) {
	if (n < 2) {
		return;
	}
	int m = n / 2;
	int xm = p[m].x;
	gao(m, p);
	gao(n - m, p + m);
	inplace_merge(p, p + m, p + n, [](const Point& lhs, const Point& rhs){ return lhs.y < rhs.y; });
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		if (sqr(p[i].x - xm) < ans) {
			v.push_back(i);
		}
	}
	for (int i = 0; i < (int)v.size(); ++i) {
		for (int j = i + 1;  j < (int)v.size() && p[v[j]].y - p[v[i]].y < ans; ++j) {
			int tmp = sqr(p[v[i]].x - p[v[j]].x) + sqr(p[v[i]].y - p[v[j]].y);
			if (ans > tmp) {
				ans = tmp;
				::u = p[v[i]];
				::v = p[v[j]];
			}
		}
	}
}

int main() {
#ifndef __WATASHI__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		p[i].i = i;
		scanf("%d%d", &p[i].x, &p[i].y);
		tag[i] = 0;
		if (p[i].x < 0) {
			p[i].x = -p[i].x;
			tag[i] ^= 1;
		}
		if (p[i].y < 0) {
			p[i].y = -p[i].y;
			tag[i] ^= 2;
		}
	}
	ans = 2 * 1000000007;
	sort(p, p + n, [](const Point& lhs, const Point& rhs){ return lhs.x < rhs.x; });
	gao(n, p);
	//	printf("%d\n", ans);
	//	printf("%d %d %d\n", u.x, u.y, u.i);
	//	printf("%d %d %d\n", v.x, v.y, v.i);
	printf("%d %d %d %d\n", u.i + 1, tag[u.i] + 1, v.i + 1, (tag[v.i] ^ 3) + 1);

	return 0;
}
