#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

const int MAXN = 1024;
const long long INF = 1000000007LL * 1000000007LL;

vector<pair<int, int> > e[MAXN], ee[MAXN];
long long mind[MAXN];

void sp(int n, int s) {
	priority_queue<pair<long long, int> > pq;

	for (int i = 0; i < n; ++i) {
		mind[i] = INF;
	}
	mind[s] = 0;
	pq.push(make_pair(-mind[s], s));
	while (!pq.empty()) {
		s = pq.top().second;
		if (pq.top().first != -mind[s]) {
			pq.pop();
			continue;
		}
		pq.pop();
		for (auto ei: e[s]) {
			if (mind[ei.first] > mind[s] + ei.second) {
				mind[ei.first] = mind[s] + ei.second;
				pq.push(make_pair(-mind[ei.first], ei.first));
			}
		}
	}
}

int main() {
	int n, m, s, t, a, b, c;

	scanf("%d%d%d%d", &n, &m, &s, &t);
	--s;
	--t;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		--a;
		--b;
		e[a].push_back(make_pair(b, c));
		e[b].push_back(make_pair(a, c));
	}

	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a, &b);
		sp(n, i);
		for (int j = 0; j < n; ++j) {
			if (mind[j] <= a) {
				ee[i].push_back(make_pair(j, b));
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		e[i].swap(ee[i]);
	}
	sp(n, s);
	cout << (mind[t] < INF ? mind[t] : -1LL) << endl;

	return 0;
}

