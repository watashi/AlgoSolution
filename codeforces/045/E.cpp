#include <list>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

int gao(const list<string>& a, const list<string>& b) {
	int k = 0;
	for (list<string>::const_iterator i = a.begin(), j = b.begin(); i != a.end() && j != b.end(); ) {
		if (i->at(0) < j->at(0)) {
			++i;
		} else if (i->at(0) > j->at(0)) {
			++j;
		} else {
			++i;
			++j;
			++k;
		}
	}
	return k;
}

int main() {
	int n, m;
	string s, t;
	list<string> a, b;
	list<string>::iterator p;
	list<pair<string, string> > c;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		a.push_back(s);
	}
	for (int i = 0; i < n; ++i) {
		cin >> s;
		b.push_back(s);
	}
	a.sort();
	b.sort();

	m = gao(a, b);
	for (list<string>::iterator i = a.begin(); i != a.end(); ) {
		s = *i;
		i = a.erase(i);
		for (list<string>::iterator j = b.begin(); j != b.end(); ) {
			t = *j;
			j = b.erase(j);
			if (s[0] == t[0] || gao(a, b) == m) {
				if (s[0] == t[0]) {
					--m;
				}
				c.push_back(make_pair(s, t));
				break;
			}
			b.insert(j, t);
		}
	}

	c.sort();
	for (list<pair<string, string> >::const_iterator i = c.begin(); i != c.end(); ++i) {
		if (i != c.begin()) {
			cout << ", ";
		}
		cout << i->first << " " << i->second;
	}
	cout << endl;
	
	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//413354 	Apr 28, 2011 1:58:05 AM 	watashi 	45E - Director 	GNU C++ 	Accepted 	30 ms 	1400 KB 
