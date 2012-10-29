#include <set>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1000000007;

int main() {
	int n, m;
	string s;
	long long d, t;
	set<int> p[128];
	set<int>::const_iterator l, r;

	cin >> n >> m >> s;
	for (int i = 0; i < 128; ++i) {
		p[i].insert(-INF);
		p[i].insert(INF);
	}
	for (int i = 0; i < (int)s.length(); ++i) {
		p[s[i]].insert(i);
	}
	
	for (int i = 0; i < n; ++i) {
		d = 0;
		cin >> s;
		for (int j = 0; j < (int)s.length(); ++j) {
			l = r = p[s[j]].lower_bound(j);
			--l;
			t = min(*r - j, j - *l);
			if (t < INF / 2) {
				d += t;
			} else {
				d += (int)s.length();
			}
		}
		cout << d << "\n";
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//308318 	Feb 26, 2011 10:35:45 PM 	watashi 	62B - Tyndex.Brome 	GNU C++ 	Accepted 	160 ms 	4600 KB 
