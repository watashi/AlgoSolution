#include <cstdio>

int main() {
    long long dp[10086];

    dp[0] = 1;
    for (int i = 1; i < 10086; ++i) {
        for (int j = 0; j < i; j += 2) {
            dp[i] += dp[j / 2];
        }
        if (i % 2 == 0) {
            dp[i] += dp[i / 2];
        }
    }

    int re;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        int n;

        scanf("%d", &n);
        printf("%d %lld\n", ri, dp[n]);
    }

    return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727373  	2011-01-29 12:40:18 	Accepted	0.266	460	26909	C++	4235 - Recursively Palindromic Partitions
/*
id => 1174206
pid => 4235
pname => Recursively Palindromic Partitions
status => Accepted
lang => C++
time => 0.036
date => 2012-12-14 17:38:14
*/
