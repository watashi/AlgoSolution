#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int ri = 0;
    int n, m, g, zero;
    long long t, a;
    vector<long long> pos, neg;

    while (scanf("%d%lld", &n, &t) != EOF && (n != 0 || t != 0)) {
        zero = 0;
        pos.clear();
        neg.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &a);
            if (a > 0) {
                pos.push_back(a);
            } else if (a < 0) {
                neg.push_back(-a);
            } else {
                ++zero;
            }
        }
        if (t > 0) {
            m = 0;
            sort(pos.begin(), pos.end());
            // for (size_t i = 0; i < pos.size(); ++i) {
            //    m += pos.end() - upper_bound(pos.begin(), pos.end(), t / pos[i]);
            // }
            a = pos.size();
            for (size_t i = 0; i < pos.size(); ++i) {
                while (a > 0 && pos[a - 1] * pos[i] > t) {
                    --a;
                }
                m += pos.size() - a;
            }
            sort(neg.begin(), neg.end());
            // for (size_t i = 0; i < neg.size(); ++i) {
            //     m += neg.end() - upper_bound(neg.begin(), neg.end(), t / neg[i]);
            // }
            a = neg.size();
            for (size_t i = 0; i < neg.size(); ++i) {
                while (a > 0 && neg[a - 1] * neg[i] > t) {
                    --a;
                }
                m += neg.size() - a;
            }
        } else if (t < 0) {
            t = -t;
            m = n * n;
            sort(pos.begin(), pos.end());
            sort(neg.begin(), neg.end());
            // for (size_t i = 0; i < pos.size(); ++i) {
            //    m -= neg.end() - lower_bound(neg.begin(), neg.end(), (t + pos[i] - 1) / pos[i]);
            // }
            a = neg.size();
            for (size_t i = 0; i < pos.size(); ++i) {
                while (a > 0 && neg[a - 1] * pos[i] >= t) {
                    --a;
                }
                m -= 2 * (neg.size() - a);
            }
        } else {
            m = pos.size() * pos.size() + neg.size() * neg.size();
        }
        g = gcd(m, n * n);
        printf("Case %d: %d/%d\n", ++ri, m / g, n * n / g);
    }

    return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727377  	2011-01-29 12:51:54 	Accepted	0.268	728	26909	C++	4269 - A Simple Game

/*
id => 1174037
pid => 4269
pname => A Simple Game
status => Accepted
lang => C++
time => 0.099
date => 2012-12-14 17:13:36
*/
