#include <map>
#include <deque>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const long long INF = 12345678987654321LL;

struct Gao {
	long long lt, gt;
	deque<long long> eq;

	Gao() : lt(-INF), gt(INF) { }

	void add(const string& cmp, long long val) {
		if (cmp == "<") {
			lt = max(lt, val);
		} else if (cmp == ">") {
			gt = min(gt, val);
		} else {
			eq.push_back(val);
		}
	}

	void gao() {
		sort(eq.begin(), eq.end());
		eq.erase(unique(eq.begin(), eq.end()), eq.end());
		while (!eq.empty() && eq.front() < lt) {
			eq.pop_front();
		}
		while (!eq.empty() && eq.back() > gt) {
			eq.pop_back();
		}
	}

	long long full() {
		if (lt > gt) {
			return 2;
		} else if (eq.size() == gt - lt + 1) {
			for (long long i = lt; i <= gt; ++i) {
				if (eq[i - lt] != i) {
					return INF;
				}
			}
			return 2 + eq.size();
		} else {
			return INF;
		}
	}

	long long total() {
		return (lt == -INF ? 0 : 1) + (gt == INF ? 0 : 1) + eq.size();
	}
};

int main() {
	int n;
	long long val, key, ans, full, total;
	char var[4096], cmp[80];
	map<long long, map<string, Gao> > mp;

	while (scanf("%d", &n) != EOF && n > 0) {
		mp.clear();
		for (int i = 0; i < n; ++i) {
			scanf(" if %s %s %lld then turnOn( %lld ); ", var, cmp, &val, &key);
			mp[key][var].add(cmp, val);
		}
		ans = 0;
		for (map<long long, map<string, Gao> >::iterator i = mp.begin(); i != mp.end(); ++i) {
			full = INF;
			total = 0;
			for (map<string, Gao>::iterator j = i->second.begin(); j != i->second.end(); ++j) {
				j->second.gao();
				j->second.full();
				full = min(full, j->second.full());
				total += j->second.total();
			}
			ans += min(full, total);
		}
		printf("%lld\n", n - ans);
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//716016  	2011-01-06 09:05:38 	Accepted	0.023	Minimum	26909	C++	5051 - Conditional Statements

/*
id => 1174142
pid => 5051
pname => Conditional Statements
status => Accepted
lang => C++
time => 0.016
date => 2012-12-14 17:29:48
*/
