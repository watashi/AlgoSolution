#include <cstdio>

using namespace std;

const int MAXN = 3000300;
bool p[MAXN + 1];
int s[1000100];

int main() {
    for (int i = 2; i <= MAXN; ++i) {
        if (!p[i]) {
            for (int j = i + i; j <= MAXN; j += i) {
                p[j] = true;
            }
        }
    }
    s[0] = 0;
    for (int i = 1; i < 1000100; ++i) {
        s[i] = s[i - 1];
        if (!p[i * 3 + 7]) {
            ++s[i];
        }
    }
    
    int re, n;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        printf("%d\n", s[n]);
    }

    return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723958  	2011-01-22 17:32:44 	Accepted	0.496	7224	26909	C++	4382 - YAPTCHA
/*
id => 1174234
pid => 4382
pname => YAPTCHA
status => Accepted
lang => C++
time => 0.315
date => 2012-12-14 17:42:36
*/
