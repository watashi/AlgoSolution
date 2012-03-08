#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

vector<pair<int, long long> > e[MAXN];

long long gao(int v, int p, long long d) {
	long long ret = d;
	for (vector<pair<int, long long> >::const_iterator it = e[v].begin(); it != e[v].end(); ++it) {
		if (it->first != p) {
			ret = max(ret, gao(it->first, v, d + it->second));
		}
	}
	return ret;
}

int main() {
	int n, a, b;
	long long c, s;

	cin >> n;
	s = 0;
	for (int i = 1; i < n; ++i) {
		cin >> a >> b >> c;
		--a;
		--b;
		e[a].push_back(make_pair(b, c));
		e[b].push_back(make_pair(a, c));
		s += c;
	}
	s = s + s - gao(0, -1, 0LL);
	cout << s << endl;

	return 0;
}

