#include <stack>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
	double d;
	stack<double> s;

	while (scanf("%lf", &d) != EOF) {
		s.push(sqrt(d));
	}
	while (!s.empty()) {
		printf("%.4lf\n", s.top());
		s.pop();
	}

	return 0;
}
/*
id => 4677335
date => 18:01:0415 Dec 2012
user => watashi
pname => Reverse Root
lang => C++
status => Accepted
testid => 
time => 0.375
mem => 3 004 KB
pid => 1001
*/
