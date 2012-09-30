#include <algorithm> // auto fix CE
#include <stack>
#include <algorithm> // auto fix CE
#include <cstdio>

using namespace std;

int main() {
    int re, n;
    char buf[4096];

    scanf("%d", &re);
    fgets(buf, sizeof(buf), stdin);
    for (int ri = 1; ri <= re; ++ri) {
        char pre = ' ';
        stack<bool> s;

        n = 0;
        fgets(buf, sizeof(buf), stdin);
        for (int i = 0; buf[i] != '\0'; ++i) {
            if (buf[i] == ')') {
                if (s.top()) {
                    if (buf[n - 2] == '(') {
                        --n;
                        buf[n - 1] = buf[n];
                    } else {
                        buf[n++] = ')';
                    }
                }
                s.pop();
            } else if (buf[i] == '(') {
                if (pre == '-') {
                    s.push(true);
                    buf[n++] = '(';
                } else {
                    s.push(false);
                }
            } else if (buf[i] != ' ') {
                buf[n++] = buf[i];
            }
            if (buf[i] != ' ') {
                pre = buf[i];
            }
        }
        buf[n] = '\0';
        fputs(buf, stdout);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//318   2010-06-27 08:10:48     Accepted    1030    C++     0   180     anotherpeg  Source

// 2012-09-30 23:40:22 | Accepted | 1423 | C++ | 0 | 180 | watashi | Source
