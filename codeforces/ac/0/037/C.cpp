#include <deque>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

int depth;
string path;
string ans[MAXN];

void gao(deque<pair<int, int> >& v) {
	if (v.empty()) {
		return;
	} else if (v[0].first == depth) {
		ans[v[0].second] = path;
		v.pop_front();
		return;
	} else {
		++depth;
		path += '0';
		gao(v);
		*path.rbegin() = '1';
		gao(v);
		path.erase(path.end() - 1);
		--depth;
	}
}

int main() {
	int n;
	deque<pair<int, int> > v;

	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i].first);
		v[i].second = i;
	}
	sort(v.begin(), v.end());

	depth = 0;
	path = "";
	gao(v);
	if (v.empty()) {
		puts("YES");
		for (int i = 0; i < n; ++i) {
			puts(ans[i].c_str());
		}
	} else {
		puts("NO");
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//235961 	Jan 2, 2011 3:56:27 PM 	watashi 	C - Old Berland Language 	GNU C++ 	Accepted 	30 ms 	2304 KB 
