#include <set>
#include <cstdio>
#include <vector>
#include <utility>
#include <functional>

using namespace std;

typedef pair<int, int> PII;

int main() {
	int re, n;
	int x, y, z;
	vector<int> ans;
	multiset<pair<PII, int> > a, o;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		a.clear();
		o.clear();
		for (int i = 1; i < n + n; ++i) {
			scanf("%d%d", &x, &y);
			a.insert(make_pair(make_pair(x, y), i));
			o.insert(make_pair(make_pair(y, x), i));
		}

		ans.clear();
		for (int i = 0; i < n; ++i) {
			if (i > 0) {
				y = o.begin()->first.first;
				x = o.begin()->first.second;
				z = o.begin()->second;
				a.erase(a.find(make_pair(make_pair(x, y), z)));
				o.erase(o.find(make_pair(make_pair(y, x), z)));
			}
			x = a.rbegin()->first.first;
			y = a.rbegin()->first.second;
			z = a.rbegin()->second;
			a.erase(a.find(make_pair(make_pair(x, y), z)));
			o.erase(o.find(make_pair(make_pair(y, x), z)));
			ans.push_back(z);
		}

		puts("YES");
		for (int i = 0; i < (int)ans.size(); ++i) {
			printf("%d ", ans[i]);
		}
		puts("");
	}

	return 0;	
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//301668 	Feb 24, 2011 6:42:55 PM 	watashi 	23C - Oranges and Apples 	GNU C++ 	Accepted 	730 ms 	17800 KB 
