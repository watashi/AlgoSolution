#include <cstdio>
#include <utility>

using namespace std;

pair<int, int> mark[1 << 20];

int main() {
	int m, n, p, dd, mm, yy, a[1024], s;

	while (scanf("%d", &n) != EOF && n > 0) {
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		scanf("%d", &p);
		scanf("%d / %d / %d", &dd, &mm, &yy);

		m = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= a[i]; ++j) {
				if (i == mm && j == dd) {
					s = m;
				}
				mark[m++] = make_pair(i, j);
			}
		}
		pair<int, int> x = make_pair(-1, -1);
		while (mark[s].first != -1) {
		//	printf("%d/%d/%d\n", mark[s].second, mark[s].first, yy);
			if (mark[s].first == x.first) {
				printf("The next Blue Moon Festival will be held on %d/%d/%d.\n", mark[s].second, mark[s].first, yy);
				break;
			} else {
				if (x == make_pair(-1, -1)) {
					x = mark[s];
				} else {
					x = mark[s];
					mark[s].first = -1;
				}
				s += p;
				if (s >= m) {
					yy += s / m;
					s %= m;
					x.first = -1;
				}
			}
		}
		if (mark[s].first == -1) {
			puts("There can never be a Blue Moon Festival.");
		}
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//715032  	2011-01-04 07:50:26 	Accepted	0.139	8592	26909	C++	4459 - Blue Moon

/*
id => 1174093
pid => 4459
pname => Blue Moon
status => Accepted
lang => C++
time => 0.056
date => 2012-12-14 17:21:22
*/
