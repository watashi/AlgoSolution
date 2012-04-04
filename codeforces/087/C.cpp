#include <set>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 17;

struct SegTree {
	int sg[MAXN + MAXN];

	static int L(int i) { return i * 2; }
	static int R(int i) { return L(i) ^ 1; }

	void set(int i, int j) {
		i += MAXN;
		while (i > 0) {
			sg[i] ^= j;
			i >>= 1;
		}
	}

	int get(int p, int pl, int pr, int l, int r) {
		if (pl == l && pr == r) {
			return sg[p];
		} else {
			int pm = (pl + pr) / 2;
			if (r <= pm) {
				return get(L(p), pl, pm, l, r);
			} else if (pm <= l) {
				return get(R(p), pm, pr, l, r);
			} else {
				return get(L(p), pl, pm, l, pm) ^ get(R(p), pm, pr, pm, r);
			}
		}
	}
} sg;

int how[MAXN];
vector<pair<int, int> > todo[MAXN];

int main() {
	fill(how, how + MAXN, MAXN);
	for (int i = 1; i < MAXN; ++i) {
		for (int s = i, j = i + 1; (s += j) < MAXN; ++j) {
			todo[s].push_back(make_pair(i, j + 1 - i));
		}
	}
	for (int i = 1; i < MAXN; ++i) {
		set<int> st;
		for (vector<pair<int, int> >::const_iterator j = todo[i].begin(); j != todo[i].end(); ++j) {
			int t = sg.get(1, 0, MAXN, j->first, j->first + j->second);
			st.insert(t);
			if (t == 0) {
				how[i] = min(how[i], j->second);
			}
		}
		for (int j = 0; ; ++j) {
			if (st.count(j) == 0) {
				sg.set(i, j);
				break;
			}
		}
		if (i <= 1000) {
			// printf("%d (%d)\n", sg.get(1, 0, MAXN, i, i + 1), how[i]);
			// printf("%d\n", how[i]);
		}
	}

	int n;

	scanf("%d", &n);
	printf("%d\n", how[n] == MAXN ? -1 : how[n]);

	return 0;
}

