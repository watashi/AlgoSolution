#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int re, rid, n;
	vector<int> a, b;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d", &rid, &n);
		a.resize(n);
		for (int i = 0; i < n; ++i) {
			scanf("%2x", &a[i]);
		}
		b.clear();
		for (int i = 0; i < n; ++i) {
			if (a[i] & (1 << 7)) {
				a[i] ^= 1 << 7;
				a[i] += 3;
				for (int j = 0; j < a[i]; ++j) {
					b.push_back(a[i + 1]);
				}
				++i;
			} else {
				++a[i];
				for (int j = 0; j < a[i]; ++j) {
					b.push_back(a[i + 1 + j]);
				}
				i += a[i];
			}
		}
		printf("%d %d", rid, (int)b.size());
		for (int i = 0; i < (int)b.size(); ++i) {
			if (i % 40 == 0) {
				puts("");
			}
			printf("%02X", b[i]);
		}
		puts("");
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//881215 	4876 	Show Me The Fax 	Accepted 	C++ 	0.028 	2011-09-13 13:39:54
/*
id => 1174162
pid => 4876
pname => Show Me The Fax
status => Accepted
lang => C++
time => 0.012
date => 2012-12-14 17:32:01
*/
