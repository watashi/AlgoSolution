#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

int d[1 << 16];

int main() {
	int re, t, m;
	queue<int> q;

	fill(d, d + (1 << 16), -1);
	d[0xff00] = 0;
	q.push(0xff00);	
	while (!q.empty()) {
		m = q.front();
		q.pop();
		if (d[m] >= 3) {
			continue;
		}
		for (int i = 0; i < 16; ++i) {
			for (int j = 0; j < 4; ++j) {
				int k = i ^ (1 << j);
				if (((m >> i) & 1) != ((m >> k) & 1)) {
					t = m ^ (1 << i) ^ (1 << k);
					if (d[t] == -1) {
						d[t] = d[m] + 1;
						q.push(t);
					}
				}
			}
		}
	}

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		m = 0;
		for (int i = 0; i < 16; ++i) {
			scanf("%d", &t);
			if (t == 1) {
				m ^= 1 << i;
			}
		}
		printf("Case #%d: ", ri);
		if (d[m] == -1) {
			puts("more");
		} else {
			printf("%d\n", d[m]);
		}
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//898515 	4743 	Alice's Cube 	Accepted 	C++ 	0.036 	2011-10-05 07:26:16
/*
id => 1174247
pid => 4743
pname => Alice's Cube
status => Accepted
lang => C++
time => 0.032
date => 2012-12-14 17:44:35
*/
