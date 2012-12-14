#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

int ceil(int a, int b) {
	return a >= 0 ? (a + b - 1) / b : a / b;
}

void gao(const PII& a, const PII& b, map<int, int>& ret) {
//	printf("gao (%d, %d) - (%d, %d)\n", a.first, a.second, b.first, b.second);
	for (int y = a.first + 1; y < b.first; ++y) {
		int x = a.second + ceil((b.second - a.second) * (y - a.first), b.first - a.first) - 1;
		ret[y] = x;
//		printf("[%d] = %d\n", y, x);
	}
}

void gao(vector<PII>::const_iterator begin, vector<PII>::const_iterator end, map<int, int>& ret) {
	ret.clear();
	
	for (vector<PII>::const_iterator it = begin + 1; it != end; ++it) {
		gao(*(it - 1), *it, ret);
		if (it - 1 != begin) {
			ret[(it-1)->first] = (it-1)->second - 1;
		}
	}
}

int main() {
	int re, m, n, p, q;
	vector<PII> v;
	vector<pair<int, PII> > ans;
	map<int, int> left, right;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d", &m, &n);
		v.resize(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &v[i].second, &v[i].first);
		}
		reverse(v.begin() + 1, v.end());

		p = min_element(v.begin(), v.end()) - v.begin();
		q = (p + 1 < n && v[p + 1].first == v[p].first ? p + 1 : p);
		if (v.back().first != v.front().first) {
			v.push_back(v.front());
			++n;
		}		
		gao(v.begin() + q, v.begin() + n, right);
		
//		printf("p = %d; q = %d\n", p, q);
		reverse(v.begin(), v.begin() + p + 1);
		for (int i = 0; i <= p; ++i) {
			v[i].second = -v[i].second;
		}
		gao(v.begin(), v.begin() + p + 1, left);

		
		ans.clear();
		for (map<int, int>::const_iterator i = left.begin(); i != left.end(); ++i) {
//		for (map<int, int>::const_reverse_iterator i = left.rbegin(); i != left.rend(); ++i) {	// CE
			if (right.count(i->first) > 0 && right[i->first] >= -i->second) {
				ans.push_back(make_pair(i->first, make_pair(-i->second, right[i->first])));
			}
		}
		reverse(ans.begin(), ans.end());

		printf("%d %d\n", m, (int)ans.size());
		for (int i = 0; i < (int)ans.size(); ++i) {
			printf("%d %d %d\n", ans[i].first, ans[i].second.first, ans[i].second.second);
		}
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714987  	2011-01-04 06:21:10 	Accepted	0.002	Minimum	26909	C++	4559 - Interior Points of Lattice Polygons

/*
id => 1174218
pid => 4559
pname => Interior Points of Lattice Polygons
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:40:17
*/
