#include <map>
#include <stack>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

typedef bitset<256> Bitset;

int eval(int lhs, int rhs, char op) {
    switch (op) {
    case '+': return (lhs + rhs) & 255;
    case '-': return (lhs - rhs + 256) & 255;
    case '*': return (lhs * rhs) & 255;
    case '/': return (lhs / rhs) & 255;
    default: return -1;
    }
}

Bitset range(int l, int r) {
    Bitset ret;
    for (int i = l; i < r; ++i) {
        ret.set(i);
    }
    return ret;
}

int main() {
    map<string, pair<int, int> > var;
    stack<Bitset> val;
    char buf[80], *p;
    int n, x, y;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%d", buf, &x, &y);
        var[buf] = make_pair(x, y + 1);
    }

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        x = strtol(buf, &p, 10);
        if (*p == '\0') {
            val.push(range(x, x + 1));
        } else if (strchr("+-*/", buf[0]) == NULL) {
            pair<int, int> snd = var[buf];
            val.push(range(snd.first, snd.second));
        } else {
            Bitset rhs = val.top();
            val.pop();
            Bitset lhs = val.top();
            val.pop();
            if (buf[0] == '/' && rhs[0]) {
                puts("error");
                return 0;
            } else {
                Bitset ret;
                for (int i = 0; i < (int)lhs.size(); ++i) {
                    if (!lhs[i]) {
                        continue;
                    }
                    for (int j = 0; j < (int)rhs.size(); ++j) {
                        if (!rhs[j]) {
                            continue;
                        }
                        ret.set(eval(i, j, buf[0]));
                    }
                }
                val.push(ret);
            }
        }
    }
    puts("correct");
    return 0;
}

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Submission Date
//#486411 	watashi 	B 	: Accepted 	C++ 	00:00 sec 	1072 KB 	Sun Sep 16 13:17:42

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Code 	Submission Date
//#490463 	watashi 	2435 	: Accepted 	C++ 	00:00 sec 	1072 KB 	2101 Bytes 	Thu Sep 20 22:19:07
