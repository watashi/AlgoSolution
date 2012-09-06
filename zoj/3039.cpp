#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct FLOAT
{
    public:
        FLOAT(const char p[])
        {
            for (int i = 0; i < 32; i++) {
                s[i] = p[31 - i];
            }
        }
        /*double operator()() const
        {
            unsigned int x = 0;

            for (int i = 0; i < 32; i++) {
                if (s[i] == '1') {
                    x |= (1U << i);
                }
            }
//          printf("%x\n", x);

            return (double)*reinterpret_cast<float*>(&x);
        }*/
        double operator[](int) const
        {
            double ret = 0;
            double p = pow(2, -23);
            for (int i = 0; i < 23; i++) {
                if (s[i] == '1') {
                    ret += p;
                }
                p *= 2;
            }
            ret += p;
            int e = 0;
            for (int i = 23; i < 31; i++) {
                if (s[i] == '1') {
                    e |= (1 << (i - 23));
                }
            }
            ret *= pow(2, e - 127);
            if (s[31] == '1') ret = -ret;

            return ret;
        }
        void doit(int k)
        {
            if (isNaN()) {
                if (k == 1 && s[31] == '0') {
                    s[30] = '0';
                }
                else {
                    s[23] = '0';
                }
                --k;
            }
            if (s[31] == '0' && k > 0) {
                s[31] = '1';
                --k;
            }
            checkE(k);
            for (int i = 22; i >= 0 && k > 0; i--) {
                if (s[i] == '0') {
                    s[i] = '1';
                    --k;
                }
            }
        }
    private:
        char s[36];
        bool isNaN()
        {
            for (int i = 23; i < 31; i++) {
                if (s[i] != '1') {
                    return false;
                }
            }
            return true;
        }
        void checkE(int& k)
        {
            int c;

            c = 0;
            for (int i = 23; i < 31; i++) {
                if (s[i] == '0') {
                    ++c;
                }
            }
            for (int i = 30; i >= 23 && c > 1 && k > 0; --i) {
                if (s[i] == '0') {
                    s[i] = '1';
                    --c;
                    --k;
                }
            }
            if (c == 1 && k >= 2 && s[23] != '0') {
                for (int i = 30; i > 23; i--) {
                    if (s[i] == '0') {
                        s[i] = '1';
                        s[23] = '0';
                        --c;
                        k -= 2;
                        break;
                    }
                }
            }
        }
};

int main(void)
{
    static char buf[36];
    int k;
    int c = 0;

    while (scanf("%s%d", buf, &k) != EOF) {
        FLOAT f(buf);

        f.doit(k);

        printf("%.20le\n", f[0]);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1644800   2008-09-15 16:01:29     Accepted    3039    C++     50  260     watashi

// 2012-09-07 01:57:32 | Accepted | 3039 | C++ | 50 | 180 | watashi | Source
