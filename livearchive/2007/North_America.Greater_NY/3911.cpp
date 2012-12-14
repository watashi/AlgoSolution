#include <cstdio>
#include <cstring>

const char * f[] = {"kg", "lb", "l", "g"};
const char * t[] = {"lb", "kg", "g", "l"};
const double r[] = {2.2046, 0.4536, 0.2642, 3.7854};

int main(void)
{
	int ri, re;
	double x;
	char unit[16];

	scanf("%d", &re);
	for (ri = 1; ri <= re; ++ri) {
		printf("%d", ri);
		scanf("%lf%s", &x, unit);
		for (int i = 0; i < sizeof(r) / sizeof(double); ++i) {
			if (strcmp(unit, f[i]) == 0) {
				printf(" %.4lf %s", x * r[i], t[i]);
				break;
			}
		}
		printf("\n");
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805985 	3911 	Conversions 	Accepted 	C++ 	0.012 	2011-05-23 16:39:54
/*
id => 1174181
pid => 3911
pname => Conversions
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:34:51
*/
