#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int s[20];
bool r[20];
vector<pair<int, int> > ans;

void gao(int a, int b, int n, bool last) {
	--n;
	if (n < 0) {
		return;
	}
	int c = 6 - a - b;
	if (last && s[n] > 1 && !r[n]) {
		if (n == 0) {
			gao(a, b, n, false);
			for (int i = 1; i < s[n]; ++i) {
				ans.push_back(make_pair(a, c));
			}
			gao(b, c, n, false);
			ans.push_back(make_pair(a, b));
			gao(c, a, n, false);
			for (int i = 1; i < s[n]; ++i) {
				ans.push_back(make_pair(c, b));
			}
			gao(a, b, n, last);
		} else {
			gao(a, b, n, false);
			for (int i = 0; i < s[n]; ++i) {
				ans.push_back(make_pair(a, c));
			}
			r[n] = !r[n];
			gao(b, a, n, false);
			for (int i = 0; i < s[n]; ++i) {
				ans.push_back(make_pair(c, b));
			}
			r[n] = !r[n];
			gao(a, b, n, last);
		}
	} else {
		gao(a, c, n, false);
		for (int i = 0; i < s[n]; ++i) {
			ans.push_back(make_pair(a, b));
		}
		r[n] = !r[n];
		gao(c, b, n, last);
	}
}

int main() {
	int n, t;
	map<int, int> mp;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t);
		++mp[t];
	}
	n = 0;
	for (map<int, int>::const_iterator it = mp.begin(); it != mp.end(); ++it) {
		s[n] = it->second;
		r[n] = false;
		++n;
	}
	gao(1, 3, n, true);
	printf("%d\n", (int)ans.size());
	for (vector<pair<int, int> >::const_iterator it = ans.begin(); it != ans.end(); ++it) {
		printf("%d %d\n", it->first, it->second);
	}

	return 0;
}

