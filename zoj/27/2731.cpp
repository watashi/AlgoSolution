// O(n^2)

#include <list>
#include <cstdio>

using namespace std;
/*
// TLE when m is very large
int J(int n, int m)
{
    int d = 1;

    while (d <= (m - 1) * n) {
        d = (m * d + m - 2) / (m - 1);
    }

    return m * n + 1 - d; // begin with 1
}
*/

void advance(list<int>::iterator& it, size_t step, list<int>& l)
{
    step %= l.size();
    while (step > 0) {
        ++it;
        --step;
        if (it == l.end()) {
            it = l.begin();
        }
    }
}

int J(int n, int m)
{
    list<int> l;

    for (int i = 1; i <= n; i++) {
        l.push_back(i);
    }

    list<int>::iterator it = l.begin();

    while (l.size() > 1) {
        advance(it, m - 1, l);
        it = l.erase(it);
        if (it == l.end()) {
            it = l.begin();
        }
    }

    return *it;
}

int main(void)
{
    int n, m, p, j;

    while (scanf("%d%d%d", &n, &m, &p) != EOF && n > 0) {
        list<int> l;

        for (int i = 1; i <= n; i++) {
            l.push_back(i);
        }

        list<int>::iterator it = l.begin();

        advance(it, m - 1, l);
        while (*it != p) {
            it = l.erase(it);
            if (it == l.end()) {
                it = l.begin();
            }
            advance(it, m - 1, l);
        }
        j = (l.size() == 1) ? 1 : J(l.size() - 1, m);
        //j = J(l.size() - 1, m);
        //printf("%d %u\n", j, l.size());
        advance(it, l.size() - j, l);
        printf("%d\n", *it);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3022329 2008-08-05 11:09:04 Accepted 2731 C++ 00:00.16 876K Re:ReJudge
//

// 2012-09-07 01:36:42 | Accepted | 2731 | C++ | 110 | 180 | watashi | Source
