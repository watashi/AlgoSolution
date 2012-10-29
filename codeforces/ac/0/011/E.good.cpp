// GOOOOOOOOOOOOOOOOOOOOOOOD PROBLEM
// GOOD PROBLEM

#include <queue>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 21;
const int INF = 1000000007;

int l[MAXN], r[MAXN], d[MAXN];

// 有更简单得多的贪心，参考#248369
long long gao(const string& t) {
	int n, m, v, w, a, b;
	long long ans;

	n = t.length();
	m = n - count(t.begin(), t.end(), 'X');
	if (m == 0) {
		return 0;
	} else {
		ans = 50000000LL * m / (n + 1 - n % 2);	//
	}

	v = 1;
	for (int i = 0; i < n || v % 2 != 0; ++v) {
		d[v] = 0;
		while (i < n && (t[i] == 'X' || ((v % 2 == 0) ^ (i % 2 == 0) ^ (t[i] == 'L')))) {
			if (t[i] != 'X') {
				++d[v];
			}
			++i;
		}
	}
	if (n % 2 != 0) {	//
		d[v++] = 0;
	}
	w = v;

	// SPOJ1553.BACKUP
	priority_queue<pair<int, int> > pq;
	d[0] = d[v] = INF;
	for (int i = 0; i <= v; ++i) {
		l[i] = i - 1;
		r[i] = i + 1;
		pq.push(make_pair(-d[i], i));
	}
	while (true) {
		int t = -pq.top().first;
		int k = pq.top().second;
		pq.pop();
		if (r[k] == -1 || d[k] != t) {
			continue;
		}
		m -= d[k];
		if (m <= 0) {
			break;
		}
		a = l[k];
		b = r[k];
		w -= 2;
		ans = max(ans, 100000000LL * m / (n + w));
		d[a] = d[a] + d[b] - d[k];
		l[r[b]] = a;
		r[a] = r[b];
		r[k] = r[b] = -1;
		pq.push(make_pair(-d[a], a));
	}

	return ans;
}

int main() {
	string s, t;
	long long ans;

	cin >> s;
	t = "";
	for (int i = 0; i < (int)s.length(); ++i) {
		if (i > 0 && s[i] == s[i - 1] && s[i] != 'X') {
			t += 'X';
		}
		t += s[i];
	}
	if (t[t.length() - 1] == t[0]) {
		ans = max(gao(t + "X"), gao("X" + t));	//
	} else {
		ans = gao(t);
	}
	cout << fixed << setprecision(6) << ans / 1e6 << endl;

	return 0;
}

// so many if-else = =b
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//278808 	Feb 11, 2011 4:11:03 PM 	watashi 	11E - Forward, march! 	GNU C++ 	Accepted 	390 ms 	34200 KB
