#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <algorithm>

using namespace std;

char buf[1 << 22];
long long v[1 << 18];

int main() {
    int re;
    int d, c, ans;
    char *p;

    scanf("%d", &re);
    fgets(buf, sizeof(buf), stdin);
    for (int ri = 1; ri <= re; ++ri) {
        fgets(buf, sizeof(buf), stdin);
        p = buf;
        d = c = 0;
        while (*p != '\n') {
            if (*p == '[') {
                ++d;
                ++p;
            } else if (*p == ']') {
                --d;
                ++p;
            } else if (isdigit(*p)) {
            //  v[c++] = strtoll(p, &p, 10) << d;
                v[c++] = (long long)strtol(p, &p, 10) << d;
            } else {
                ++p;
            }
        }
        sort(v, v + c);
        d = 1;
        ans = 1;
        for (int i = 1; i < c; ++i) {
            if (v[i] == v[i - 1]) {
                ans = max(ans, ++d);
            } else {
                d = 1;
            }
        }
        printf("%d\n", c - ans);
    }

    return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727338  	2011-01-29 09:31:29 	Accepted	0.057	Minimum	26909	C++	4286 - Equilibrium Mobile

/*
id => 1174317
pid => 4286
pname => Equilibrium Mobile
status => Accepted
lang => C++
time => 0.032
date => 2012-12-14 17:53:32
*/
