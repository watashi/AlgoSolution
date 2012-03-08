#include <set>
#include <map>
#include <list>
#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 3003;
const int INF = 1000000007;

int mind[MAXN][MAXN];
short pre[MAXN][MAXN];
list<int> e[MAXN];
map<pair<short, short>, set<short> > f;

void dump(int i, int j) {
	if (i != 1) {
		dump(pre[i][j], i);
	}
	printf("%d ", i);
}

int main() {
	int n, m, p, a, b, c;
	queue<pair<int, int> > q;

	scanf("%d%d%d", &n, &m, &p);
	fill(mind[1], mind[n + 1], INF);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for (int i = 1; i <= p; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		f[make_pair(a, b)].insert(c);
	}

	for (list<int>::iterator i = e[1].begin(); i != e[1].end(); ++i) {
		mind[1][*i] = 0;
		q.push(make_pair(1, *i));
	}
	e[1].clear();
	while (!q.empty()) {
		a = q.front().first;
		b = q.front().second;
		q.pop();
		const set<short>& st = f.count(make_pair(a, b)) == 0 ? set<short>() : f[make_pair(a, b)];
		for (list<int>::iterator i = e[b].begin(); i != e[b].end(); ) {
			if (st.count(*i) > 0) {
				++i;
			} else {
				mind[b][*i] = mind[a][b] + 1;
				pre[b][*i] = a;
				q.push(make_pair(b, *i));
				i = e[b].erase(i);
			}
		}
	}

	a = INF;
	b = -1;
	for (int i = 1; i <= n; ++i) {
		if (mind[i][n] < a) {
			a = mind[i][n];
			b = i;
		}
	}
	if (b == -1) {
		puts("-1");
	} else {
		printf("%d\n", a + 1);
		dump(b, n);
		printf("%d\n", n);
	}

	return 0;
}

