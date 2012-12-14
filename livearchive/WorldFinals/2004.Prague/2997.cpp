#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date {
	static bool isLeap(int yy) {
		return yy % 4 == 0 && (yy % 100 != 0 || yy % 400 == 0);
	}

	int yy, mm, dd;

	void read() {
		static int x;
		scanf("%d", &x);
		yy = x / 10000;
		mm = x / 100 % 100;
		dd = x % 100;
	}

	int toInt() const {
		int ret = yy * 365 + (yy - 1) / 4 - (yy - 1) / 100 + (yy - 1) / 400;
		days[1] += isLeap(yy);
		for (int i = 0; i < mm - 1; ++i) {
			ret += days[i];
		}
		days[1] = 28;
		return ret + dd;
	}

	void fromInt(int a) {
		yy = a / 146097 * 400;
		for (a %= 146097; a >= 365 + isLeap(yy); ++yy) {
			a -= 365 + isLeap(yy);
		}
		days[1] += isLeap(yy);
		for (mm = 1; a >= days[mm - 1]; ++mm) {
			a -= days[mm - 1];
		}
		days[1] = 28;
		dd = a + 1;
	}
} date;

void read(int n, map<int, int>& h, vector<pair<int, int> >& v) {
	v.clear();
	for (int i = 0; i < n; ++i) {
		date.read();
		int a = date.toInt();
		date.read();
		int b = date.toInt() + 1;
		h[a];
		h[b];
		v.push_back(make_pair(a, b));
	}
}

int main() {
	bool empty;
	int ri = 0, n, m;
	vector<int> r;
	vector<bool> mark;
	map<int, int> h;
	vector<pair<int, int> > v, w;

	while (scanf("%d%d", &n, &m) != EOF && !(n == 0 && m == 0)) {
		h.clear();
		read(n, h, v);
		read(m, h, w);
		r.clear();
		for (map<int, int>::iterator it = h.begin(); it != h.end(); ++it) {
			it->second = r.size();
			r.push_back(it->first);
		}

		vector<bool>(r.size(), false).swap(mark);
		for (vector<pair<int, int> >::iterator it = w.begin(); it != w.end(); ++it) {
			it->first = h[it->first];
			it->second = h[it->second];
			for (int i = it->first; i < it->second; ++i) {
				mark[i] = true;
			}
		}
		for (vector<pair<int, int> >::iterator it = v.begin(); it != v.end(); ++it) {
			it->first = h[it->first];
			it->second = h[it->second];
			for (int i = it->first; i < it->second; ++i) {
				mark[i] = false;
			}
		}
	
		if (ri > 0) {
			puts("");
		}
		printf("Case %d:\n", ++ri);
		empty = true;
		for (int i = 0; i < (int)mark.size(); ++i) {
			if (mark[i]) {
				int j = i;
				while (j < (int)mark.size() && mark[j]) {
					++j;
				}
				empty = false;
				date.fromInt(r[i]);
				printf("    %d/%d/%d", date.mm, date.dd, date.yy);
				if (r[j] - r[i] > 1) {
					date.fromInt(r[j] - 1);
					printf(" to %d/%d/%d", date.mm, date.dd, date.yy);
				}
				puts("");
				i = j;
			}
		}
		if (empty) {
			puts("    No additional quotes are required.");
		}
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723906  	2011-01-22 15:30:17 	Accepted	0.014	Minimum	26909	C++	2997 - Intersecting Dates

/*
id => 1174051
pid => 2997
pname => Intersecting Dates
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:15:35
*/
