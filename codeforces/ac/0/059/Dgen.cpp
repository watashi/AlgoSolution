#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

set<pair<int, int> > s;
map<int, int> ss;
int p[MAXN * 3];

int main() {
	int n = 36000, m = n * 3, t[3];

	for (int i = 1; i <= m; ++i) {
		p[i] = i;
	}
	random_shuffle(p + 1, p + 1 + m);
	printf("%d\n", n);
	for (int i = 1; i <= m; ++i) {
		printf("%d%c", p[i], i == m ? '\n' : ' ');
		s.insert(make_pair(i, p[i]));
		ss[p[i]] = i;
	}

	for (int i = 1; i <= n; ++i) {
		t[0] = s.begin()->second;
		s.erase(make_pair(ss[t[0]], t[0]));
		ss.erase(t[0]);
		p[t[0]] = -1;
		for (int j = 1; j < 3; ++j) {
			for (int k = 0; ; ++k) {
				t[j] = k == 10 ? s.begin()->second : rand() % m + 1;
				if (ss.count(t[j]) > 0) {
					break;
				}
			}
			s.erase(make_pair(ss[t[j]], t[j]));
			ss.erase(t[j]);
			p[t[j]] = -1;
		}
		random_shuffle(t, t + 3);
		printf("%d %d %d\n", t[0], t[1], t[2]);
	}
	fflush(stdout);

	return 0;
}

