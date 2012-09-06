// 运用<分治?双向搜索?>的思想!!

#include <map>
#include <cstdio>
using namespace std;

int n, m, v[24], cur;
long long mask[24], tmp;
map<long long, int> mpa, mpb;

int main(void)
{
    while(scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &v[i], &m);
            mask[i] = 0;
            while(m--) {
                scanf("%d", &cur);
                mask[i] |= 1LL << cur;
            }
        }
        mpa.clear();
        mpb.clear();
        mpa.insert(make_pair(0, 0));
        mpb.insert(make_pair(0, 0));
        m = n / 2;
        n = n - m;
        for (int i = 0; i < 1 << m; i++) {
            cur = 0;
            tmp = 0;
            for (int j = 0; j < m; j++)
                if(i & (1 << j)) {
                    cur += v[j];
                    tmp ^= mask[j];
                }
            if(mpa.find(tmp) == mpa.end()) mpa.insert(make_pair(tmp, cur));
            else if(mpa[tmp] < cur) mpa[tmp] = cur;
        }
        for (int i = 0; i < 1 << n; i++) {
            cur = 0;
            tmp = 0;
            for (int j = 0; j < n; j++)
                if(i & (1 << j)) {
                    cur += v[m + j];
                    tmp ^= mask[m + j];
                }
            if(mpb.find(tmp) == mpb.end()) mpb.insert(make_pair(tmp, cur));
            else if(mpb[tmp] < cur) mpb[tmp] = cur;
        }
        cur = 0;
        for (map<long long, int>::iterator itr = mpa.begin(); itr != mpa.end(); ++itr)
            if(mpb.find(itr -> first) != mpb.end() && itr -> second + mpb[itr -> first] > cur)
                cur = itr -> second + mpb[itr -> first];
        printf("%d\n", cur);
    }
    return 0;
}

// Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
// 2746104 2008-02-07 18:36:24 Accepted 2898 C++ 00:01.11 1116K わたし

// 2012-09-07 01:45:45 | Accepted | 2898 | C++ | 690 | 312 | watashi | Source
