#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
	int a[4], p;
	vector<int> ans;

	for (int i = 0; i < 4; ++i) {
		scanf("%d", &a[i]);
	}
	while (ans.size() <= 1000) {
		if (*max_element(a, a + 4) == 1) {
			break;
		}
		p = rand() % 4;
		if (a[p] % 2 != 0) {
			ans.push_back(p);
			++a[p];
			++a[(p + 1) & 3];
		}
		if (a[(p + 1) & 3] % 2 != 0) {
			ans.push_back((p + 1) & 3);
			++a[(p + 1) & 3];
			++a[(p + 2) & 3];
		}
		ans.push_back(-1 - p);
		a[p] /= 2;
		a[(p + 1) & 3] /= 2;
//		printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);
	}
	if (ans.size() > 1000) {
		puts("-1");
	} else {
		for (vector<int>::const_iterator it = ans.begin(); it != ans.end(); ++it) {
			printf("%c%d\n", *it >= 0 ? '+' : '/', *it >= 0 ? *it + 1 : -*it);
		}
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//218599 	Dec 12, 2010 6:55:12 PM 	watashi 	C - Safe cracking 	GNU C++ 	Accepted 	30 ms 	1312 KB 
