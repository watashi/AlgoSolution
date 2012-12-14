#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 128;
const int INF = 1000000007;

int d[MAXN][MAXN];
vector<pair<int, int> > e[MAXN];

int gao(int n, int m) {
	int ret = INF;
	priority_queue<pair<int, pair<int, int> > > pq;
	
	fill(d[0], d[n], INF);
	d[0][0] = 0;
	pq.push(make_pair(-d[0][0], make_pair(0, 0)));
	while (!pq.empty()) {
		int u = -pq.top().first;
		int v = pq.top().second.first;
		int w = pq.top().second.second;
		pq.pop();
		if (d[v][w] != u) {
			continue;
		}

		if (u > m) {
			break;
		} else if (v == n - 1) {
			ret = min(ret, w);
		}

		for (vector<pair<int, int> >::const_iterator it = e[v].begin(); it != e[v].end(); ++it) {
			if (w + 1 < n && d[it->first][w + 1] > d[v][w]) {
				d[it->first][w + 1] = d[v][w];
				pq.push(make_pair(-d[it->first][w + 1], make_pair(it->first, w + 1)));
			}
			if (d[it->first][w] > d[v][w] + it->second) {
				d[it->first][w] = d[v][w] + it->second;
				pq.push(make_pair(-d[it->first][w], make_pair(it->first, w)));
			}
		}
	}

	return ret;
}

int main() {
	int n, m, a, b, c, d;

	while (scanf("%d%d%d", &n, &m, &d) != EOF && n > 0) {
		for (int i = 0; i < n; ++i) {
			e[i].clear();
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &a, &b, &c);
			--a;
			--b;
			e[a].push_back(make_pair(b, c));
		}
		printf("%d\n", gao(n, d));
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//772424  	2011-04-29 08:53:40 	Accepted	0.482	756	26909	C++	5073 - Test Case Tweaking
/*
id => 1174079
pid => 5073
pname => Test Case Tweaking
status => Accepted
lang => C++
time => 0.102
date => 2012-12-14 17:19:26
*/
