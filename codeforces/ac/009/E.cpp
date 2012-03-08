#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

bool v[64];
vector<int> e[64];

void dfs(int p) {
	if (!v[p]) {
		v[p] = true;
		for (int i = 0; i < (int)e[p].size(); ++i) {
			dfs(e[p][i]);
		}
	}
}

int link(int p, int q) {
	if (v[p]) {
		return -1;
	} else {
		v[p] = true;
	}
	int r = -1;
	for (int i = 0; i < (int)e[p].size(); ++i) {
		if (e[p][i] != q) {
			if (r == -1) {
				r = e[p][i];
			} else {
				r = -2;
			}
		}
	}
	if (r == -1) {
		return p;
	} else if (r >= 0) {
		return link(r, p);
	} else {
		return -1;
	}
}

int main() {
	bool flag = true;
	int n, m, a, b;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b);
		--a;
		--b;
		e[a].push_back(b);
		e[b].push_back(a);			
	}
	if (n < m) {
		puts("NO");
	} else if (n == m) {
		dfs(0);
		for (int i = 0; flag && i < n; ++i) {
			flag &= v[i];
			flag &= e[i].size() == 2;
		}
		puts(flag ? "YES\n0" : "NO");
	} else {
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
		for (int i = 0; flag && i < n; ++i) {
			if (!v[i] && e[i].size() <= 1) {
				b = link(i, -1);
				flag &= b != -1;
				a = min(i, b);
				b = max(i, b);
				pq.push(make_pair(a, b));
			}
		}
		for (int i = 0; flag && i < n; ++i) {
			flag &= v[i] || e[i].size() == 0;
		}
		if (flag) {
			vector<pair<int, int> > ans;
			while (pq.size() > 1) {
				pair<int, int> x = pq.top();
				pq.pop();
				pair<int, int> y = pq.top();
				pq.pop();
				ans.push_back(make_pair(x.first, y.first));
				pq.push(make_pair(min(x.second, y.second), max(x.second, y.second)));
			}
			ans.push_back(pq.top());
			puts("YES");
			printf("%d\n", ans.size());
			for (int i = 0; i < (int)ans.size(); ++i) {
				printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
			}
		} else {
			puts("NO");
		}
	}

	return 0;
}

// Case2: 1 1 1 1
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//209250 	Dec 6, 2010 7:53:43 PM 	watashi 	E - Interestring graph and Apples 	GNU C++ 	Accepted 	30 ms 	1308 KB
