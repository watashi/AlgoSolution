#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

int d, dd;
vector<PII> v;
map<pair<int, PII>, bool> mp;

bool gao(int x, int y, int z) {
	if (x * x + y * y > dd) {
		return true;
	} else if (mp.count(make_pair(z, make_pair(x, y))) > 0) {
		return mp[make_pair(z, make_pair(x, y))];
	} else {
		bool& ret = mp[make_pair(z, make_pair(x, y))];
		z = ((z & 1) << 1) ^ ((z & 2) >> 1);
		if ((z & 1) == 0 && !gao(y, x, z ^ 1)) {
			ret = true;
		}
		for (vector<PII>::const_iterator it = v.begin(); !ret && it != v.end(); ++it) {
			ret |= !gao(x + it->first, y + it->second, z);
		}
		return ret;
	}
}

int main() {
	int x, y, d, n;

	scanf("%d%d%d%d", &x, &y, &n, &d);
	dd = d * d;
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &v[i].first, &v[i].second);
	}
	puts(gao(x, y, 0) ? "Anton" : "Dasha");

	return 0;
}

