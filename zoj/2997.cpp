/*
#include <cstdio>

int lcm(int a, int b)
{
    int ret = a * b, c;

    while (b != 0) {
        c = a;
        a = b;
        b = c % b;
    }

    return ret / a;
}

bool gao(int n, int p, int q, int ret[])
{
    int a, b, d;
    static bool m[5005];
    static int s[5005], sp;

    for (int i = 0; i <= n; i++) {
        ret[i] = 0;
        s[i] = i;
        m[i] = true;
    }
    sp = n;
    // SPFA
    while (sp >= 0) {
        a = s[sp--];
        m[a] = false;
        // s[i] - s[i - p] >= 1
        b = a - p;
        if (b >= 0) {
            d = ret[a] - 1;
            if (d < -n) {
                return false;
            }
            if (d < ret[b]) {
                ret[b] = d;
                if (!m[b]) {
                    s[++sp] = b;
                    m[b] = true;
                }
            }
        }
        // s[i + q] - s[i] <= -1
        b = a + q;
        if (b <= n) {
            d = ret[a] - 1;
            if (d < -n) {
                return false;
            }
            if (d < ret[b]) {
                ret[b] = d;
                if (!m[b]) {
                    s[++sp] = b;
                    m[b] = true;
                }
            }
        }
    }

    return true;
}

int main(void)
{
    int n, p, q;
    static int s[5005];

    while (scanf("%d%d%d", &n, &p, &q) != EOF) {
        if (lcm(p, q) > n && gao(n, p, q, s)) {
            puts("YES");
            for (int i = 1; i <= n; i++) {
                printf("%d%c", s[i] - s[i - 1], (i == n) ? '\n' : ' ');
            }
        }
        else {
            puts("NO");
        }
    }

    return 0;
}
*/

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3027912 2008-08-08 16:22:15 Accepted 2997 C++ 00:00.09 436K Re:ReJudge
//

// 因为边长都是-1的，所以可以用拓扑排序来做，而不是用差分约束

#include <cstdio>

int lcm(int a, int b)
{
    int ret = a * b, c;

    while (b != 0) {
        c = a;
        a = b;
        b = c % b;
    }

    return ret / a;
}

bool gao(int n, int p, int q, int s[])
{
    int a, b, d;
    static int c[5005], qp, qh, qt, qq[5005];

    qt = 0;
    for (int i = 0; i <= n; i++) {
        c[i] = (i + p <= n) + (i - q >= 0);
        if (c[i] == 0) {
            qq[qt++] = i;
        }
    }
    qp = 0;
    d = 0;
    while (qp < qt) {
        qh = qt;
        while (qp < qh) {
            a = qq[qp++];
            s[a] = d;
            if ((b = a - p) >= 0) {
                if (--c[b] == 0) {
                    qq[qt++] = b;
                }
            }
            if ((b = a + q) <= n) {
                if (--c[b] == 0) {
                    qq[qt++] = b;
                }
            }
        }
        --d;
    }

    return qt == n + 1;
}

int main(void)
{
    int n, p, q;
    static int s[5005];

    while (scanf("%d%d%d", &n, &p, &q) != EOF) {
        if (lcm(p, q) > n && gao(n, p, q, s)) {
            puts("YES");
            for (int i = 1; i <= n; i++) {
                printf("%d%c", s[i] - s[i - 1], (i == n) ? '\n' : ' ');
            }
        }
        else {
            puts("NO");
        }
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3027974 2008-08-08 16:59:38 Accepted 2997 C++ 00:00.06 452K Re:ReJudge
//

/*
// [quote]
#include<iostream>
using namespace std;
int const Maxn=5000+3;
int d[Maxn],s[Maxn];
int n,p,q;
bool get=0;
int solve()
{
int i,can=1,k=0;
for (i=0;i<=n;i++) d[i]=0;
for (i=0;i<=n;i++)
if (i+p<=n) d[i+p]++;
for (i=0;i<=n;i++)    //计算入度
if (i+q<=n) d[i]++;
while (can)
{
   can=0;
   for (i=0;i<=n;i++)
   if (d[i]==0)
   {
    can=1;
    s[i]=k++;
    if (i+p<=n) d[i+p]--;
    if (i-q>=0) d[i-q]--;// 删边
    d[i]=-1;// 标记已经解决
   }
}
if (k>n ) get=1;
else get=0;
return 0;
}
int main()
{

while (scanf("%d%d%d",&n,&p,&q)!=EOF)
{
   get=0;
   solve();
   if (get)
   {
    printf("YES\n");
    for (int i=1;i<=n;i++)
    {
     if (i>1) printf(" ");
     printf("%d",s[i]-s[i-1]);
    }
    printf("\n");
   }
   else printf("NO\n");
}
return 0;
}

// 这是用拓扑排序作的， 还有一种是用差分约束系统作的
// 其实这题也是ioi94的原题


// [/quote]
*/

// 2012-09-07 01:53:34 | Accepted | 2997 | C++ | 20 | 240 | watashi | Source
