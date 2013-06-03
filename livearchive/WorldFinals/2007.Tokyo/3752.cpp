#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
	int ri = 0;
	char buf[1024];
	int dp[1024];
	int ans;
	while (scanf("%s", buf) != EOF && strcmp(buf, "end") != 0) {
		ans = dp[0] = 1;
		for (int i = 1; buf[i]; ++i) {
			dp[i] = 1;
			for (int j = 0; j < i; ++j) {
				if (buf[i] > buf[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ans = max(ans, dp[i]);
		}
		printf("Case %d: %d\n", ++ri, ans);
	}
	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727328  	2011-01-29 09:18:22 	Accepted	0.014	Minimum	26909	C++	3752 - Containers

/*
id => 1243107
pid => 3752
pname => Containers
status => Accepted
lang => C++
time => 0.013
data => 2013-06-03 13:47:02
*/
