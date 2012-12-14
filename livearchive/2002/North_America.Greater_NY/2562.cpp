#include <map>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 64;

struct Answer {
    int rem, end;
    int l[MAXN], r[MAXN], v[MAXN], x[MAXN];
} cur, ans;

map<int, string> mp;
int textlen, codelen;
char buf[1024];
int text[1024];
char code[1024];

inline int c2i(char ch) {
    return ch == ' ' ? 0 : ch - 'A' + 1;
}

inline char i2c(int v) {
    return v == 0 ? ' ' : v - 1 + 'A';
}

void dfs(int p, const string& s) {
    if (ans.v[p] == -1) {
        dfs(ans.l[p], s + "0");
        dfs(ans.r[p], s + "1");
    } else {
        mp[ans.v[p]] = s;
    }
}

void gao(int x, int y) {
    if (x == textlen) {
    //   printf("[%d %d]\n", x, y);
        if (y == codelen) {
            if (ans.rem == -1) {
                ans = cur;
            } else {
                throw "MULTIPLE TABLES";
            }
        }
    } else if (cur.x[text[x]] != 0) {
   //     printf("[%d %d]\n\tcheck\n", x, y);
        int p = 0;
        while (cur.v[p] == -1 && y < codelen) {
            p = (code[y] == 0 ? cur.l[p] : cur.r[p]);
            ++y;
        }
        if (cur.v[p] == text[x]) {
            gao(x + 1, y);
        }
    } else {
        cur.x[text[x]] = 1;
        int p = 0, q = y, r = cur.end;
        vector<int> back;
        while (cur.v[p] < 0 && q < codelen && cur.rem >= 0) {
     //       printf("[%d %d]%d %d %d %d\n", x, y, p, q, cur.v[p], cur.rem);
            if (cur.v[p] == -1) {
                p = (code[q] == 0 ? cur.l[p] : cur.r[p]);
            } else {
                cur.v[p] = text[x];
                gao(x + 1, q);
                back.push_back(p);
                cur.v[p] = -1;
                cur.l[p] = cur.end++;
                cur.r[p] = cur.end++;
                cur.v[cur.l[p]] = cur.v[cur.r[p]] = -2;
                p = (code[q] == 0 ? cur.l[p] : cur.r[p]);
                --cur.rem;
            }
            ++q;
        }
        if (cur.v[p] == -2 && cur.rem >= 0) {
      //      printf("[%d_%d]%d %d %d %d\n", x, y, p, q, cur.v[p], cur.rem);
            cur.v[p] = text[x];
            gao(x + 1, q);
            cur.v[p] = -2;
        }
        for (vector<int>::const_iterator it = back.begin(); it != back.end(); ++it) {
            cur.v[*it] = -2;
            ++cur.rem;
        }
        cur.end = r;
        cur.x[text[x]] = 0;
    }
}

int main() {
    int re;

    scanf("%d", &re);
    fgets(buf, sizeof(buf), stdin);
    for (int ri = 1; ri <= re; ++ri) {
        mp.clear();
        fgets(buf, sizeof(buf), stdin);
        textlen = find(buf, buf + sizeof(buf), '\n') - buf;
        for (int i = 0; i < textlen; ++i) {
            text[i] = c2i(buf[i]);
            mp[text[i]];
        }
        fgets(buf, sizeof(buf), stdin);
        codelen = find(buf, buf + sizeof(buf), '\n') - buf;
        for (int i = 0; i < codelen; ++i) {
            code[i] = buf[i] - '0';
        }
        fill(cur.v, cur.v + MAXN, -2);
        fill(cur.x, cur.x + MAXN, 0);
        cur.v[0] = -1;
        cur.l[0] = 1;
        cur.r[0] = 2;
        cur.rem = mp.size() - 2;
        cur.end = 3;
        ans.rem = -1;
        printf("DATASET #%d\n", ri);
        try {
            gao(0, 0);
            if (ans.rem == -1) {
                throw 555;
            }
            dfs(0, "");
            for (map<int, string>::const_iterator it = mp.begin(); it != mp.end(); ++it) {
                printf("%c = %s\n", i2c(it->first), it->second.c_str());
            }
        } catch (...) {
            puts("MULTIPLE TABLES");
        }
    }

    return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805971 	2562 	Dehuff 	Accepted 	C++ 	0.012 	2011-05-23 16:17:59
/*
id => 1174065
pid => 2562
pname => Dehuff
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:17:51
*/
