#include <cstdio>

int main() {
    int ri = 0;
    int k;
    long long n, p, ans;
    long long num[100], cnt[100], pos[100];

    while (scanf("%lld%lld", &p, &n) != EOF && p > 0) {
        k = 0;
        num[0] = 1;
        pos[0] = 0;
        cnt[0] = 1;
        while (num[k] < n) {
            ++k;
            num[k] = num[k - 1] * p;
            pos[k] = n % num[k];
            cnt[k] = (pos[k] / num[k - 1] + 1) * cnt[k - 1];
        }
        ans = 0;
        while (k > 0) {
            if (n > pos[k]) {
                ans += cnt[k];
                n = 0;
            } else {
                ans += n / num[k - 1] * cnt[k - 1];
                n = n % num[k - 1];
            }
            --k;
        }
        printf("Case %d: %04lld\n", ++ri, (ans + 1) % 10000);
    }

    return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723920  	2011-01-22 16:05:09 	Accepted	0.002	Minimum	26909	C++	3700 - Interesting Yang Hui Triangle

/*
id => 1174136
pid => 3700
pname => Interesting Yang Hui Triangle
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:29:05
*/
