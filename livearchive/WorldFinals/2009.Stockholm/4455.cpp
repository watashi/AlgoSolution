#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 218;
const long long INF = 1000000007LL * 1000000007LL;

set<pair<string, string> > st;

void gao(const map<string, int>& mp, const vector<string>& v, long long w[MAXN][MAXN]) {
	static long long d[MAXN][MAXN];
	int n = v.size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				d[i][j] = 0;
			} else if (st.count(make_pair(v[i], v[j])) != 0) {
				d[i][j] = 1;
			} else if (v[i][0] == v[j][0] && mp.count(v[i].substr(1)) > 0 && mp.count(v[j].substr(1)) > 0) {
				d[i][j] = w[mp.find(v[i].substr(1))->second][mp.find(v[j].substr(1))->second];
			} else {
				d[i][j] = INF;
			}
		}
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			w[i][j] = d[i][j];
		}
	}
}

vector<string> v[MAXN];
map<string, int> mp[MAXN];
long long w[MAXN][MAXN];

void add(const string& s) {
	for (int i = 0; i <= (int)s.length(); ++i) {
		mp[s.length() - i][s.substr(i)];
	}
}

int main() {
	int ri = 0, n, m;
	long long ans;
	string s, t, a, b;

	while (cin >> s >> t >> n && s != ".") {
		st.clear();
		m = s.length();
		for (int i = 0; i <= m; ++i) {
			mp[i].clear();
		}
		add(s);
		add(t);
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			add(a);
			add(b);
			st.insert(make_pair(a, b));
		}
		for (int i = 0; i <= m; ++i) {
			v[i].clear();
			for (map<string, int>::iterator j = mp[i].begin(); j != mp[i].end(); ++j) {
				j->second = v[i].size();
				v[i].push_back(j->first);
			}
		}

		w[0][0] = 0;
		for (int i = 1; i <= m; ++i) {
			gao(mp[i - 1], v[i], w);
		}
		ans = w[mp[m][s]][mp[m][t]];
		cout << "Case " << ++ri << ": ";
		if (ans < INF) {
			cout << ans;
		} else {
			cout << "No solution";
		}
		cout << endl;
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//800094 	4455 	Suffix-Replacement Grammars 	Accepted 	C++ 	5.780 	2011-05-17 13:04:55
/*
id => 1174040
pid => 4455
pname => Suffix-Replacement Grammars
status => Accepted
lang => C++
time => 2.379
date => 2012-12-14 17:13:54
*/
