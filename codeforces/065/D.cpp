#include <set>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const string house[] = {"Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"};

char str[32768];

int main() {
	int n;
	set<string> ans;
	set<vector<int> > from, to;

	scanf("%d%s", &n, str);
	from.insert(vector<int>(4, 0));

	for (int i = 0; i < n; ++i) {
		to.clear();
		if (str[i] == '?') {
			for (set<vector<int> >::const_iterator it = from.begin(); it != from.end(); ++it) {
				vector<int> v = *it;
				int m = *min_element(v.begin(), v.end());
				for (vector<int>::iterator jt = v.begin(); jt != v.end(); ++jt) {
					if (*jt == m) {
						++*jt;
						to.insert(v);
						--*jt;
					}
				}
			}
		} else {
			int h = string("GHRS").find(str[i]);
			for (set<vector<int> >::const_iterator it = from.begin(); it != from.end(); ++it) {
				vector<int> v = *it;
				++v[h];
				to.insert(v);
			}
		}
		from.swap(to);
	}

	for (set<vector<int> >::const_iterator it = from.begin(); it != from.end(); ++it) {
		vector<int> v = *it;
		int m = *min_element(v.begin(), v.end());
		for (vector<int>::iterator jt = v.begin(); jt != v.end(); ++jt) {
			if (*jt == m) {
				ans.insert(house[jt - v.begin()]);
			}
		}
	}
	for (set<string>::const_iterator it = ans.begin(); it != ans.end(); ++it) {
		puts(it->c_str());
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//413437 	Apr 28, 2011 3:50:25 AM 	watashi 	65D - Harry Potter and the Sorting Hat 	GNU C++ 	Accepted 	80 ms 	1400 KB 
