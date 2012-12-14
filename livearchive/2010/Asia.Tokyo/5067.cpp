#include <set>
#include <map>
#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

set<string> done;
map<string, set<string> > mp;

set<string> gao(const string& s) {
	set<string> r;
	if (done.count(s) > 0) {
		return mp[s];
	} else if (mp.count(s) == 0) {
		r.insert(s);
		return r;
	} else {
		done.insert(s);
		for (set<string>::const_iterator it = mp[s].begin(); it != mp[s].end(); ++it) {
			set<string> t = gao(*it);
			r.insert(t.begin(), t.end());
		}
		return mp[s] = r;
	}
}

int main() {
	int n;
	string s, t, r;

	while (cin >> n && n > 0) {
		done.clear();
		mp.clear();
		for (int i = 0; i < n; ++i) {
			cin >> s;
			for (string::iterator c = s.begin(); c != s.end(); ++c) {
				if (*c == ':' || *c == ',' || *c == '.') {
					*c = ' ';
				}
			}
			
			istringstream iss(s);
			iss >> t;
			if (i == 0) {
				r = t;
			}

			set<string>& st = mp[t];
			while (iss >> t) {
				st.insert(t);
			}
		}
		
		printf("%d\n", gao(r).size());
	}	

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//771936  	2011-04-28 11:30:54 	Accepted	0.199	660	26909	C++	5067 - Membership Management
/*
id => 1174082
pid => 5067
pname => Membership Management
status => Accepted
lang => C++
time => 0.042
date => 2012-12-14 17:20:00
*/
