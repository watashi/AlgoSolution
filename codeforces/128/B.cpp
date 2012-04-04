#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

struct Substring {
    char *begin, *end;
    Substring(char *p): begin(p), end(p + 1) {
    }
    bool operator<(const Substring& o) const {
        return lexicographical_compare(o.begin, o.end, begin, end);
    }
};

const int MAXN = 100100;

char str[MAXN];

int main() {
    int n;
    priority_queue<Substring> q;

    scanf("%s%d", str, &n);
    for (char* p = str; *p != '\0'; ++p) {
        q.push(Substring(p));
    }
    while (!q.empty() && --n > 0) {
        Substring s = q.top();
        q.pop();
        if (*s.end != '\0') {
            ++s.end;
            q.push(s);
        }
    }
    if (q.empty()) {
        puts("No such line.");
    } else {
        *q.top().end = '\0';
        puts(q.top().begin);
    }

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1152102 	Feb 6, 2012 6:05:37 AM 	watashi 	128B - String 	GNU C++ 	Accepted 	130 ms 	3100 KB
