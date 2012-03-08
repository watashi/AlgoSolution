#include <list>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 10086;

bool mark[MAXN];
vector<pair<int, int> > e[MAXN];
vector<pair<vector<int>, vector<int> > > v;

void dfs(int i) {
	mark[i] = true;
	v.back().first.push_back(i);
	if (e[i].size() % 2 != 0) {
		v.back().second.push_back(i);
	}
	for (vector<pair<int, int> >::const_iterator j = e[i].begin(); j != e[i].end(); ++j) {
		if (!mark[j->first]) {
			dfs(j->first);
		}
	}
}

void gao(int i, list<pair<int, int> >& r) {
	while (true) {
		while (!e[i].empty() && mark[e[i].back().second]) {
			e[i].pop_back();
		}
		if (e[i].empty()) {
			break;
		}
		r.push_back(make_pair(i, e[i].back().second));
		mark[e[i].back().second] = true;
		i = e[i].back().first;
	}
	for (list<pair<int, int> >::iterator j = r.begin(); j != r.end(); ++j) {
		i = j->first;
		while (!e[i].empty() && mark[e[i].back().second]) {
			e[i].pop_back();
		}
		if (!e[i].empty()) {
			list<pair<int, int> > s;
			gao(i, s);
			r.splice(j, s);
		}
	}
}

int main() {
	int n, a, b;
	list<int> s;
	list<list<int> > t;
	list<pair<int, int> > r;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a, &b);
		e[a].push_back(make_pair(b, i));
		e[b].push_back(make_pair(a, i));
	}

	b = 0;
	fill(mark, mark + MAXN, false);
	for (int i = 0; i < MAXN; ++i) {
		if (!mark[i] && !e[i].empty()) {
			v.resize(v.size() + 1);
			dfs(i);
			b += max(1, (int)v.back().second.size() / 2);
		}
	}

	a = n;
	fill(mark, mark + MAXN, false);
	if (n == 1 || b > 2) {
		puts("-1");
	} else {
		t.clear();
		for (int i = 0; i < (int)v.size(); ++i) {
			for (int j = 0; j < (int)v[i].second.size(); j += 2) {
				++a;
				e[v[i].second[j]].push_back(make_pair(v[i].second[j + 1], a));
				e[v[i].second[j + 1]].push_back(make_pair(v[i].second[j], a));
			}
			r.clear();
			gao(v[i].first.front(), r);
			s.clear();
			for (list<pair<int, int> >::const_iterator it = r.begin(); it != r.end(); ++it) {
				s.push_back(it->second > n ? -1 : it->second);
			}
			rotate(s.begin(), find(s.begin(), s.end(), -1), s.end());
			while (!s.empty()) {
				if (s.front() == -1) {
					s.pop_front();
				}
				t.push_back(list<int>());
				t.back().splice(t.back().begin(), s, s.begin(), find(s.begin(), s.end(), -1));
			}
		}
		if (t.size() == 1) {
			t.push_back(list<int>());
			t.back().splice(t.back().begin(), t.front(), t.front().begin());
		}
		for (list<list<int> >::const_iterator it = t.begin(); it != t.end(); ++it) {
			printf("%d\n", (int)it->size());
			for (list<int>::const_iterator jt = it->begin(); jt != it->end(); ++jt) {
				printf("%d ", *jt);
			}
			puts("");
		}
	}

	return 0;
}

// orz 1y
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//241049 	Jan 7, 2011 2:42:05 PM 	watashi 	36E - Two paths 	GNU C++ 	Accepted 	50 ms 	2332 KB 

/*
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
240763 	Jan 7, 2011 9:28:27 AM 	chinazh 	E - Two paths 	GNU C++ 	Accepted 	60 ms 	2332 KB
240754 	Jan 7, 2011 9:24:59 AM 	sazzad 	E - Two paths 	GNU C++ 	Accepted 	60 ms 	2332 KB
240752 	Jan 7, 2011 9:24:20 AM 	jlepack 	E - Two paths 	GNU C++ 	Accepted 	60 ms 	2332 KB
240751 	Jan 7, 2011 9:23:58 AM 	sazzad 	E - Two paths 	GNU C++ 	Accepted 	60 ms 	2332 KB
240743 	Jan 7, 2011 9:22:33 AM 	tester 	E - Two paths 	GNU C++ 	Accepted 	50 ms 	2332 KB
240736 	Jan 7, 2011 9:19:11 AM 	tl268 	E - Two paths 	GNU C++ 	Accepted 	50 ms 	2332 KB
240735 	Jan 7, 2011 9:18:36 AM 	hlahuhkln 	E - Two paths 	GNU C++ 	Idleness limit exceeded on test 1 	0 ms 	0 KB
240733 	Jan 7, 2011 9:18:15 AM 	sazzad 	E - Two paths 	GNU C++ 	Idleness limit exceeded on test 1 	0 ms 	0 KB 
*/
