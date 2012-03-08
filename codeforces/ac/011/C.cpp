#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

char s[1024][1024];

int main() {
	int re, ans, n, m, c, x, y, xx, yy;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%s", s[i]);
		}
		ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (s[i][j] != '1') {
					continue;
				}
				queue<pair<int, int> > q;
				vector<int> v[4];
				s[i][j] = '0';
				q.push(make_pair(i, j));
				while (!q.empty()) {
					x = q.front().first;
					y = q.front().second;
					q.pop();
					v[0].push_back(x);
					v[1].push_back(y);
					v[2].push_back(x + y);
					v[3].push_back(x - y);
					for (int dx = -1; dx <= 1; ++dx) {
						for (int dy = -1; dy <= 1; ++dy) {
							xx = x + dx;
							yy = y + dy;
							if (0 <= xx && xx < n && 0 <= yy && yy < m && s[xx][yy] == '1') {
								s[xx][yy] = '0';
								q.push(make_pair(xx, yy));
							}
						}
					}
				}
				if (v[0].size() % 4 != 0) {
					continue;
				}
				c = v[0].size() / 4;
				if (*min_element(v[0].begin(), v[0].end()) == i &&
					*min_element(v[1].begin(), v[1].end()) == j &&
					*max_element(v[0].begin(), v[0].end()) == i + c &&
					*max_element(v[1].begin(), v[1].end()) == j + c &&
					count(v[0].begin(), v[0].end(), i) == c + 1 &&
					count(v[1].begin(), v[1].end(), j) == c + 1 &&
					count(v[0].begin(), v[0].end(), i + c) == c + 1 &&
					count(v[1].begin(), v[1].end(), j + c) == c + 1) {
					++ans;
				}
				if (*min_element(v[2].begin(), v[2].end()) == i + j &&
					*min_element(v[3].begin(), v[3].end()) == i - j &&
					*max_element(v[2].begin(), v[2].end()) == i + j + c + c &&
					*max_element(v[3].begin(), v[3].end()) == i - j + c + c &&
					count(v[2].begin(), v[2].end(), i + j) == c + 1 &&
					count(v[3].begin(), v[3].end(), i - j) == c + 1 &&
					count(v[2].begin(), v[2].end(), i + j + c + c) == c + 1 &&
					count(v[3].begin(), v[3].end(), i - j + c + c) == c + 1) {
					++ans;
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//275608 	Feb 5, 2011 4:18:00 PM 	watashi 	11C - How Many Squares? 	GNU C++ 	Accepted 	110 ms 	4100 KB 
