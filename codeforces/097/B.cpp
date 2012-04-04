#include <set>
#include <map>
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

int main() {
	int n;
	set<int> st;
	set<Point> w;
	vector<Point> v;
	map<int, set<int> > mp;

	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &v[i].x, &v[i].y);
		mp[v[i].x].insert(v[i].y);
	}
	for (map<int, set<int> >::const_iterator it = mp.begin(); it != mp.end(); ++it) {
		map<int, set<int> >::const_iterator jt = it;
		++jt;
		if (jt == mp.end()) {
			continue;
		}
		set<int> y;
		y.insert(it->second.begin(), it->second.end());
		y.insert(jt->second.begin(), jt->second.end());
		for (int yi: y) {
			w.insert({it->first, yi});
			w.insert({jt->first, yi});
		}
	}
	printf("%d\n", w.size());
	for (Point p: w) {
		printf("%d %d\n", p.x, p.y);
	}

	return 0;
}
