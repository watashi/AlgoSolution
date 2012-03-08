#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
const long long INF = 12345678987654321LL;

int p[MAXN];
long long d[MAXN];
vector<pair<int, int> > e[MAXN];

void dump(int i) {
	if (i > 1) {
		dump(p[i]);
	}
	printf("%d ", i);
}

int main() {
	int n, m, a, b, c;
	long long x, y;
	priority_queue<pair<long long, int> > pq;

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		d[i] = INF;
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		e[a].push_back(make_pair(b, c));
		e[b].push_back(make_pair(a, c));
	}

	pq.push(make_pair(-(d[1] = 0), 1));
	while (!pq.empty()) {
		x = -pq.top().first;
		b = pq.top().second;
		pq.pop();
		if (x != d[b]) {
			continue;
		}
		for (vector<pair<int, int> >::const_iterator i = e[b].begin(); i != e[b].end(); ++i) {
			if ((y = x + i->second) < d[i->first]) {
				pq.push(make_pair(-(d[i->first] = y), i->first));
				p[i->first] = b;
			}
		}
	}

	if (d[n] == INF) {
		puts("-1");
	} else {
		dump(n);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//278901 	Feb 11, 2011 6:22:07 PM 	watashi 	C - Dijkstra? 	GNU C++ 	Accepted 	190 ms 	9100 KB
