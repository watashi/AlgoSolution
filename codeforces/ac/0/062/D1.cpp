#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 128;

vector<int> e[MAXN];
int dfn[MAXN], low[MAXN], st[MAXN], top;
set<pair<int, int> > keyE;

void tarjan(int now, int cnt){
	st[top++] = now;
	dfn[now] = low[now] = cnt;
	for (int ii = e[now].size() - 1; ii >= 0; --ii){
		int i = e[now][ii];
		if (!dfn[i]){
			tarjan(i, cnt + 1);
			low[now] = min(low[now], low[i]);
			if (low[i] > dfn[now])
				keyE.insert(make_pair(now, i));
		}
		else if (dfn[i] != dfn[now] - 1)
			low[now] = min(low[now], dfn[i]);
	}
}
void ArtEdge_ArtVertex_Components(int N){
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));     
	keyE.clear();
	for (int i = top = 0; i < N; ++i)
		if (!dfn[i])
			tarjan(i, 1);
}

int main() {
	int n, m, a, b;
	vector<int> v, w;

	scanf("%d%d", &n, &m);
	v.resize(m + 1);
	for (int i = 0; i <= m; ++i) {
		scanf("%d", &v[i]);
		--v[i];
	}
	for (int i = m; i >= 0; --i) {
	//	printf("gao(%d): %d => %d\n", i, v[i - 1], v[i]);
		if (i == 0) {
			puts("No solution");
			return 0;
		}
		a = v[i - 1];
		b = v[i];
		e[a].push_back(b);
		e[b].push_back(a);
		ArtEdge_ArtVertex_Components(n);
		sort(e[a].begin(), e[a].end());
		for (vector<int>::const_iterator it = upper_bound(e[a].begin(), e[a].end(), b); it != e[a].end(); ++it) {
		//	printf("? %d\n", *it);
			if (keyE.count(make_pair(a, *it)) == 0 && keyE.count(make_pair(*it, a)) == 0) {
				b = *it;
		//		printf("%d -> %d\n", a, b);
		//		v.erase(v.begin() + i, v.end());
				v.resize(i);
				v.push_back(b);
				e[a].erase(find(e[a].begin(), e[a].end(), b));
				e[b].erase(find(e[b].begin(), e[b].end(), a));
				for (int k = 1; k <= n; ++k) {
					sort(e[k].begin(), e[k].end());
				}
				while ((int)v.size() > i) {
					a = v.back();
					if (e[a].empty()) {
						v.pop_back();
						w.push_back(a);
					} else {
						b = e[a][0];
						e[a].erase(find(e[a].begin(), e[a].end(), b));
						e[b].erase(find(e[b].begin(), e[b].end(), a));
						v.push_back(b);
					}
				}
				v.insert(v.end(), w.rbegin(), w.rend());
				for (int i = 0; i <= m; ++i) {
					printf("%d ", v[i] + 1);
				}
				return 0;
			}
		}
	}

	return 0;
}

