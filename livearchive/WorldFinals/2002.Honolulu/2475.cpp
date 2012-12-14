#include <map>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 80;

typedef pair<string, string> PSS;

struct CMP {
	bool operator()(const PSS& lhs, const PSS& rhs) const {
		if (lhs.first.length() != rhs.first.length()) {
			return lhs.first.length() > rhs.first.length();
		} else {
			return lhs.first > rhs.first;
		}
	}
};

int main() {
	int ri = 0, n;
	char buf[80];

	while (scanf("%d", &n) != EOF && n > 0) {
		string r, s, t;
		vector<string> vs;
		map<string, string> ans;
		priority_queue<PSS, vector<PSS>, CMP> pq;
	
		for (int i = 0; i < n; ++i) {
			scanf("%s", buf);
			s = buf;
			vs.push_back(s);
		}
		for (vector<string>::const_iterator it = vs.begin(); it != vs.end(); ++it) {
			for (vector<string>::const_iterator jt = vs.begin(); jt != vs.end(); ++jt) {
				if (it != jt && it->length() <= jt->length() && *it == jt->substr(0, it->length())) {
					r = jt->substr(it->length());
					if (ans.count(r) == 0 ||
						ans[r].length() > jt->length() ||
						(ans[r].length() == jt->length() && ans[r] > *jt)) {
						ans[r] = *jt;
						pq.push(make_pair(ans[r], r));
					}
				}
			}
		}

		while (ans.count("") == 0) {
			s = pq.top().second;
			t = pq.top().first;
			pq.pop();
			if (t != ans[s]) {
				continue;
			}
			for (vector<string>::const_iterator it = vs.begin(); it != vs.end(); ++it) {
				if (it->length() <= s.length() && *it == s.substr(0, it->length())) {
					r = s.substr(it->length());
					if (ans.count(r) == 0 ||
						ans[r].length() > t.length() ||
						(ans[r].length() == t.length() && ans[r] > t)) {
						ans[r] = t;
						pq.push(make_pair(ans[r], r));
					}
				}
				if (it->length() > s.length() && it->substr(0, s.length()) == s) {
					r = it->substr(s.length());
					if (ans.count(r) == 0 ||
						ans[r].length() > t.length() + r.length() ||
						(ans[r].length() == t.length() + r.length() && ans[r] > t + r)) {
						ans[r] = t + r;
						pq.push(make_pair(ans[r], r));
					}
				}
			}
		}

		s = ans[""];
		printf("Code %d: %d bits\n", ++ri, s.length());
		for (int i = 0; i < (int)s.length(); i += 20) {
			puts(s.substr(i, 20).c_str());
		}
		puts("");
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//722958  	2011-01-20 15:07:40 	Accepted	0.479	516	26909	C++	2475 - Undecodable Codes
/*
id => 1174105
pid => 2475
pname => Undecodable Codes
status => Accepted
lang => C++
time => 0.092
date => 2012-12-14 17:22:51
*/
