#include <queue>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 4096;
const int INF = 1000000000;
typedef pair<int,int> PI;
typedef pair<int,PI> PII;
vector<pair<int, int> > e[MAXN];
vector<PII> edge;

int fa[MAXN];
int getFather(int x){
	return fa[x] == -1 ? x : fa[x] = getFather(fa[x]);
}

int dijkstra(int n, int s, int t) {
	static int mind[MAXN], d;
	priority_queue<pair<int, int> > q;

	for (int i = 0; i < n; ++i) {
		mind[i] = INF;
	}
	mind[s] = 0;
	q.push(make_pair(-mind[s], s));
	while (!q.empty()) {
		d = -q.top().first;
		s = q.top().second;
		q.pop();
		if (d != mind[s]) {
			continue;
		} else if (s == t) {
			break;
		}
		for (vector<pair<int, int> >::const_iterator it = e[s].begin(); it != e[s].end(); ++it) {
			if (mind[it->first] > d && mind[it->first] > it->second) {
				mind[it->first] = max(d, it->second);
				q.push(make_pair(-mind[it->first], it->first));
			}
		}
	}
	return mind[t];
}

int main() {
	int re;
	int n, m, q, a, b, c;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		memset(fa, 0xff, sizeof(fa));
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			e[i].clear();
		}
		edge.clear();
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &a, &b, &c);
			--a;
			--b;
			edge.push_back(PII(c,PI(a,b)));
		}
		sort(edge.begin(),edge.end());
		for (int i=0; i<edge.size(); i++){
			int a = edge[i].second.first, b = edge[i].second.second;
			int c = edge[i].first;

			int fx = getFather(a), fy = getFather(b);
			if (fx!=fy){
				fa[fx] = fy;
				e[a].push_back(make_pair(b, c));
				e[b].push_back(make_pair(a, c));
			}
		}

		scanf("%d", &q);
		printf("Case %d\n", ri);
		for (int i = 0; i < q; ++i) {
			scanf("%d%d", &a, &b);
			--a;
			--b;
			printf("%d\n", dijkstra(n, a, b));
		}
		puts("");
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723948  	2011-01-22 17:18:30 	Accepted	2.229	2188	26909	C++	4296 - Bring Your Own Horse

/*
id => 1174114
pid => 4296
pname => Bring Your Own Horse
status => Accepted
lang => C++
time => 0.502
date => 2012-12-14 17:24:27
*/
