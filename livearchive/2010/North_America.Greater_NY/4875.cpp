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
		for (int i = 0, j = 0; i < n; i = j) {
			while (a[i] == a[j] && j < i + 130 && j < n) {
				++j;
			}
			if (j - i >= 3) {
				b.push_back(128 + j - i - 3);
				b.push_back(a[i]);
			} else {
				while (j < i + 128 && j < n) {
					if (j + 3 <= n && a[j + 1] == a[j] && a[j + 2] == a[j]) {
						break;
					} else {
						++j;
					}	
				}
				b.push_back(j - i - 1);
				b.insert(b.end(), a.begin() + i, a.begin() + j);
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
//881214 	4875 	Just The Simple Fax 	Accepted 	C++ 	0.016 	2011-09-13 13:38:13
/*
id => 1174161
pid => 4875
pname => Just The Simple Fax
status => Accepted
lang => C++
time => 0.012
date => 2012-12-14 17:31:39
*/
