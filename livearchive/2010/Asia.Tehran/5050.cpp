#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int DAY = 24 * 60;

int readtime() {
	int hh, mm;
	scanf("%d:%d", &hh, &mm);
	return hh * 60 + mm;
}

int main() {
	int n, m, p, q, t;
	vector<int> a, b, c, d;

	while (scanf("%d%d", &n, &m) == 2 && n > 0 && m > 0) {
		a.clear();
		for (int i = 0; i < n; ++i) {
			a.push_back(readtime());
		}
		b.clear();
		for (int i = 0; i < m; ++i) {
			b.push_back(readtime());
		}
		c.clear();
		for (int i = 1; i < DAY; ++i) {
			c.push_back(i);
		}

		scanf("%d", &p);
		for (int k = 0; k < p; ++k) {
			q = readtime();
			d.clear();
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
#ifdef WRONG_ANSWER
					t = 0;
					t += q - a[i] + (q < a[i] ? DAY : 0);
					t += q - b[j] + (q < b[j] ? DAY : 0);
#else
          t = (q - a[i]) + (q - b[j]);
          if (q < a[i] || q < b[j]) {
            t += 2 * DAY;
          }
#endif
					if (0 < t && t < DAY) {
						d.push_back(t);
					}
				}
			}
			sort(d.begin(), d.end());
			c.erase(set_intersection(c.begin(), c.end(), d.begin(), d.end(), c.begin()), c.end());
		}

		if (c.empty()) {
			puts("il bugiardo passeggeri!");
		} else if (c.size() == 1) {
			printf("%02d:%02d\n", c[0] / 60, c[0] % 60);
		} else {
			printf("%d scelte\n", (int)c.size());
		}
	}

	return 0;
}

/*
id => 1243115
pid => 5050
pname => Bus Shuttle
status => Accepted
lang => C++
time => 0.039
data => 2013-06-03 14:17:37
*/
