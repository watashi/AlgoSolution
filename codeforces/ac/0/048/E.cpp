#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

const int MAXN = 218;
const int INF = 1000000000;

struct Act {
	int ch, ct, gh, gt;
};

int done[MAXN][MAXN];
int dp[MAXN][MAXN];
int h0, t0, r, n, m;
vector<Act> v;

int gao(int hh, int tt) {
	if (hh + tt > r) {
		return 0;
	} else if (done[hh][tt] == 1) {
		return dp[hh][tt];
	} else if (done[hh][tt] == -1) {
		return INF;
	} else {
		int& ret = dp[hh][tt];
		done[hh][tt] = -1;
		for (vector<Act>::const_iterator it = v.begin(); it != v.end(); ++it) {
			if (hh >= it->ch && tt >= it->ct) {
				ret = max(ret, gao(hh - it->ch + it->gh, tt - it->ct + it->gt) + 1);
			}
		}
		done[hh][tt] = 1;
		return ret;
	}
}

int main() {
	scanf("%d%d%d", &h0, &t0, &r);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		v.push_back(Act());
		v.back().ch = i;
		v.back().ct = 0;
		scanf("%d%d", &v.back().gh, &v.back().gt);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		v.push_back(Act());
		v.back().ch = 0;
		v.back().ct = i;
		scanf("%d%d", &v.back().gh, &v.back().gt);
	}

	queue<pair<int, int> > q;
	done[0][0] = 1;
	dp[0][0] = -1;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int hh = q.front().first;
		int tt = q.front().second;
		q.pop();
		for (vector<Act>::const_iterator it = v.begin(); it != v.end(); ++it) {
			if (hh >= it->gh && tt >= it->gt) {
				int h2 = hh - it->gh + it->ch;
				int t2 = tt - it->gt + it->ct;
				if (h2 + t2 <= r && !done[h2][t2]) {
					done[h2][t2] = 1;
					dp[h2][t2] = dp[hh][tt] - 1;
					q.push(make_pair(h2, t2));
				}
			}
		}
	}

	int ans = gao(h0, t0);

	if (ans < 0) {
		printf("Ivan\n%d\n", -ans - 1);
	} else if (ans >= INF) {
		printf("Draw\n");
	} else {
		printf("Zmey\n%d\n", ans);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//218388 	Dec 12, 2010 3:48:06 PM 	watashi 	E - Ivan the Fool VS Gorynych the Dragon 	GNU C++ 	Accepted 	80 ms 	2664 KB 
