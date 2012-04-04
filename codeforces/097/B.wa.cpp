#include <set>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
	int x, y;
};

bool operator<(const Point& lhs, const Point& rhs) {
	return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y > rhs.y);
}

void gao(vector<Point>& v, vector<Point>& ret) {
	sort(v.begin(), v.end());
	ret.clear();
	for (Point p: v) {
		if (ret.empty() || p.y > ret.back().y) {
			if (!ret.empty()) {
				ret.push_back({p.x, ret.back().y});
			}
			ret.push_back(p);
		}
	}
}

int main() {
	int n;
	set<Point> w;
	vector<Point> v, t;

	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &v[i].x, &v[i].y);
	}
	w.insert(v.begin(), v.end());
	for (int xx = 0; xx < 2; ++xx) {
		for (int yy = 0; yy < 2; ++yy) {
			gao(v, t);
			for (Point p: t) {
				if (xx > 0) {
					p.x = -p.x;
				}
				if (yy > 0) {
					p.y = -p.y;
				}
				w.insert(p);
			}
			for (Point& vj: v) {
				vj.y = -vj.y;
			}
		}
		for (Point& vi: v) {
			vi.x = -vi.x;
		}
	}
	printf("%d\n", w.size());
	for (Point p: w) {
		printf("%d %d\n", p.x, p.y);
	}

	return 0;
}
