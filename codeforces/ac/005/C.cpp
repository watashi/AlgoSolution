#include <stack>
#include <cstdio>

using namespace std;

char s[1 << 20];

int main() {
	int n, m, c, b;
	stack<int> l;

	scanf("%s", s);
	n = 0;
	c = 1;
	b = -1;
	for (int i = 0; s[i] != '\0'; ++i) {
		if (s[i] == '(') {
			l.push(i);
		} else if (l.empty()) {
			b = i;
		} else {
			l.pop();
			m = i - (l.empty() ? b : l.top());
			if (n < m) {
				n = m;
				c = 1;
			} else if (m == n) {
				++c;
			}
		}
	}
	printf("%d %d\n", n, c);

	return 0;
}

//#  	When  	Who  	Problem  	Lang  	Verdict  	Time  	Memory
//256017 	Jan 21, 2011 10:44:24 AM 	watashi 	5C - Longest Regular Bracket Sequence 	GNU C++ 	Accepted 	60 ms 	6400 KB 
