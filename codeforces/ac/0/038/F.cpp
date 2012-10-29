#include <map>
#include <string>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int score(const string& s) {
	static int n, a[80];
	n = s.length();
	transform(s.begin(), s.end(), a, bind2nd(minus<int>(), 'a' - 1));
	return accumulate(a, a + n, 0) * *max_element(a, a + n);
}

struct Status {
	int w, a, b;
	Status(int w = -1, int a = 0, int b = 0) : w(w), a(a), b(b) { }
	Status rev() const { return Status(-w, b, a); }
};

bool operator<(const Status& lhs, const Status& rhs) {
	if (lhs.w != rhs.w) {
		return lhs.w > rhs.w;
	} else if (lhs.a != rhs.a) {
		return lhs.a > rhs.a;
	} else {
		return lhs.b < rhs.b;
	}
}

map<string, pair<int, Status> > dp;

bool byLength(const string& lhs, const string& rhs) {
	return lhs.length() > rhs.length();
}

int main() {
	int n;
	string s;
	vector<string> q;

	cin >> n;
	for (int k = 0; k < n; ++k) {
		cin >> s;
		for (int i = 0; i < (int)s.length(); ++i) {
			for (int j = 1; i + j <= (int)s.length(); ++j) {
				dp[s.substr(i, j)].first |= 1 << k;
			}
		}
	}
	for (map<string, pair<int, Status> >::iterator k = dp.begin(); k != dp.end(); ++k) {
		q.push_back(k->first);
		k->second.first = __builtin_popcount(k->second.first) + score(k->first);
	}

	sort(q.begin(), q.end(), byLength);
	for (vector<string>::const_iterator k = q.begin(); k != q.end(); ++k) {
		pair<int, Status>& f = dp[*k];
		f.second.b += f.first;
		Status& t1 = dp[k->substr(0, k->length() - 1)].second;
		t1 = min(t1, f.second.rev());
		Status& t2 = dp[k->substr(1)].second;
		t2 = min(t2, f.second.rev());
	}
	const Status& ans = dp[""].second;
	cout << (ans.w == 1 ? "First" : "Second") << endl;
	cout << ans.a << " " << ans.b << endl;

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//235915 	Jan 2, 2011 11:07:57 AM 	watashi 	F - Smart Boy 	GNU C++ 	Accepted 	80 ms 	2512 KB 
