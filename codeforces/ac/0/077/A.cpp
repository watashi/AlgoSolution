#include <map>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 7;
const int INF = 1000000007;

bool like[MAXN][MAXN];
int ship[1 << MAXN];
map<string, int> mp;

int main() {
	int n, a, b, c, u, v, w;
	char sa[80], sb[80];
	pair<int, int> tmp, ans;

	mp["Anka"] = 0;
	mp["Chapay"] = 1;
	mp["Cleo"] = 2;
	mp["Troll"] = 3;
	mp["Dracul"] = 4;
	mp["Snowy"] = 5;
	mp["Hexadecimal"] = 6;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s likes %s", sa, sb);
		like[mp[sa]][mp[sb]] = true;
	}
	scanf("%d%d%d", &a, &b, &c);

	for (int k = 0; k < (1 << MAXN); ++k) {
		ship[k] = 0;
		for (int i = 0; i < MAXN; ++i) {
			for (int j = 0; j < MAXN; ++j) {
				if ((k & (1 << i)) != 0 && (k & (1 << j)) != 0 && like[i][j]) {
					++ship[k];
				}
			}
		}
	}

	ans = make_pair(INF, 0);
	for (int i = 1; i < (1 << MAXN); ++i) {
		u = a / __builtin_popcount(i);
		for (int j = 1; j < (1 << MAXN); ++j) {
			if (i & j) {
				continue;
			}
			v = b / __builtin_popcount(j);
			for (int k = 1; k < (1 << MAXN); ++k) {
				if ((i & k) != 0 || (j & k) != 0 || (i | j | k) != (1 << MAXN) - 1) {
					continue;
				}
				w = c / __builtin_popcount(k);
				ans = min(ans, make_pair(max(u, max(v, w)) - min(u, min(v, w)),
						-(ship[i] + ship[j] + ship[k])));
			}
		}
	}
	printf("%d %d\n", ans.first, -ans.second);

	return 0;
}

