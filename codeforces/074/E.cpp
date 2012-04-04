#include <cctype>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 6;

int a[MAXN][MAXN];

void find(int& x, int& y, int z) {
	for (x = 0; x < MAXN; ++x) {
		for (y = 0; y < MAXN; ++y) {
			if (a[x][y] == z) {
				return;
			}
		}
	}
}

int main() {
	char ch;

	for (int i = 0; i < MAXN; ++i) {
		for (int j = 0; j < MAXN; ++j) {
			scanf(" %c", &ch);
			a[i][j] = isdigit(ch) ? ch - '0' : ch - 'A' + 10;
		}
	}

	return 0;
}
