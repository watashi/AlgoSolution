#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

vector<pair<int, bool> > e[MAXN];
long long s[MAXN], c[MAXN], x[MAXN];

void dfs(int v, int p) {
	s[v] = 1;
	c[v] = 0;
	for (vector<pair<int, bool> >::const_iterator it = e[v].begin(); it != e[v].end(); ++it) {
		if (it->first == p) {
			continue;
		}
		dfs(it->first, v);
		s[v] += s[it->first];
		c[v] += it->second ? s[it->first] : c[it->first];
	}
}

void gao(int v, int p) {
	for (vector<pair<int, bool> >::const_iterator it = e[v].begin(); it != e[v].end(); ++it) {
		if (it->first == p) {
			continue;
		}
		x[it->first] = it->second ? s[0] - s[it->first] : x[v] + c[v] - c[it->first];
		gao(it->first, v);
	}	
}

int main() {
	int n, a, b;
	char buf[80];
	string str;
	long long ans;

	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf("%d%d%s", &a, &b, buf);
		--a;
		--b;
		str = buf;
		str.erase(remove(str.begin(), str.end(), '4'), str.end());
		str.erase(remove(str.begin(), str.end(), '7'), str.end());
		e[a].push_back(make_pair(b, str == ""));
		e[b].push_back(make_pair(a, str == ""));
	}

	dfs(0, -1);
	x[0] = 0;
	gao(0, -1);

	ans = 0;
	for (int i = 0; i < n; ++i) {
	//	printf("%lld %lld %lld\n", s[i], c[i], x[i]);
		x[i] += c[i];
		ans += x[i] * (x[i] - 1);
	}
	cout << ans << endl;

	return 0;
}

