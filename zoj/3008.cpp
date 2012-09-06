#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXP = 10240;
int pn, pl[2048], pp[2048];

void gen_p()
{
    static bool flag = false;

    if (flag) {
        return;
    }

    bool *p = new bool[MAXP + 1];

    for (int i = 0; i <= MAXP; i++) {
        p[i] = ((i & 1) == 0);
    }
    pn = 0;
    pl[pn++] = 2;
    for (int i = 3; i <= MAXP; i++) {
        if (p[i]) {
            continue;
        }
        pl[pn++] = i;
        for (int j = i + i; j <= MAXP; j += i) {
            p[j] = true;
        }
    }
    for (int i = 0; i < pn; i++) {
        pp[i] = pl[i] * pl[i];
    }

    delete[] p;
}

vector<pair<int, int> > factors(int x)
{
    vector<pair<int, int> > ret;

    gen_p();
    for (int i = 0; pp[i] <= x; i++) {
        if (x % pl[i] == 0) {
            ret.push_back(make_pair(pl[i], 0));
            do {
                x /= pl[i];
                ++ret.back().second;
            } while(x % pl[i] == 0);
        }
    }
    if (x > 1) {
        ret.push_back(make_pair(x, 1));
    }

    return ret;
}

size_t gao(int x, int t, size_t l, vector<pair<int, int> >& fs, size_t& cnt)
{
    if (l == fs.size()) {
        ++cnt;
        return cnt;
    }

    long long tmp = t;

    for (int i = 0; i <= fs[l].second; i++) {
        gao(x, (int)tmp, l + 1, fs, cnt);
        tmp *= fs[l].first;
        if (tmp > x) {
            break;
        }
    }

    return cnt;
}

int main(void)
{
    int n, m;

    while (scanf("%d%d", &n, &m) != EOF) {
        vector<pair<int, int> > fs = factors(n);
        size_t cnt;

        for (size_t i = 0; i < fs.size(); i++) {
            fs[i].second *= m;
        }
        printf("%u\n", gao(n, 1, 0, fs, cnt = 0));
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3009318   2008-07-27 20:20:42     Accepted    3008    C++     00:00.01    864K    Re:ReJudge

// 2012-09-07 01:54:29 | Accepted | 3008 | C++ | 0 | 196 | watashi | Source
