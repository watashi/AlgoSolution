#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 100100;
const int INF = 1000000007;

int f[MAXN], s[MAXN], tag[MAXN], pre[MAXN];
vector<int> c[MAXN];
PII dp[MAXN][2];

PII operator+(const PII& lhs, const PII& rhs) {
	return make_pair(lhs.first + rhs.first, lhs.second + rhs.second);
}

PII operator-(const PII& lhs, const PII& rhs) {
	return make_pair(lhs.first - rhs.first, lhs.second - rhs.second);
}

void gao(int v) {
	if (tag[v] == 0) {
		tag[v] = 1;
	}
	dp[v][0] = make_pair(0, 0);
	dp[v][1] = make_pair(0, 0);
	pre[v] = -1;
	for (vector<int>::const_iterator w = c[v].begin(); w != c[v].end(); ++w) {
		if (tag[*w] == -1) {
			continue;		
		}
		gao(*w);
		dp[v][0] = dp[v][0] + dp[*w][1];
		PII tmp = make_pair(1, s[v] == s[*w] ? 0 : 1) - (dp[*w][1] - dp[*w][0]);
		if (dp[v][1] < tmp) {
			dp[v][1] = tmp;
			pre[v] = *w;
		}
	}
	dp[v][1] = dp[v][1] + dp[v][0];
//	printf("@%d: <%d, %d> <%d, %d>\n", v, dp[v][0].first, dp[v][0].second, dp[v][1].first, dp[v][1].second);
}

void dump(int v, bool f, vector<PII>& ret) {
	for (vector<int>::const_iterator w = c[v].begin(); w != c[v].end(); ++w) {
		if (tag[*w] == -1) {
			continue;		
		}
		if (!f || *w != pre[v]) {
			dump(*w, true, ret);
		} else {
			ret.push_back(make_pair(v, *w));
			dump(*w, false, ret);
		}
	}
}

PII cdp[MAXN][2];
int cpre[MAXN];
PII ans;
vector<PII> todo;

void solve(int v) {
	while (tag[v] == 0) {
		tag[v] = 1;
		v = f[v];
	}
	vector<int> circ(1, v);
	for (int w = f[v]; w != v; w = f[w]) {
		circ.push_back(w);
	}

	int n = (int)circ.size();
	
//	printf("solve(%d):\n", v);
//	for (int i = 0; i < n; ++i) {
//		printf("\t%d", circ[i]);
//	}
//	puts("");

	for (int i = 0; i < n; ++i) {
		tag[circ[i]] = -1;
	}
	for (int i = 0; i < n; ++i) {
		gao(circ[i]);
//		printf("gao(%d): <%d, %d> <%d, %d>\n", circ[i], dp[circ[i]][0].first, dp[circ[i]][0].second, dp[circ[i]][1].first, dp[circ[i]][1].second);
	}

	// (n-1) -> 0: no
	cdp[circ.front()][0] = dp[circ.front()][0];
	cdp[circ.front()][1] = dp[circ.front()][1];
	cpre[circ.front()] = -1;
	for (vector<int>::const_iterator i = circ.begin() + 1; i != circ.end(); ++i) {
		vector<int>::const_iterator j = i - 1;
		cdp[*i][0] = cdp[*j][1] + dp[*i][0];
		cdp[*i][1] = cdp[*j][1] + dp[*i][1];
		cpre[*i] = -1;
		PII tmp = cdp[*j][0] + make_pair(1, s[*i] == s[*j] ? 0 : 1) + dp[*i][0];
		if (cdp[*i][1] < tmp) {
			cdp[*i][1] = tmp;
			cpre[*i] = 1;
		}
	}
	PII best = cdp[circ.back()][1];
//	printf("b %d %d\n", best.first, best.second);
	vector<PII> how;
	for (vector<int>::const_iterator i = circ.end() - 1; i >= circ.begin(); ) {
		if (cpre[*i] == -1) {
			dump(*i, true, how);
			--i;
		} else {
			dump(*i, false, how);
			dump(*(i - 1), false, how);
			how.push_back(make_pair(*i, *(i - 1)));
			i -= 2;
		}
	}

	rotate(circ.begin(), circ.begin() + 1, circ.end());
	cdp[circ.front()][0] = dp[circ.front()][0];
	cdp[circ.front()][1] = dp[circ.front()][1];
	cpre[circ.front()] = -1;
	for (vector<int>::const_iterator i = circ.begin() + 1; i != circ.end(); ++i) {
		vector<int>::const_iterator j = i - 1;
		cdp[*i][0] = cdp[*j][1] + dp[*i][0];
		cdp[*i][1] = cdp[*j][1] + dp[*i][1];
		cpre[*i] = -1;
		PII tmp = cdp[*j][0] + make_pair(1, s[*i] == s[*j] ? 0 : 1) + dp[*i][0];
		if (cdp[*i][1] < tmp) {
			cdp[*i][1] = tmp;
			cpre[*i] = 1;
		}
	}
//	printf("b %d %d\n", cdp[circ.back()][1].first, cdp[circ.back()][1].second);
	if (best < cdp[circ.back()][1]) {
		best = cdp[circ.back()][1];
		how.clear();
		for (vector<int>::const_iterator i = circ.end() - 1; i >= circ.begin(); ) {
			if (cpre[*i] == -1) {
				dump(*i, true, how);
				--i;
			} else {
				dump(*i, false, how);
				dump(*(i - 1), false, how);
				how.push_back(make_pair(*i, *(i - 1)));
				i -= 2;
			}
		}
	}

	ans = ans + best;
	todo.insert(todo.end(), how.begin(), how.end());
}

int main() {
	int n;

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &f[i], &s[i]);
		c[f[i]].push_back(i);
	}
	ans = make_pair(0, 0);
	todo.clear();
	for (int i = 1; i <= n; ++i) {
		if (tag[i] == 0) {
			solve(i);
		}
	}
	printf("%d %d\n", ans.first, ans.second);
	for (vector<PII>::const_iterator it = todo.begin(); it != todo.end(); ++it) {
		printf("%d %d\n", it->first, it->second);
	}

	return 0;
}

