#include <map>
#include <queue>
#include <limits>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2048;
const int MAXM = 4096;

struct Edge {
	int v, c, w;
	Edge() { }
	Edge(int v, int c, int w) : v(v), c(c), w(w) { }
};

struct NegativeCostCircuitExistsException {
};

struct MinCostMaxFlow {
	int n, m, source, sink;
	vector<int> e[MAXN];
	Edge edge[MAXM * 2];

	void init(int n, int source, int sink) {
		this->n = n;
		this->m = 0;
		this->source = source;
		this->sink = sink;
		for (int i = 0; i < n; ++i) {
			e[i].clear();
		}
	}

	void addEdge(int a, int b, int c, int w) {
		edge[m] = Edge(b, c, w);
		e[a].push_back(m++);
		edge[m] = Edge(a, 0, -w);
		e[b].push_back(m++);
	}

	bool mark[MAXN];
	int maxc[MAXN];
	int minw[MAXN];
	int pre[MAXN];
	int d[MAXN];

	// assert @return == true
	bool _spfa() {
		deque<int> q;

		fill(mark, mark + n, false);
		fill(maxc, maxc + n, 0);
		fill(minw, minw + n, numeric_limits<int>::max());
		fill(pre, pre + n, -1);
		fill(d, d + n, 0);
		mark[source] = true;
		maxc[source] = numeric_limits<int>::max();
		minw[source] = 0;
		// pre[source] = source;
		q.push_back(source);
		while (!q.empty()) {
			int cur = q.front();
//			fprintf(stderr, "%d %d %d\n", cur, maxc[cur], minw[cur]);
			mark[cur] = false;
			q.pop_front();
			for (size_t i = 0; i < e[cur].size(); ++i) {
				int id = e[cur][i];
				int v = edge[id].v;
				int c = min(maxc[cur], edge[id].c);
				if (c == 0) {	// ~~
					continue;
				}
				int w = minw[cur] + edge[id].w;
				if (minw[v] > w || (minw[v] == w && maxc[v] < c)) {
					maxc[v] = c;
					minw[v] = w;
					pre[v] = id;	// e not v !
					d[v] = d[cur] + 1;
					if (d[v] >= n) {
						return false;
					}
					if (!mark[v]) {
						mark[v] = true;
                        if (!q.empty() && d[v] < d[q.front()]) {
                            q.push_front(v);
                        } else {
                            q.push_back(v);
                        }
					}
				}
			}
		}

		return true;
	}

	pair<int, int> gao() {
		int sumc = 0, sumw = 0;

		while (true) {
			if (!_spfa()) {
				throw NegativeCostCircuitExistsException();
			} else if (maxc[sink] == 0) {
				break;
			} else {
				int c = maxc[sink];
				sumc += c;
				sumw += c * minw[sink];
				int cur = sink;
				while (cur != source) {
					int id = pre[cur];
					edge[id].c -= c;
					edge[id ^ 1].c += c;
					cur = edge[id ^ 1].v;
				}
			}
		}

		return make_pair(sumc, sumw);
	}
} mcmf;

inline int IN(int i) { return i << 1; }
inline int OUT(int i) { return IN(i) ^ 1; }

int s[MAXN], t[MAXN], c[MAXN], e[MAXN];

int main() {
    int n, m, k;
    map<int, int> mp;

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &s[i], &t[i], &c[i]);
        t[i] += s[i];
        mp[s[i]];
        mp[t[i]];
    }
    m = 0;
    for (auto& i: mp) {
        i.second = m++;
    }

    mcmf.init(m + 1, m, m - 1);
    mcmf.addEdge(m, 0, k, 0);
    for (int i = 1; i < m; ++i) {
        mcmf.addEdge(i - 1, i, k, 0);
    }
    for (int i = 0; i < n; ++i) {
        e[i] = mcmf.m;
        mcmf.addEdge(mp[s[i]], mp[t[i]], 1, -c[i]);
    }

    pair<int, int> ans = mcmf.gao();
    // printf("%d %d\n", ans.first, -ans.second);
    for (int i = 0; i < n; ++i) {
        printf("%d%c", 1 - mcmf.edge[e[i]].c, i == n - 1 ? '\n' : ' ');
    }

    return 0;
}
