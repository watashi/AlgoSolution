#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 4096;

map<int, int> mpx;
int x1[MAXN], x2[MAXN];
vector<int> begin[MAXN], end[MAXN];
short id[MAXN][MAXN], dp[MAXN][MAXN], pre[MAXN][MAXN];

int gao(int l, int r) {
	short& ret = dp[l][r];
	short& pre = ::pre[l][r];
	if (ret != -1) {
	} else if (l >= r) {
		ret = 0;
	} else {
		ret = 0;
		if (ret < gao(l + 1, r)) {
			ret = gao(l + 1, r);
			pre = l + 1;
		}
		if (ret < gao(l, r - 1)) {
			ret = gao(l, r - 1);
			pre = r - 1;
		}
		for (vector<int>::const_iterator i = begin[l].begin(); i != begin[l].end(); ++i) {
			if (x2[*i] < r && ret < gao(l, x2[*i]) + gao(x2[*i], r)) {
				ret = gao(l, x2[*i]) + gao(x2[*i], r);
				pre = x2[*i];
			}
		}
		for (vector<int>::const_iterator i = end[r].end(); i != end[r].end(); ++i) {
			if (x1[*i] > l && ret < gao(l, x1[*i]) + gao(x1[*i], r)) {
				ret = gao(l, x1[*i]) + gao(x1[*i], r);
				pre = x1[*i];
			}
		}
		ret += id[l][r] == -1 ? 0 : 1;
	//	printf("[%d, %d] = %d (%d)\n", l, r, ret, pre);
	}
	return ret;
}

void print(int l, int r) {
	if (l < r && dp[l][r] > 0) {
		if (id[l][r] != -1) {
			printf("%d ", id[l][r] + 1);
		}
	//	printf("[%d, %d] => %d\n", l, r, pre[l][r]);
		print(l, pre[l][r]);
		print(pre[l][r], r);
	}
}

int main() {
	int n, c, r, m;

	scanf("%d", &n);
	mpx[1];
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &c, &r);
		mpx[x1[i] = c - r];
		mpx[x2[i] = c + r];
	}
	m = 0;
	for (map<int, int>::iterator it = mpx.begin(); it != mpx.end(); ++it) {
		it->second = m++;
	}
	
	for (int i = 0; i <= m; ++i) {
		for (int j = i; j <= m; ++j) {
			id[i][j] = -1;
			dp[i][j] = -1;
			pre[i][j] = -1;
		}
	}
	for (int i = 0; i < n; ++i) {
		x1[i] = mpx[x1[i]];
		x2[i] = mpx[x2[i]];
		begin[x1[i]].push_back(i);
		end[x2[i]].push_back(i);
		id[x1[i]][x2[i]] = i;
	}

	printf("%d\n", gao(0, m));	
	print(0, m);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//396359 	Apr 19, 2011 3:35:46 PM 	watashi 	39C - Moon Craters 	GNU C++ 	Accepted 	360 ms 	100400 KB 
