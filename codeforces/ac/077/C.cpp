#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 100100;

int v[MAXN];
vector<int> e[MAXN];

long long gao(int s, int t) {
	long long u = 0;
	vector<long long> w;
	for (vector<int>::iterator i = e[s].begin(); i != e[s].end(); ++i) {
		if (*i == t) {
			continue;
		}
		--v[*i];
		w.push_back(gao(*i, s));
		u += v[*i];
	}

	long long ret = 0;
//	printf("@%d [%d, %d]\n", s + 1, v[s], u);
	if (v[s] >= (int)w.size()) {
//		puts("!");
		ret += accumulate(w.begin(), w.end(), 0LL);
		ret += w.size();
		v[s] -= w.size();
		ret += min(u, (long long)v[s]);
		v[s] -= min(u, (long long)v[s]);
	} else {
		sort(w.begin(), w.end(), greater<long long>());
		for (int i = 0; i < v[s]; ++i) {
			ret += w[i];
		}
		ret += v[s];
		v[s] = 0;
	}
//	printf("@%d = %lld\n", s + 1, ret);
	
	return ret;
}

int main() {
	int n, a, b, s;
	long long ans;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}
	for (int i = 1; i < n; ++i) {
		scanf("%d%d", &a, &b);
		--a;
		--b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	scanf("%d", &s);
	ans = 2 * gao(s - 1, -1);
//	printf("%lld\n", ans);
	printf("%I64d\n", ans);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//402171 	Apr 19, 2011 11:05:20 PM 	watashi 	77C - Beavermuncher-0xFF 	GNU C++ 	Accepted 	220 ms 	22600 KB
