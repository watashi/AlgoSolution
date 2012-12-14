#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>

using namespace std;

typedef pair<char, string> Token;

inline Token nextNumeric(char *p, char **q) {
    static char buf[65536];
    int len = 0;
    if (*p == '+') {
        ++p;
    } else if (*p == '-') {
        buf[len++] = '-';
        ++p;
    }
    while (*p == '0') {
        ++p;
    }
    while (isdigit(*p)) {
        buf[len++] = *p;
        ++p;
    }
    if (len == 0 || (len == 1 && buf[0] == '-')) {
        len = 0;
        buf[len++] = '0';
    }
    buf[len] = '\0';
    *q = p;
    return make_pair('0', string(buf));
}

inline Token nextToken(bool f, char *p, char **q) {
    if (isdigit(*p) || (f && (*p == '+' || *p == '-') && isdigit(*(p + 1)))) {
        return nextNumeric(p, q);
    } else {
        Token ret(toupper(*p), "");
        *q = p + 1;
        return ret;
    }
}

inline int cmpNumeric(const string& lhs, const string& rhs) {
    if (lhs.length() != rhs.length()) {
        return lhs.length() < rhs.length() ? -1 : 1;
    } else if (lhs != rhs) {
        return lhs < rhs ? -1 : 1;
    } else {
        return 0;
    }
}

inline int cmpToken(const Token& lhs, const Token& rhs) {
    if (lhs.first != rhs.first) {
        return lhs.first < rhs.first ? -1 : 1;
    } else if (lhs.second == rhs.second) {
        return 0;
    } else if (lhs.second[0] == '-' ^ rhs.second[0] == '-') {
        return lhs.second[0] == '-' ? -1 : 1;
    } else if (lhs.second[0] == '-') {
        return -cmpNumeric(lhs.second.substr(1, string::npos), rhs.second.substr(1, string::npos));
    } else {
        return cmpNumeric(lhs.second, rhs.second);
    }
}

inline int cmpTokens(const vector<Token> &lhs, const vector<Token>& rhs) {
    int n = lhs.size(), m = rhs.size();
    for (int i = 0; i < n && i < m; ++i) {
        int t = cmpToken(lhs[i], rhs[i]);
        if (t != 0) {
            return t;
        }
    }
    return n == m ? 0 : n < m ? -1 : 1;
}

int main() {
    int re;
    char *p;
    vector<Token> v[2];
    static char buf[65536];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        for (int i = 0; i < 2; ++i) {
            scanf("%s", buf);
            p = buf;
            v[i].clear();
            while (*p != '\0') {
                v[i].push_back(nextToken(
                        v[i].empty() || v[i].back().first != '0',
                        p, &p));
        //        printf("\t%c %s\n", v[i].back().first, v[i].back().second.c_str());
            }
        //    puts("");
        }
        printf("%d %d\n", ri, cmpTokens(v[0], v[1]));
    }

    return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727375  	2011-01-29 12:42:21 	Accepted	0.002	Minimum	26909	C++	4237 - Extended Normal Order Sort
/*
id => 1174207
pid => 4237
pname => Extended Normal Order Sort
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:38:28
*/
