#include <cctype>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
char buf[MAXN][MAXN];
bool mark[MAXN];

int main() {
	int r, c;
	char tag;

	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; ++i) {
		scanf("%s", buf[i] + 1);
	}
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			if (buf[i][j] == 'b') {
				fill(mark + 'A', mark + 'F', false);
				if (buf[i - 1][j] == 'w' && buf[i + 1][j] == 'w') {
					mark[buf[i - 2][j]] = mark[buf[i + 2][j]] = true;
					for (int k = -1; k <= 1; ++k) {
						mark[buf[i + k][j - 1]] = mark[buf[i + k][j + 1]] = true;
					}
					tag = find(mark + 'A', mark + 'F', false) - mark;
					for (int k = -1; k <= 1; ++k) {
						buf[i + k][j] = tag;
					}
				} else if (buf[i][j - 1] == 'w' && buf[i][j + 1] == 'w') {
					mark[buf[i][j - 2]] = mark[buf[i][j + 2]] = true;
					for (int k = -1; k <= 1; ++k) {
						mark[buf[i - 1][j + k]] = mark[buf[i + 1][j + k]] = true;
					}
					tag = find(mark + 'A', mark + 'F', false) - mark;
					for (int k = -1; k <= 1; ++k) {
						buf[i][j + k] = tag;
					}
				}
			}
		}
	}
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			if (buf[i][j] == 'b' || buf[i][j] == 'w') {
				puts("NO");
				return 0;
			} else {
				buf[i][j] = tolower(buf[i][j]);
			}
		}
	}
	puts("YES");
	for (int i = 1; i <= r; ++i) {
		puts(buf[i] + 1);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//404544 	Apr 21, 2011 3:29:49 PM 	watashi 	44J - Triminoes 	GNU C++ 	Accepted 	80 ms 	2400 KB 
