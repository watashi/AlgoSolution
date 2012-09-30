#include <set>
#include <queue>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef vector<string> VS;

bool empty(const VS& vs) {
    for (VS::const_iterator i = vs.begin(); i != vs.end(); ++i) {
        for (string::const_iterator j = i->begin(); j != i->end(); ++j) {
            if (isdigit(*j)) {
                return false;
            }
        }
    }
    return true;
}

VS revit(const VS& vs) {
    VS ret(vs);
    for (VS::iterator i = ret.begin(); i != ret.end(); ++i) {
        reverse(i->begin(), i->end());
    }
    return ret;
}

VS rotit(const VS& vs) {
    int n = vs.size(), m = vs[0].size();
    VS ret(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ret[j] += vs[i][j];
        }
    }
    return ret;
}

string leftit(const string& s) {
    string ret;
    for (int i = 0; i < (int)s.size(); ++i) {
        switch (s[i]) {
        case '#':
            while ((int)ret.size() < i) {
                ret += ' ';
            }
            ret += '#';
            break;
        case '@':
        case '1':
        case '2':
        case '3':
            ret += s[i];
            break;
        }
    }
    return ret;
}

typedef VS GAOIT(const VS& vs);

VS leftit(const VS& vs) {
    VS ret;
    for (VS::const_iterator i = vs.begin(); i != vs.end(); ++i) {
        ret.push_back(leftit(*i));
    }
    return ret;
}

VS rightit(const VS& vs) {
    return revit(leftit(revit(vs)));
}

VS upit(const VS& vs) {
    return rotit(leftit(rotit(vs)));
}

VS downit(const VS& vs) {
    return rotit(rightit(rotit(vs)));
}

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int dfs(VS& vs, char ch, int x, int y) {
    if (vs[x][y] != ch) {
        return 0;
    } else {
        int ret = 1;
        vs[x][y] = ' ';
        for (int i = 0; i < 4; ++i) {
            ret += dfs(vs, ch, x + dx[i], y + dy[i]);
        }
        return ret;
    }
}

bool clearit(VS& vs) {
    bool ret = false;
    char ch;
    int n = vs.size(), m = vs[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (isdigit(vs[i][j])) {
                ch = vs[i][j];
                if (dfs(vs, ch, i, j) == 1) {
                    vs[i][j] = ch;
                } else {
                    ret = true;
                }
            }
        }
    }
    return ret;
}
/*
void dump(const VS& vs, const string& s = "") {
    puts(s.c_str());
    for (VS::const_iterator i = vs.begin(); i != vs.end(); ++i) {
        puts(i->c_str());
    }
}
*/
const int LIMIT = 18;
const char* dirs = "DLRU";
const GAOIT *gaoit[] = {downit, leftit, rightit, upit};

void gao(VS vs) {
    set<VS> s;
    queue<pair<VS, string> > q;

    s.insert(vs);
    q.push(make_pair(vs, ""));
    while (!q.empty()) {
        // dump(q.front().first, q.front().second);
        for (int i = 0; i < 4; ++i) {
            vs = q.front().first;
            do {
                vs = gaoit[i](vs);
            //  dump(vs, q.front().second + (char)('0' + i));
            } while (clearit(vs));
            if (s.count(vs) > 0) {
                continue;
            }
            s.insert(vs);
            if ((int)q.front().second.length() == LIMIT) {
                throw string("-1");
            } else if (empty(vs)) {
                throw q.front().second + dirs[i];
            }
            q.push(make_pair(vs, q.front().second + dirs[i]));
        }
        q.pop();
    }
    throw string("-1");
}

int main() {
    int re, n, m;
    char buf[1024];
    VS vs;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &n, &m);
        gets(buf);
        vs.clear();
        for (int i = 0; i < n; ++i) {
            gets(buf);
            vs.push_back(buf);
        }
        gets(buf);
        try {
            gao(vs);
        } catch (const string& e) {
            puts(e.c_str());
        }
    }

    return 0;
}

/*
唯一值得注意的是这句话，“There is one line after each map, ignore them.”一定要用gets把它读掉，因为这行里是有字符的。我作的时候直接用cin读下一个n,m,
WA的莫名其妙。
*/

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//399   2010-07-06 23:16:00     Accepted    1020    C++     1560    3244    anotherpeg  Source

// 2012-09-30 23:39:12 | Accepted | 1237 | C++ | 1290 | 3356 | watashi | Source
