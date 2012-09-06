#include <cmath>
#include <cstdio>

class Light
{
private:
    static const double eps;
    double L;
    int G, S;
public:
    inline void cget();
    inline bool pass(double);
};

const double Light::eps = 1e-8;

inline void Light::cget()
{
    int Y, R;

    scanf("%lf%d%d%d", &L, &G, &Y, &R);
    G = G + Y;
    S = G + R;
}

inline bool Light::pass(double speed)
{
    double x = fmod(L / speed, S);

    return x < G + eps || x > S - eps;
}

Light lights[6];
bool mark[66];

int main(void)
{
    bool flag;
    int ri = 0, f, t, n;
    double speed;

    while(scanf("%d", &n) != EOF && n > 0) {
        for (int i = 0; i < n; i++)
            lights[i].cget();
        for (int i = 30; i <= 60; i++) {
            mark[i] = true;
            speed = i / 3600.0;
            for (int j = 0; j < n; j++)
                if(!lights[j].pass(speed)) {
                    mark[i] = false;
                    break;
                }
        }
        printf("Case %d:", ++ri);
        flag = false;
        t = 30;
        while(t <= 60) {
            if(!mark[t]) {
                ++t;
                continue;
            }
            f = t;
            while(++t <= 60 && mark[t]);
            if(flag) putchar(',');
            else flag = true;
            if(t == f + 1) printf(" %d", f);
            else printf(" %d-%d", f, t - 1);
        }
        if(!flag) printf(" No acceptable speeds.");
        putchar('\n');
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2770550 2008-03-04 23:04:35 Accepted 1270 C++ 00:00.00 392K ¤ï¤¿¤·

// 2012-09-07 00:43:45 | Accepted | 1270 | C++ | 0 | 180 | watashi | Source
