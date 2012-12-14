#include <cstdio>

int main(void)
{
	int ww, w, h, tw, th, maxw, maxh;

	while(scanf("%d", &ww) != EOF && ww > 0) {
		tw = th = 0;
		maxw = maxh = 0;
		while(scanf("%d%d", &w, &h) != EOF && w >= 0 && h >= 0) {
			if(tw + w > ww) {
				tw = w;
				if(tw > maxw)
					maxw = tw;
				th = maxh;
				maxh = th + h;
			}
			else {
				tw = tw + w;
				if(tw > maxw)
					maxw = tw;
				if(th + h > maxh)
					maxh = th + h;
			}
		}
		printf("%d x %d\n", maxw, maxh);
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//806273 	3056 	Flow Layout 	Accepted 	C++ 	0.008 	2011-05-24 11:23:58
/*
id => 1174271
pid => 3056
pname => Flow Layout
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:47:12
*/
