#include <map>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 50;

map<long long, int> mp;
vector<int> e[MAXN];
long long em[MAXN];

bool gao(int n, long long m) {
	if (n == 0) {
		return m == 0;
	}
	int& l = mp[m];
	if (l >= n) {
		return false;
	}
	l = n;
	int i = __builtin_ctzll(m);
	for (vector<int>::const_iterator j = e[i].begin(); j != e[i].end(); ++j) {
		if (gao(n - 1, m & em[*j])) {
			return true;
		}
	}
	return false;
}

int main() {
	int r, c;

	for (r = 1; r <= 40; ++r) {
		for (c = 1; c <= 40; ++c) {
			if (r * c > 40) continue;
			printf("ans[%d][%d] = ", r, c);
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			int x = i * c + j;
			em[x] = ~0;
			for (int ii = i - 1; ii <= i + 1; ++ii) {
				for (int jj = j - 1; jj <= j + 1; ++jj) {
					if (0 <= ii && ii < r && 0 <= jj && jj < c && abs(i - ii) + abs(j - jj) <= 1) {
						int y = ii * c + jj;
						e[x].push_back(y);
						em[x] ^= 1LL << y;
					}
				}
			}
		}
	}
	for (int i = 1; ; ++i) {
		mp.clear();
		if (gao(i, (1LL << r * c) - 1)) {
			printf("%d;\n", r * c - i);
			fflush(stdout);
			break;
		}
	}
		}}
	return 0;
}

