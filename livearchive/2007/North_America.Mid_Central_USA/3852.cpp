#include <map>
#include <cmath>
#include <cstdio>
#include <limits>
#include <vector>
#include <algorithm>
using namespace std;

struct Point{
	double x;
	double y;
	int mask;
};

int p, c, g, n;
int v[12], mask[12], all;
Point pt[100];
double risk[100][12];
double ans;

inline double dist(const Point& lhs, const Point& rhs)
{
	double x = lhs.x - rhs.x, y = lhs.y - rhs.y;
	return sqrt(x * x + y * y);
}

void dfs(const vector<double>& arg, int level, int bound)
{
	if(level == 0) {
		ans = min(ans, *max_element(arg.begin(), arg.end()));
		return;
	}
	vector<double> cmp(p);
	--level;	
	for (int i = bound + 1; i < n; i++) {
		for (int j = 0; j < p; j++)
			cmp[j] = min(arg[j], risk[i][j]);
		dfs(cmp, level, i);
	}
}

int main(void)
{
	char ch, str[12];

	while(scanf("%d", &p) != EOF && p != 0) {
		scanf("%d%d", &c, &g);
		all = 0;
		map<char, int> mp;
		for (n = 0; n < p; n++) {
			scanf(" %c%lf%lf%d", &ch, &pt[n].x, &pt[n].y, &v[n]);
			pt[n].mask = 0;
			all |= 1 << n;
			mp.insert(make_pair(ch, n));
		}
		for (int i = 0; i < c; i++) {
			mask[i] = 0;
			scanf("%s", str);
			int m = 0, tmp[12];
			while(str[m] != '\0') {
				tmp[m] = mp[str[m]];
				mask[i] |= 1 << tmp[m];
				++m;
			}
			for (int j = 0; j < m; j++) {
				pt[tmp[j]].mask |= mask[i];
				for (int k = 0; k < j; k++) {
					pt[n].x = (pt[tmp[j]].x * v[tmp[j]] + pt[tmp[k]].x * v[tmp[k]]) / (v[tmp[j]] + v[tmp[k]]);
					pt[n].y = (pt[tmp[j]].y * v[tmp[j]] + pt[tmp[k]].y * v[tmp[k]]) / (v[tmp[j]] + v[tmp[k]]);
					pt[n].mask = mask[i];
					++n;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < p; j++) {
				if((pt[i].mask & (1 << j)) == 0) risk[i][j] = numeric_limits<double>::max();
				else risk[i][j] = dist(pt[i], pt[j]) * v[j];
			}
		}
		ans = numeric_limits<double>::max();
		vector<double> cmp(p, numeric_limits<double>::max());
		dfs(cmp, g, -1);
		if(ans == numeric_limits<double>::max()) printf("too few guards\n");
		else printf("%.2lf\n", ans);
	}
	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//806016 	3852 	Guard 	Accepted 	C++ 	0.132 	2011-05-23 17:15:57
/*
id => 1174270
pid => 3852
pname => Guard
status => Accepted
lang => C++
time => 0.102
date => 2012-12-14 17:47:04
*/
