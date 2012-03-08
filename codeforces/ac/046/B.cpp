#include <map>
#include <string>
#include <cstdio>

using namespace std;

const int d[10] = {0, 1, -1, 2, -2, 3, -3, 4, -4};
map<string, int> mp;
string pm[10];
int c[10] = {0};

int main() {
	int m, t;
	char s[20];
	
	mp["S"] = 3;
	pm[3] = "S";
	mp["M"] = 4;
	pm[4] = "M";
	mp["L"] = 5;
	pm[5] = "L";
	mp["XL"] = 6;
	pm[6] = "XL";
	mp["XXL"] = 7;
	pm[7] = "XXL";
	for (int i = 3; i <= 7; ++i) {
		scanf("%d", &c[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%s", s);
		t = mp[s];
		for (int j = 0; ; ++j) {
			if (c[t + d[j]] > 0) {
				--c[t + d[j]];
				puts(pm[t + d[j]].c_str());
				break;
			}
		}
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//208607 	Dec 5, 2010 7:49:18 PM 	watashi 	B - T-shirts from Sponsor 	GNU C++ 	Accepted 	30 ms 	1312 KB 
