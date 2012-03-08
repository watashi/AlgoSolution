#include <set>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef vector<PII> VP;
typedef set<int> SI;

#define itr const_iterator
#define fst first
#define snd second

const int INF = 1024;
const int MAXN = 52;
const int SIGMA = 27;

VP v[SIGMA];

void gao(int n, char s[MAXN], SI m[MAXN][SIGMA]) {
	for (int k = n - 1; k >= 0; --k) {
		queue<PII> q;
		m[k][s[k] - 'a'].insert(k + 1);
		q.push(make_pair(s[k] - 'a', k + 1));
		while (!q.empty()) {
			int i = q.front().fst;
			int j = q.front().snd;
			q.pop();
			for (VP::itr it = v[i].begin(); it != v[i].end(); ++it) {
				for (SI::itr jt = m[j][it->fst].begin(); jt != m[j][it->fst].end(); ++jt) {
					if (m[k][it->snd].insert(*jt).snd) {
						q.push(make_pair(it->snd, *jt));
					}
				}
			}
		}
	}
}

SI ma[MAXN][SIGMA], mb[MAXN][SIGMA];
int mind[MAXN][MAXN];

int main() {
	int na, nb, n;
	char sa[MAXN], sb[MAXN], s[MAXN];

	scanf("%s%s", sa, sb);
	na = strlen(sa);
	nb = strlen(sb);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		v[s[3] - 'a'].push_back(make_pair(s[4] - 'a', s[0] - 'a'));
	}
	gao(na, sa, ma);
	gao(nb, sb, mb);

	fill(mind[0], mind[na + 1], INF);
	mind[0][0] = 0;
	for (int i = 0; i < na; ++i) {
		for (int j = 0; j < nb; ++j) {
			if (mind[i][j] == INF) {
				continue;
			}
			// we can use bitwise mask to optimize these three for loops into two loops (1/26)
			// ok[i][j] & (1 << k) <=> m[i][k].count(j) > 0
			for (int k = 0; k < SIGMA; ++k) {
				for (SI::itr it = ma[i][k].begin(); it != ma[i][k].end(); ++it) {
					for (SI::itr jt = mb[j][k].begin(); jt != mb[j][k].end(); ++jt) {
						mind[*it][*jt] = min(mind[*it][*jt], mind[i][j] + 1);
					}
				}
			}
		}
	}
	printf("%d\n", mind[na][nb] == INF ? -1 : mind[na][nb]);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//229566 	Dec 24, 2010 8:04:14 PM 	watashi 	E - Common ancestor 	GNU C++ 	Accepted 	480 ms 	3320 KB 
