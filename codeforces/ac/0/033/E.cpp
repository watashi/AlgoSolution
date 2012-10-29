#include <map>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m, dd, hh, mm, t;
	int sep[16];
	char buf[80];
	vector<string> todo;
	map<string, int> cost;
	vector<pair<int, int> > time;
	vector<vector<pair<int, bool> > > dp;
	vector<pair<pair<int, int>, pair<int, int> > > job;

	scanf("%d%d%d", &n, &m, &dd);
	for (int i = 0; i < n; ++i) {
		scanf("%s", buf);
		todo.push_back(buf);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &cost[todo[i]]);
	}
	
	for (int i = 0; i < 8; ++i) {
		scanf("%*[^0-9]%d:%d", &hh, &mm);
		sep[i] = hh * 60 + mm;
	}
	for (int i = 1, k = 0; i <= dd; ++i) {
		for (int j = 0; j < 24 * 60; ++j) {
			if (k % 2 == 0 && j == sep[k]) {
				k = (k + 1) % 8;
			}
			if (k % 2 == 0) {
				time.push_back(make_pair(i, j));
			}
			if (k % 2 != 0 && j == sep[k]) {
				k = (k + 1) % 8;
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		scanf("%s%d%d:%d%d", buf, &dd, &hh, &mm, &t);
		if (cost.count(buf) == 0) {
			continue;
		}
		job.push_back(make_pair(make_pair(
				lower_bound(time.begin(), time.end(), make_pair(dd, hh * 60 + mm)) - time.begin(),
				i), make_pair(cost[buf], t)));
	}
	sort(job.begin(), job.end());
	reverse(job.begin(), job.end());

	n = time.size();
	m = job.size();
	dp = vector<vector<pair<int, bool> > >(1, vector<pair<int, bool> >(n + 1));
	for (int i = 0; i < m; ++i) {
		t = job[i].second.first;
		dp.push_back(dp.back());
		for (int j = 0; j <= n; ++j) {
			dp[i + 1][j].second = false;
		}
		for (int j = t; j <= job[i].first.first; ++j) {
			if (dp[i + 1][j - t].first < dp[i][j].first + job[i].second.second) {
				dp[i + 1][j - t].first = dp[i][j].first + job[i].second.second;
				dp[i + 1][j - t].second = true;
			}
		}
	}

	printf("%d\n", dp[m][0].first);
	todo.clear();
	for (int i = m - 1, j = 0; i >= 0; --i) {
		if (dp[i + 1][j].second) {
			t = j + job[i].second.first - 1;
			sprintf(buf, "%d %d %02d:%02d %d %02d:%02d", job[i].first.second + 1,
				time[j].first, time[j].second / 60, time[j].second % 60,
				time[t].first, time[t].second / 60, time[t].second % 60);
			todo.push_back(buf);
			j = t + 1;
		}
	}
	printf("%d\n", todo.size());
	for (int i = 0; i < (int)todo.size(); ++i) {
		puts(todo[i].c_str());
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//421398 	May 1, 2011 7:47:06 PM 	watashi 	33E - Helper 	GNU C++ 	Accepted 	110 ms 	46000 KB 
