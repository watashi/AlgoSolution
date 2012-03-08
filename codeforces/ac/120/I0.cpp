#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

const int led[10] = {
	0x7e,
	0x60,
	0x6d,
	0x79,
	0x33,
	0x5b,
	0x5f,
	0x70,
	0x7f,
	0x7b,
};
int val[10][10];
char buf[200200];
int dig[200200];
pair<int, int> how[10];

int main() {
#ifndef __WATASHI__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, rem;

	for (int i = 0; i < 10; ++i) {
		how[i] = {-1, -1};
	}
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			val[i][j] = __builtin_popcount(led[i] & led[j]);
			if (how[val[i][j]].first == -1) {
				how[val[i][j]] = {i, j};
			}
		}
	}
	scanf("%s", buf);
	n = strlen(buf) / 2;
	for (int i = 0; i < n + n; ++i) {
		dig[i] = buf[i] - '0';
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = dig[n + i] + 1; j < 10; ++j) {
			if (val[dig[i]][j] > val[dig[i]][dig[n + i]]) {
				dig[n + i] = j;
				rem = val[dig[i]][j] - val[dig[i]][dig[n + i]];
				for (int r = i + 1; r < n; ++r) {
					for (int p = 0; p < 10; ++p) {
						if (val[dig[r]][p] + rem > val[dig[r]][dig[n + r]]) {
							dig[n + r] = p;
							rem += val[dig[r]][p] - val[dig[r]][dig[n + r]];
						}
					}
				}
				goto DONE;
			}
		}
	}

	puts("-1");
	return 0;
DONE:
	for (int i = 0; i < n + n; ++i) {
		buf[i] = '0' + dig[i];
	}
	puts(buf);
	return 0;
}
