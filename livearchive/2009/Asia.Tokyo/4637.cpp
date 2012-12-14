#include <set>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

inline string sub(const string& s, const string& a, const string& b) {
//	printf("sub(%s, %s, %s) = ", s.c_str(), a.c_str(), b.c_str());
	string::size_type pos = s.find(a);
	if (pos == string::npos) {
//		puts("");
		return "";
	} else {
		string::size_type oldpos = 0;
		string ret = "";
		do {
//			printf("(%d,%d)", oldpos, pos);
			ret += s.substr(oldpos, pos - oldpos);
//			printf("-[%s]", ret.c_str());
			ret += b;
//			printf("~[%s]", ret.c_str());
			oldpos = pos + a.length();
		} while (oldpos < s.length() && (pos = s.find(a, oldpos)) != string::npos);
		if (oldpos < s.length()) {
			ret += s.substr(oldpos);
		}
//		printf(" [[%s]]\n", ret.c_str());
		return ret;
	}
}

int main() {
	int n, begin, end, ans;
	char buf[1024];
	string a[16], b[16], c, d;

	while (scanf("%d", &n) != EOF && n > 0) {
		for (int i = 0; i < n; ++i) {
			scanf("%s", buf);
			a[i] = buf;
			scanf("%s", buf);
			b[i] = buf;
		}
		scanf("%s", buf);
		c = buf;
		scanf("%s", buf);
		d = buf;

		vector<string> q;
		set<string> s;

		if (c == d) {
			puts("0");
			goto NEXT;
		}

		q.push_back(c);
		s.insert(c);
		ans = begin = 0;
		while (begin < (int)q.size()) {
			++ans;
			end = (int)q.size();
			while (begin < end) {
				const string str = q[begin++];
//				printf("gao [%s]\n", str.c_str());
				for (int i = 0; i < n; ++i) {
					string tmp = sub(str, a[i], b[i]);
					if (0 < tmp.length() && tmp.length() <= d.length() && s.count(tmp) == 0) {
						if (tmp == d) {
							printf("%d\n", ans);
							goto NEXT;
						} else {
							q.push_back(tmp);
							s.insert(tmp);
						}
					}
				}
			}
		}
		puts("-1");
NEXT:
		continue;
	}

	return 0;
}
//715028  	2011-01-04 07:35:27 	Accepted	0.049	Minimum	26909	C++	4637 - Repeated Substitution with Sed
/*
id => 1174286
pid => 4637
pname => Repeated Substitution with Sed
status => Accepted
lang => C++
time => 0.015
date => 2012-12-14 17:49:39
*/
