#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int INF = 1 << 20;

inline int mod(int a, int b) {
	return (a % b + b) % b;
}

int main() {
	int re, d[11], n;
	vector<pair<int, int> > dp[11][11];

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		for (int i = 1; i < 10; ++i) {
			scanf("%d", &d[i]);
		}
		
		for (int i = 0; i < 11; ++i) {
			for (int j = 0; j < 11; ++j) {
				dp[i][j].clear();
			}
		}
		
		dp[1][0].push_back(make_pair(0, 0));
		for (int i = 1; i < 10; ++i) {
			for (int j = 0; j < 11; ++j) {
				vector<pair<int, int> >& from = dp[i][j];
				if (from.empty()) {
					continue;
				}
				sort(from.begin(), from.end());
				n = 1;
				for (int t = 1; t < (int)from.size(); ++t) {
					if (from[t].second < from[n - 1].second) {
						from[n++] = from[t];
					}
				}
				from.resize(n);

				for (int k = 0; k <= d[i]; ++k) {
					vector<pair<int, int> >& to = dp[i + 1][mod(j + (d[i] - 2 * k) * i, 11)];
					for (int t = 0; t < (int)from.size(); ++t) {
						to.push_back(make_pair(from[t].first + d[i] - k, from[t].second + k));
					}
				}
			}
		}

		n = INF;
		for (int i = 0; i < (int)dp[10][0].size(); ++i) {
			n = min(n, max(dp[10][0][i].first * 2, dp[10][0][i].second * 2 - 1));
		}
		printf("%d\n", n < INF ? n : -1);
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//716555  	2011-01-07 10:14:21 	Accepted	0.066	Minimum	26909	C++	5111 - Soccer Teams

/*
id => 1174198
pid => 5111
pname => Soccer Teams
status => Accepted
lang => C++
time => 0.022
date => 2012-12-14 17:37:10
*/
