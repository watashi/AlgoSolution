#include <cstdio>

struct TIME_T
{
    int hh, mm, ss;
    void read()
    {
        scanf("%d:%d:%d", &hh, &mm, &ss);
    }
    void next_second()
    {
        ++ss;
        if (ss == 60) {
            ss = 0;
            ++mm;
            if (mm == 60) {
                mm = 0;
                ++hh;
            }
        }
    }
    void next_day()
    {
        hh += 24;
    }
    bool operator<(const TIME_T& rhs) const
    {
        if (hh != rhs.hh) {
            return hh < rhs.hh;
        }
        else if(mm != rhs.mm) {
            return mm < rhs.mm;
        }
        else {
            return ss < rhs.ss;
        }
    }
    int count() const
    {
        int t = (hh * 100 + mm) % 3;

        if (t != 0) {
            t = 3 - t;
        }

        return (hh * 60 + mm) * 20 + (ss - t + 2) / 3;
    }
};

int main(void)
{
    int re;
    TIME_T s, t;

    scanf("%d", &re);
    while (re--) {
        s.read();
        t.read();
        if (!(s < t)) {
            t.next_day();
        }
        t.next_second();
        printf("%d\n", t.count() - s.count());
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1750156   2009-01-28 14:49:43     Accepted    3131    C++     10  176     watashi@Zodiac

// 2012-09-07 02:02:33 | Accepted | 3131 | C++ | 0 | 180 | watashi | Source
