#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

const int led[10] = {
	0x7e,
	0x30,
	0x6d,
	0x79,
	0x33,
	0x5b,
	0x5f,
	0x70,
	0x7f,
	0x7b,
};
int v[10][10];
char s[200200];
int d[200200];

void smart(int n, int s, int& rem) {
	for (int i = s + 1; i < n; ++i) {
		if (rem > 1) {
			--rem;
			d[i] = 0;
			d[n + i] = 0;
		}
	}
}

void stupid(int n, int s, int& rem) {
	for (int i = s + 1; i < n; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (rem - v[d[i]][d[n + i]] + v[d[i]][j] > 0) {
				rem -= v[d[i]][d[n + i]] - v[d[i]][j];
				d[n + i] = j;
				break;
			}
		}
	}
}

int main() {
#ifndef __WATASHI__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, rem = 0;

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			v[i][j] = __builtin_popcount(led[i] & led[j]);
		}
	}
	scanf("%s", s);
	n = strlen(s) / 2;
	for (int i = 0; i < n + n; ++i) {
		d[i] = s[i] - '0';
	}
	
	for (int i = n - 1; i >= 0; --i) {
		for (int j = d[n + i] + 1; j < 10; ++j) {
			if (rem + v[d[i]][j] - v[d[i]][d[n + i]] > 0) {
				rem += v[d[i]][j] - v[d[i]][d[n + i]];
				d[n + i] = j;
				stupid(n, i, rem);
				goto DONE;
			}
		}
		rem += v[d[i]][8] - v[d[i]][d[n + i]];
		d[n + i] = 8;
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = d[i] + 1; j < 10; ++j) {
			if (rem + v[j][8] - v[d[i]][d[n + i]] > 0) {
				rem += v[j][8] - v[d[i]][d[n + i]];
				d[i] = j;
				d[n + i] = 8;
				smart(n, i, rem);
				stupid(n, -1, rem);
				goto DONE;
			}
		}
		rem += v[8][8] - v[d[i]][d[n + i]];
		d[i] = d[n + i] = 8;
	}

	puts("-1");
	return 0;
DONE:
	for (int i = 0; i < n + n; ++i) {
		s[i] = '0' + d[i];
	}
	puts(s);
	return 0;
}
