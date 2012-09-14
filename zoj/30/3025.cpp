#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int p, q, r;

size_t next(const char buf[], size_t p)
{
    if (buf[p] == '-') {
        return next(buf, p + 1);
    }
    else if (buf[p] == '(') {
        size_t c = 1;

        while (c > 0) {
            ++p;
            switch(buf[p]) {
                case '(': ++c; break;
                case ')': --c; break;
            }
        }

        return p + 1;
    }
    else {
        return p + 1;
    }
}

int gao(const char buf[], size_t l, size_t r)
{
    size_t p;
    int a, b;

    if (buf[l] == '(') {
        p = next(buf, l + 1);
        a = gao(buf, l + 1, p);
        b = gao(buf, p + 1, r - 1);
        switch(buf[p]) {
            case '+': return max(a, b);
            case '*': return min(a, b);
        }
    }
    else {
        switch (buf[l]) {
            case '0': return a = 0;
            case '1': return a = 1;
            case '2': return a = 2;
            case 'P': return a = ::p;
            case 'Q': return a = ::q;
            case 'R': return a = ::r;
            case '-': return a = 2 - gao(buf, l + 1, r);
        }
    }
}

int main(void)
{
    static char buf[1024];
    int ans = 0;

    while (gets(buf) != NULL && strcmp(buf, ".") != 0) {
        ans = 0;
        for (p = 0; p <= 2; p++) {
            for (q = 0; q <= 2; q++) {
                for (r = 0; r <= 2; r++) {
                    if (gao(buf, 0, strlen(buf)) == 2) {
                        ++ans;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3040786   2008-08-18 16:51:35     Accepted    3025    C++     00:00.03    440K    Re:ReJudge
//

// 2012-09-07 01:56:12 | Accepted | 3025 | C++ | 0 | 180 | watashi | Source
