#include <cstdio> // auto fix CE
#include <cmath>
#include <iostream>
using namespace std;

class Vector
{
    public:
        friend const double operator*(const Vector& lhs, const Vector& rhs)
        {
            return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
        }
        friend istream& operator>>(istream& is, Vector& v)
        {
            is >> v.x >> v.y >> v.z;

            return is;
        }
    private:
        double x, y, z;
};

template<typename T>
double sqr(const T &x)
{
    return x * x;
}

Vector s[100], t[100];

int main(void)
{
    int k, n, ans;
    double r;

    while(cin >> k >> n, k && n) {
        for (int i = 0; i < k; i++)
            cin >> s[i];
        for (int i = 0; i < n; i++)
            cin >> t[i];
        ans = 0;
        for (int i = 0; i < n; i++) {
            r = sqr(t[i]);
            for (int j = 0; j < k; j++) {
                if(s[j] * t[i] >= r) {
                    ++ans;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2873226   2008-04-27 09:23:02     Accepted    2544    C++     00:00.15    836K    Re:ReJudge

// 2012-09-07 13:36:22 | Accepted | 2544 | C++ | 10 | 192 | watashi | Source
