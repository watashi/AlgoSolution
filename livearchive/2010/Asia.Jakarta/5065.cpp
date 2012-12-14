#include <set>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const string rank = "23456789TJQKA";
const string suit = "DCHS";

int main() {
	int re, c;
	char buf[80];
	set<int> s;
	vector<int> a, b;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		a.clear();
		for (int i = 0; i < 52; ++i) {
			a.push_back(i);
		}

		b.clear();
		for (int i = 0; i < 26; ++i) {
			scanf("%s", buf);
			b.push_back((rank.find(buf[0]) << 2) ^ suit.find(buf[1]));
		}
		sort(b.begin(), b.end());
		
		s.clear();
		set_difference(a.begin(), a.end(), b.begin(), b.end(), insert_iterator<set<int> >(s, s.begin()));
	
		c = 0;
		for (int i = 0; i < 26; ++i) {
			set<int>::iterator it = s.upper_bound(b[i]);
			if (it != s.begin()) {
				s.erase(--it);
				++c;
			}
		}
		printf("%d\n", c);
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//864743 	5065 	Romantic Date 	Accepted 	C++ 	0.008 	2011-08-24 06:02:23
/*
id => 1174302
pid => 5065
pname => Romantic Date
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:51:44
*/
