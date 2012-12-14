#include <map>
#include <queue>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int c, r, q, x;
	string s, t;

	while (cin >> c && c > 0) {
		map<string, int> mp;
		for (int i = 0; i < c; ++i) {
			cin >> s;
			mp[s] = i;
		}

		cin >> r;
		getline(cin, s);		
		vector<vector<int> > e(c + r);
		for (int i = 0; i < r; ++i) {
			getline(cin, s);
			istringstream iss(s);
			iss >> t >> s;
			e[mp[s]].push_back(c + i);
			e[c + i].push_back(mp[s]);
			while (iss >> x >> s) {
				e[mp[s]].push_back(c + i);
				e[c + i].push_back(mp[s]);
			}
		}

		cin >> q;
		for (int i = 0; i < q; ++i) {
			cin >> s >> t;
			queue<int> q;
			vector<int> d(c + r, -1);
			q.push(mp[s]);
			d[mp[s]] = 0;
			x = mp[t];
			while (!q.empty() && d[x] == -1) {
				for (vector<int>::const_iterator i = e[q.front()].begin(); i != e[q.front()].end(); ++i) {
					if (d[*i] == -1) {
						d[*i] = d[q.front()] + 1;
						q.push(*i);
					}
				}
				q.pop();
			}
			cout << "Number of roads needed from " << s << " to " << t << " is " << d[x] / 2 << "." << endl;
		}
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//715033  	2011-01-04 07:50:59 	Accepted	0.004	Minimum	26909	C++	4461 - Easy does it!
/*
id => 1174094
pid => 4461
pname => Easy does it!
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:21:28
*/
