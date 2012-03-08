#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 100100;
const int INF = 1000000007;

bool mark[MAXN];
int f[MAXN], s[MAXN], pre[MAXN];
vector<int> c[MAXN];
PII dp[MAXN][2];

PII operator+(const PII& lhs, const PII& rhs) {
	return make_pair(lhs.first + rhs.first, lhs.second + rhs.second);
}

PII operator-(const PII& lhs, const PII& rhs) {
	return make_pair(lhs.first - rhs.first, lhs.second - rhs.second);
}

void gao(int v) {
	mark[v] = true;
	dp[v][0] = make_pair(0, 0);
	dp[v][1] = make_pair(0, 0);
	pre[v] = -1;
	for (vector<int>::const_iterator w = c[v].begin(); w != c[v].end(); ++w) {
		gao(*w);
		dp[v][0] = dp[v][0] + dp[*w][1];
		PII tmp = make_pair(1, s[v] == s[*w] ? 0 : 1) - (dp[*w][1] - dp[*w][0]);
		if (dp[v][1] < tmp) {
			dp[v][1] = tmp;
			pre[v] = *w;
		}
	}
	dp[v][1] = dp[v][1] + dp[v][0];
}

void dump(int v, bool f, vector<PII>& ret) {
	for (vector<int>::const_iterator w = c[v].begin(); w != c[v].end(); ++w) {
		if (!f || *w != pre[v]) {
			dump(*w, true, ret);
		} else {
			ret.push_back(make_pair(v, *w));
			dump(*w, false, ret);
		}
	}
}

PII ans;
vector<PII> todo;

void solve(int v) {
	while (!mark[v]) {
		mark[v] = true;
		v = f[v];
	}
	vector<int> circ(1, v);
	for (int w = f[v]; w != v; w = f[w]) {
		circ.push_back(w);
	}

	PII best = make_pair(0, 0);
	vector<PII> how;

	for (int i = 0; i < 2; ++i) {
		int w = f[v];
		c[w].erase(find(c[w].begin(), c[w].end(), v));
		gao(v);
		if (best < dp[v][1]) {
			best = dp[v][1];
			how.clear();
			dump(v, true, how);
		}
		c[w].push_back(v);
		v = w;
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
		if (!mark[i]) {
			solve(i);
		}
	}
	printf("%d %d\n", ans.first, ans.second);
	for (vector<PII>::const_iterator it = todo.begin(); it != todo.end(); ++it) {
		printf("%d %d\n", it->first, it->second);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//432505 	May 5, 2011 6:53:39 AM 	watashi 	81E - Pairs 	GNU C++ 	Accepted 	190 ms 	14600 KB 
