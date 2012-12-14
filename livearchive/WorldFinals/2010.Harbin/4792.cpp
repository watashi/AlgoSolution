#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 1 << 20;
const int INF = 1000000007;
map<string, int> mp;
set<pair<int, int> > st;
vector<pair<double, int> > e[MAXN];
int x[MAXN], y[MAXN], z[MAXN], h[MAXN];

void add(priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >& pq, int i) {
	if (h[i] == INF) {
//		printf("add %d\n", i);
		h[i] = z[i];
		pq.push(make_pair(h[i], i));
	}
}

int floodfill(int s) {
	int ret = h[s];
	if (h[s] > z[s]) {
		h[s] = -1;
		for (vector<pair<double, int> >::iterator j = e[s].begin(); j != e[s].end(); ++j) {
			if (h[j->second] != -1) {
				ret = min(ret, floodfill(j->second));
			}
		}
	}
	return ret;
}

int main() {
	int ri = 0, n, m, a, b;
	char buf[80];

	while (scanf("%d%d", &n, &m) != EOF && n > 0) {
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

		for (int i = 0; i < n; ++i) {
			scanf("%s%d%d%d", buf, &x[i], &y[i], &z[i]);
			mp[buf] = i;
			e[i].clear();
			h[i] = INF;
		}
		st.clear();
		for (int i = 0; i < m; ++i) {
			scanf("%s", buf);
			a = mp[buf];
			scanf("%s", buf);
			b = mp[buf];
			e[a].push_back(make_pair(0.0, b));
			e[b].push_back(make_pair(0.0, a));
			st.insert(make_pair(a, b));
			st.insert(make_pair(b, a));
		}

		for (int i = 0; i < n; ++i) {
			for (vector<pair<double, int> >::iterator j = e[i].begin(); j != e[i].end(); ++j) {
				j->first = atan2(y[i] - y[j->second], x[i] - x[j->second]);
			}
			sort(e[i].begin(), e[i].end());
			for (int j = 0; j < (int)e[i].size(); ++j) {
				if (fmod(e[i][(j + 1) % e[i].size()].first - e[i][j].first + 2 * M_PI, 2 * M_PI) >= M_PI ||
						st.count(make_pair(e[i][j].second, e[i][(j + 1) % e[i].size()].second)) == 0) {
					add(pq, e[i][j].second);
					add(pq, e[i][(j + 1) % e[i].size()].second);
				}
			}
		}

		while (!pq.empty()) {
			int hh = pq.top().first;
			int s = pq.top().second;
			pq.pop();
			if (h[s] != hh) {
				continue;
			}
			for (vector<pair<double, int> >::iterator j = e[s].begin(); j != e[s].end(); ++j) {
				if (h[j->second] > max(z[j->second], hh)) {
					h[j->second] = max(z[j->second], hh);
					pq.push(make_pair(h[j->second], j->second));
				}
			}
		}

//		for (int i = 0; i < n; ++i) {
//			printf("[%d] h = %d; z = %d;\n", i, h[i], z[i]);
//		}

		vector<int> ans;
		for (int i = 0; i < n; ++i) {
			if (h[i] > z[i]) {
				ans.push_back(floodfill(i));
			}
		}
		if (ans.empty()) {
			ans.push_back(0);
		}
		sort(ans.begin(), ans.end());
		printf("Case %d:\n", ++ri);
		for (int i = 0; i < (int)ans.size(); ++i) {
			printf("  %d\n", ans[i]);
		}
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805865 	4792 	Rain 	Accepted 	C++ 	0.544 	2011-05-23 14:06:02
/*
id => 1174053
pid => 4792
pname => Rain
status => Accepted
lang => C++
time => 0.355
date => 2012-12-14 17:15:49
*/
