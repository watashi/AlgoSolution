#include <set>
#include <map>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <numeric>
#include <sstream>
#include <algorithm>

using namespace std;

const int MAXN = 52;
const int MOD = 1000000007;

set<string> done;
map<string, vector<string> > mp;

vector<string> gao(const string& key) {
    vector<string>& val = mp[key];

    if (done.insert(key).second) {
        vector<string> swp;
        for (vector<string>::const_iterator it = val.begin(); it != val.end(); ++it) {
            if (it->at(0) == '[') {
                swp.push_back(it->substr(1, it->length() - 2));
            } else if (isupper(it->at(0))) {
                swp.push_back(*it);
            } else {
                vector<string> tmp = gao(*it);
                swp.insert(swp.end(), tmp.begin(), tmp.end());
            }
        }
        val.swap(swp);
        if ((int)val.size() >= 4 * MAXN) {
            val.resize(4 * MAXN);
        }
    }

    return val;
}

int dp[MAXN][MAXN][MAXN][MAXN];

int main() {
    int n[4], m;
    string dna, tok;
    char buf[4096];

    for (int i = 0; i < 4; ++i) {
        scanf("%d", &n[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf(" %[a-z]:", buf);
        vector<string>& v = mp[buf];
        if (i == 0) {
            dna = buf;
        }
        scanf("  %[^\n]", buf);
        istringstream iss(buf);
        while (iss >> tok) {
            v.push_back(tok);
        }
    }

    vector<string> vs = gao(dna);
    if ((int)vs.size() == accumulate(n, n + 4, 0)) {
        dp[0][0][0][0] = 1;
        for (int i = 0; i < (int)vs.size(); ++i) {
            for (int u = 0; u <= i && u <= n[0]; ++u) {
                for (int v = 0; u + v <= i && v <= n[1]; ++v) {
                    for (int w = 0; u + v + w <= i && w <= n[2]; ++w) {
                        int r = i - u - v - w;
                        if (r <= n[3]) {
                            const int& src = dp[u][v][w][r];
                            if (src != 0) {
#define GAO(ch, a, b, c, d) \
    if (vs[i].find(ch) != string::npos) {\
        int& dest = dp[u + a][v + b][w + c][r + d];\
        dest += src;\
        if (dest >= MOD) {\
            dest -= MOD;\
        }\
    }
                                GAO('A', 1, 0, 0, 0)
                                GAO('T', 0, 1, 0, 0)
                                GAO('G', 0, 0, 1, 0)
                                GAO('C', 0, 0, 0, 1)
#undef GAO
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", dp[n[0]][n[1]][n[2]][n[3]]);

    return 0;
}

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Code 	Submission Date
//#490596 	watashi 	2437 	: Accepted 	C++ 	00:32 sec 	29772 KB 	2661 Bytes 	Fri Sep 21 00:57:59

