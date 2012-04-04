#include <set>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
	int x, y;
};

bool operator<(const Point& lhs, const Point& rhs) {
	return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y);
}

set<Point> w;
set<int> sx, sy;
vector<Point> v;

void gao(const Point& p) {
	if (!w.insert(p).second) {
		return;
	}
	vector<Point> todo;
	set<int>::const_iterator it;
	it = sx.lower_bound(p.x);
	if (it != sx.end()) {
		todo.push_back({*it, p.y});
	}
	if (it != sx.begin()) {
		--it;
		todo.push_back({*it, p.y});
	}
	it = sy.lower_bound(p.y);
	if (it != sy.end()) {
		todo.push_back({p.x, *it});
	}
	if (it != sy.begin()) {
		--it;
		todo.push_back({p.x, *it});
	}
	sx.insert(p.x);
	sy.insert(p.y);
	for (Point q: todo) {
		gao(q);
	}
}

int main() {
	int n;

	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &v[i].x, &v[i].y);
	}
	for (Point p: v) {
		gao(p);
	//	printf("%d\n", w.size());
	}
	printf("%d\n", w.size());
	for (Point p: w) {
		printf("%d %d\n", p.x, p.y);
	}

	return 0;
}
