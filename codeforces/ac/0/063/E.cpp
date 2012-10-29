#include <cstdio>
#include <algorithm>

using namespace std;

char str[10][10];
int hash[1 << 20];

const int lj[] = {-1, 1, 1, 1, 2, 3};
const int rj[] = {-1, 3, 4, 5, 5, 5};
const int dx[] = {0, 1, 1};
const int dy[] = {1, 0, 1};

bool gao() {
	int index = 0;
	for (int i = 1; i <= 5; ++i) {
		for (int j = lj[i]; j <= rj[i]; ++j) {
			index <<= 1;
			if (str[i][j] == 'O') {
				index ^= 1;
			}
		}
	}
	int& ret = hash[index];
	if (ret == 0) {
		ret = -1;
		for (int i = 1; ret < 0 && i <= 5; ++i) {
			for (int j = lj[i]; ret < 0 && j <= rj[i]; ++j) {
				if (str[i][j] != 'O') {
					continue;
				}
				for (int k = 0; ret < 0 && k < 3; ++k) {
					int x = i;
					int y = j;
					while (str[x][y] == 'O') {
						str[x][y] = 'X';
						x += dx[k];
						y += dy[k];
						if (!gao()) {
							ret = 1;
							break;
						}
					}
					while (x != i || y != j) {
						x -= dx[k];
						y -= dy[k];
						str[x][y] = 'O';
					}
				}
			}
		}
	}
	return ret > 0;
}

int main() {
	for (int i = 1; i <= 5; ++i) {
		for (int j = lj[i]; j <= rj[i]; ++j) {
			scanf(" %c", &str[i][j]);
		}
	}
	puts(gao() ? "Karlsson" : "Lillebror");
	return 0;
}

