#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 5050;

int v[MAXN], w[MAXN];
vector<int> ord;
map<int, int> mp;
vector<pair<int, int> > e[MAXN];
priority_queue<int, vector<int>, greater<int> > q[MAXN];

void dfs(int s, pair<int, int> p) {
	ord.push_back(s);
	e[s].erase(remove(e[s].begin(), e[s].end(), p), e[s].end());
	for (int i = 0; i < (int)e[s].size(); ++i) {
		dfs(e[s][i].first, make_pair(s, e[s][i].second));
	}
}

int main() {
	int n, a, b, c;

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		q[i].push(a);
		mp[a] = i;
	}
	for (int i = 1; i < n; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		e[a].push_back(make_pair(b, c));
		e[b].push_back(make_pair(a, c));
	}
	dfs(1, make_pair(-1, -1));

	c = 1;
	for (int t = 1; c < n; ++t) {
		for (vector<int>::const_iterator i = ord.begin(); i != ord.end(); ++i) {
			for (vector<pair<int, int> >::const_iterator j = e[*i].begin(); j != e[*i].end(); ++j) {
				for (int k = 0; k < j->second && !q[j->first].empty(); ++k) {
			//		printf("#%d: %d -> %d\n", q[j->first].top(), j->first, *i);
					if (*i == 1) {
						++c;
						w[mp[q[j->first].top()]] = t;
					} else {
						q[*i].push(q[j->first].top());
					}
					q[j->first].pop();
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		printf("%d%c", w[i], i == n ? '\n' : ' ');
	}
	
	return 0;
}

