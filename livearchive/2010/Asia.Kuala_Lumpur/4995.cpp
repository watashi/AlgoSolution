#include <map>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const string s[] = {"HELLO", "HOLA", "HALLO", "BONJOUR", "CIAO", "ZDRAVSTVUJTE"};
const string t[] = {"ENGLISH", "SPANISH", "GERMAN", "FRENCH", "ITALIAN", "RUSSIAN"};

int main() {
	int ri = 0;
	char buf[100];
	map<string, string> mp;

	for (int i = 0; i < sizeof(s) / sizeof(s[0]); ++i) {
		mp[s[i]] = t[i];
	}
	while (scanf("%s", buf) && buf[0] != '#') {
		printf("Case %d: ", ++ri);
		if (mp.count(buf) == 0) {
			puts("UNKNOWN");
		} else {
			puts(mp[buf].c_str());
		}
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//868535 	4995 	Language Detection 	Accepted 	C++ 	0.012 	2011-08-28 06:28:25
/*
id => 1174110
pid => 4995
pname => Language Detection
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:23:31
*/
