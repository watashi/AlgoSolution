// from ZOJ2698
#include <map>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>

using namespace std;

const char* str[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const int num[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 , 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50, 60, 70, 80, 90};
map<string, int> mp;
map<int, string> pm;

const int MAXN = 1000000;
char buf[MAXN];
int wc[MAXN], dp[MAXN], pre[MAXN], val[MAXN];
string w[MAXN];

bool isalpha(const string& s) {
    return s.length() > 0 && isalpha(s[0]);
}

bool isspace(const string& s) {
    for (string::const_iterator i = s.begin(); i != s.end(); ++i) {
        if (!isspace(*i)) {
            return false;
        }
    }
    return true;
}

string tolower(string s) {
    for (string::iterator i = s.begin(); i != s.end(); ++i) {
        *i = tolower(*i);
    }
    return s;
}

typedef const string* ptr;

ptr skip(ptr p) {
    while (isspace(*p)) {
        ++p;
    }
    return p;
}

// gao5
int find(const string& s) {
    return mp.count(s) == 0 ? -1 : mp[s];
}

// [yz]
pair<int, ptr> gao4(ptr p) {
    //  fprintf(stderr, "[4] '%s'\n", p->c_str());
    int val = find(tolower(*p));
    // assert(isalpha(*p));
    if (val < 20) { // include (val == -1)
        return make_pair(val, p + 1);
    } else {
        ptr q = skip(p + 1);
        int t = find(tolower(*q));
        if (t != -1 && t < 10) {
            return make_pair(val + t, q + 1);
        } else {
            return make_pair(val, p + 1);
        }
    }
}

// [xyz]
pair<int, ptr> gao3(ptr p) {
    //  fprintf(stderr, "[3] '%s'\n", p->c_str());
    int val;
    // assert(isalpha(*p));
    val = find(tolower(*p));
    if (val == -1) {
        return make_pair(-1, p + 1);
    } else if (val < 10) {
        ptr q = skip(p + 1);
        if (tolower(*q) == "hundred") {
            // ptr r = skip(q + 1);
            // if (tolower(*r) == "and") {
            //  pair<int, ptr> pip = gao4(skip(r + 1));
            pair<int, ptr> pip = gao4(skip(q + 1));
            if (pip.first == -1) {
                return make_pair(val * 100, q + 1);
            } else {
                return make_pair(val * 100 + pip.first, pip.second);
            }
            // } else {
            //  return make_pair(val * 100, q + 1);
            // }
        } else {
            return make_pair(val, p + 1);
        }
    } else {
        return gao4(p);
    }
}

// [def] thousand [ghi]
pair<int, ptr> gao2(ptr p) {
    //  fprintf(stderr, "[2] '%s'\n", p->c_str());
    pair<int, ptr> pip = gao3(p);
    if (pip.first == -1) {
        return pip;
    }
    ptr q = skip(pip.second);
    if (tolower(*q) == "thousand") {
        pair<int, ptr> qiq = gao3(skip(q + 1));
        if (qiq.first == -1) {
            return make_pair(pip.first * 1000, q + 1);
        } else {
            return make_pair(pip.first * 1000 + qiq.first, qiq.second);
        }
    } else {
        return pip;
    }
}

// [abc] million [def] thousand [ghi]
pair<int, ptr> gao1(ptr p) {
    //  fprintf(stderr, "[1] '%s'\n", p->c_str());
    pair<int, ptr> pip = gao3(p);
    if (pip.first == -1) {
        return pip;
    }
    ptr q = skip(pip.second);
    if (tolower(*q) == "million") {
        pair<int, ptr> qiq = gao2(skip(q + 1));
        if (qiq.first == -1) {
            return make_pair(pip.first * 1000000, q + 1);
        } else {
            return make_pair(pip.first * 1000000 + qiq.first, qiq.second);
        }
    } else {
        return gao2(p);
    }
}

pair<int, ptr> gao(ptr p) {
    //  fprintf(stderr, "[0] '%s'\n", p->c_str());
    if (!isalpha(*p)) {
        return make_pair(-1, p + 1);
    } else if (tolower(*p) == "zero") {
        return make_pair(0, p + 1);
    } else {
        return gao1(p);
    }
}

int main() {
    for (size_t i = 0; i < sizeof(num) / sizeof(int); ++i) {
        mp[str[i]] = num[i];
        pm[num[i]] = str[i];
    }

    while (fgets(buf, sizeof(buf), stdin) != NULL && buf[0] != '\n') {
        int n = 0;
        for (int begin = 0; buf[begin] != '\0';) {
            int end = begin + 1;
            if (isalpha(buf[begin])) {
                while (buf[end] != '\0' && isalpha(buf[end])) {
                    ++end;
                }
            } else {
                while (buf[end] != '\0' && !isalpha(buf[end])) {
                    ++end;
                }
            }
            w[n++] = string(buf + begin, buf + end);
            if (n >= MAXN) { throw 1; }
            begin = end;
        }
        w[n] = "0";

        if (w[0] == "negative") {
            printf("-%d\n", gao(w + 2).first);
        } else {
            printf("%d\n", gao(w).first);
        }
    }
    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2181417   2010-04-30 19:36:05     Accepted    2311    C++     0   20688   watashi@Zodiac

// 2012-09-07 01:17:57 | Accepted | 2311 | C++ | 0 | 20688 | watashi | Source
