#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int diff[7] = {2, 2, 1, 2, 2, 2, 1};
const int next[7] = {2, 1, 2, 2, 1, 2, 2};
const int begin[7] = {0, 2, 3, 5, 7, 8, 10};

bool gao(int a, int b, string ret[7]) {
	int mask = 0;
	for (int i = 0; i < 7; ++i) {
		ret[i] = "";
		ret[i] += 'A' + a;
		if (b == 1) {
			ret[i] += '#';
			mask |= 1;
		} else if (b == -1) {
			ret[i] += 'b';
			mask |= 2;
		} else if (b != 0) {
			return false;
		}
//		printf("%d %d => %s\n", a, b, ret[i].c_str());
		b += diff[i] - next[a];
		a = (a + 1) % 7;
	}
	return mask != 3;
}

int main() {
	int key;
	bool blank = false, valid;
	char buf[80];
	string from[7], to[7];

	while (scanf("%s", buf) != EOF && buf[0] != '*') {
		if (blank) {
			puts("");
		} else {
			blank = true;
		}
		valid = true;
		if (valid && !gao(buf[0] - 'A', buf[1] == '#' ? 1 : (buf[1] == 'b' ? -1 : 0), from)) {
			valid = false;
			printf("Key of %s is not a valid major key\n", buf);
		}
		scanf("%s", buf);
		if (valid && !gao(buf[0] - 'A', buf[1] == '#' ? 1 : (buf[1] == 'b' ? -1 : 0), to)) {
			valid = false;
			printf("Key of %s is not a valid major key\n", buf);
		}
		if (valid) {
			printf("Transposing from %s to %s:\n", from[0].c_str(), to[0].c_str());
		}
		while (scanf("%s", buf) != EOF && buf[0] != '*') {
			if (!valid) {
				continue;
			}
			key = find(from, from + 7, buf) - from;
			if (key < 7) {
				printf("  %s transposes to %s\n", from[key].c_str(), to[key].c_str());
			} else {
				printf("  %s is not a valid note in the %s major scale\n", buf, from[0].c_str());
			}
		}
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//722955  	2011-01-20 15:02:00 	Accepted	0.053	Minimum	26909	C++	2237 - A Major Problem

/*
id => 1174025
pid => 2237
pname => A Major Problem
status => Accepted
lang => C++
time => 0.025
date => 2012-12-14 17:12:01
*/
