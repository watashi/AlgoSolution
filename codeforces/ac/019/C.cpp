#include <set>
#include <map>
#include <list>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
int a[MAXN];
list<int> v[MAXN];
map<int, int> mp;
set<pair<int, int> > st;

int main() {
	int n, s;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if (mp.count(a[i]) == 0) {
			mp[a[i]] = i;
		}
		v[mp[a[i]]].push_back(i);
	}
	a[n] = -1;

	s = 0;
	for (int i = 0; i < n; ++i) {
		list<int>& w = v[mp[a[i]]];
		w.pop_front();
		for (list<int>::const_iterator j = w.begin(); j != w.end(); ++j) {
			int x = i;
			int y = *j;
			do {
				st.insert(make_pair(x, y));
				++x;
				++y;
			} while (x < *j && a[x] == a[y] && st.count(make_pair(x, y)) == 0);
			if (x == *j) {
				s = *j;
				i = s - 1;
				break;
			}
		}
	}
	
	printf("%d\n", n - s);
	for (int i = s; i < n; ++i) {
		printf("%d ", a[i]);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//444527 	May 10, 2011 9:24:18 PM 	watashi 	19C - Deletion of Repeats 	GNU C++ 	Accepted 	360 ms 	17100 KB 
