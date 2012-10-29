#include <cctype>
#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

inline int sqr(int x) {
	return x * x;
}

int main() {
	int n, m, d, ans;
	char s[80][80];
	bool x[26], y[26];
	vector<pair<int, int> > shift;
	static char buf[1 << 20];

	scanf("%d%d%d", &n, &m, &d);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s[i]);
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == 'S') {
				shift.push_back(make_pair(i, j));
			}
		}
	}

	fill(x, x + 26, false);
	fill(y, y + 26, false);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == 'S') {
				continue;
			}
			x[s[i][j] - 'a'] = true;
			for (auto k: shift) {
				if (sqr(i - k.first) + sqr(j - k.second) <= d * d) {
					y[s[i][j] - 'a'] = true;
					break;
				}
			}
		}
	}

	scanf("%*d%s", buf);
	ans = 0;
	for (int i = 0; buf[i] != '\0'; ++i) {
		if (!x[tolower(buf[i]) - 'a']) {
			ans = -1;
			break;
		} else if (isupper(buf[i])) {
			if (shift.empty()) {
				ans = -1;
				break;
			} else if (!y[tolower(buf[i]) - 'a']) {
				++ans;
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//509293 	Jun 24, 2011 4:46:35 AM 	watashi 	88B - Keyboard 	GNU C++0x 	Accepted 	50 ms 	2400 KB 

