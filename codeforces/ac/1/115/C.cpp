#include <cstdio>
#include <algorithm>

using namespace std;

const int MOD = 1000003;

char buf[1 << 20];

bool test(int i, int j) {
	return ((i >> j) & 1) != 0;
}

int main() {
	int r, c, a, b, ans;
	vector<string> s;

	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; ++i) {
		scanf("%s", buf);
		for (int j = 0; j < c; ++j) {
			if (buf[j] == '3') {
				buf[j] = '4';
			} else if (buf[j] == '4') {
				buf[j] = '3';
			}
		}
		s.push_back(buf);
	}
	//	if (r % 2 != 0 || c % 2 != 0) {
	//		ans = 0;
	//	} else {
	ans = 1;
	for (int i = 0; i < r; ++i) {
		a = b = 1;
		for (int j = 0; j < c; ++j) {
			if (s[i][j] == '.') {
				continue;
			}
			if ((j % 2 == 0) ^ test(s[i][j] - '1', 1)) {
				a = 0;
			}
			if ((j % 2 != 0) ^ test(s[i][j] - '1', 1)) {
				b = 0;
			}
		}
		ans = ans * (a + b) % MOD;
	}
	for (int j = 0; j < c; ++j) {
		a = b = 1;
		for (int i = 0; i < r; ++i) {
			if (s[i][j] == '.') {
				continue;
			}
			if ((i % 2 == 0) ^ test(s[i][j] - '1', 0)) {
				a = 0;
			}
			if ((i % 2 != 0) ^ test(s[i][j] - '1', 0)) {
				b = 0;
			}
		}
		ans = ans * (a + b) % MOD;
	}
	//	}
	printf("%d\n", ans);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//702471 	Sep 15, 2011 10:18:26 PM 	watashi 	C - Plumber 	GNU C++0x 	Accepted 	640 ms 	17800 KB 
