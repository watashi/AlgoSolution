#include <set>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

struct DisjointSet {
	int p[MAXN];
	int c[MAXN];

	void init(int n) {
		for (int i = 0; i < n; ++i) {
			p[i] = i;
			c[i] = 1;
		}
	}

	int getp(int i) {
		return i == p[i] ? i : (p[i] = getp(p[i]));
	}

	void setp(int i, int j) {
		i = getp(i);
		j = getp(j);
		if (i != j) {
			c[i] += c[j];
			p[j] = i;
		}
	}
} ds;

struct Edge {
	int i, a, b, d;
	bool operator<(const Edge& o) const {
		return d < o.d;
	}
} edge[MAXN];

long long sc;
int c[MAXN], f[MAXN], tag[MAXN];
vector<pair<int, int> > e[MAXN];

long long ans;
vector<int> how;

int dfs(int v, int p, int t) {
	tag[v] = t;
	for (vector<pair<int, int> >::const_iterator i = e[v].begin(); i != e[v].end(); ++i) {
		int w = i->first;
		if (w != p) {
			f[w] = i->second;
			c[v] += dfs(w, v, t);
		}
	}
	return c[v];
}

int main() {
	int n;

	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		edge[i].i = i;
		scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].d);
		--edge[i].a;
		--edge[i].b;
	}
	sort(edge + 1, edge + n);
	ds.init(n);

	for (int i = 1, j; i < n; i = j) {
		set<int> _todo;
		for (j = i; j < n && edge[j].d == edge[i].d; ++j) {
			_todo.insert(ds.getp(edge[j].a));
			_todo.insert(ds.getp(edge[j].b));
		}
	//	printf("gao %d = [%d, %d)\n", edge[i].d, i, j);

		vector<int> todo(_todo.begin(), _todo.end());
		sc = 0;
		for (vector<int>::const_iterator v = todo.begin(); v != todo.end(); ++v) {
			e[*v].clear();
			c[*v] = ds.c[*v];
			tag[*v] = -1;
	//		sc += c[t];
	//		printf("c[%d] = %d\n", t, c[t]);
		}

		for (int k = i; k < j; ++k) {
			int a = ds.getp(edge[k].a);
			int b = ds.getp(edge[k].b);
			e[a].push_back(make_pair(b, edge[k].i));
			e[b].push_back(make_pair(a, edge[k].i));
		}
	//	dfs(todo[0], -1);
	
		for (vector<int>::const_iterator v = todo.begin(); v != todo.end(); ++v) {
			if (tag[*v] == -1) {
				dfs(*v, -1, *v);
			}
		}

		for (vector<int>::const_iterator v = todo.begin(); v != todo.end(); ++v) {
	//		printf("@%d %d ? %d\n", *v, c[tag[*v]], c[*v]);
			long long tmp = 1LL * (c[tag[*v]] - c[*v]) * c[*v];
			if (ans < tmp) {
				ans = tmp;
				how.clear();
			}
			if (ans == tmp) {
				how.push_back(f[*v]);
			}
		}
		
		for (int k = i; k < j; ++k) {
			ds.setp(edge[k].a, edge[k].b);
		}
	}

	printf("%I64d %d\n", 2 * ans, (int)how.size());
//	printf("%lld %d\n", 2 * ans, (int)how.size());
	sort(how.begin(), how.end());
	for (int i = 0; i < (int)how.size(); ++i) {
		printf("%d%c", how[i], i == (int)how.size() - 1 ? '\n' : ' ');
	}
	
	return 0;
}

