#include <cstdio>
#include <cstring>

void kmp(int l, const char buf[], int ll, const char pat[], int ret[])
{
    static int f[512];
    int t;

    f[0] = -1;
    for (int i = 1; i <= ll; i++) {
        f[i] = f[i - 1];
        while(f[i] != -1 && pat[i] != pat[f[i] + 1])
            f[i] = f[f[i]];
        if(pat[i] == pat[f[i] + 1])
            ++f[i];
    }
    t = 0;
    for (int i = 0; i <= l; i++) {
        if(t == ll) {
            ret[i - ll] = 1;
        }
        if(buf[i] == pat[t]) {
            t++;
        }
        else if(t) {
            t = f[t - 1] + 1;
            --i;
        }
    }
}

char buf[1024], pat[1024];
int mark[1024];

int main(void)
{
    char ch;
    int l, ll, ans;

    while(gets(buf) != NULL) {
        l = (int)strlen(buf);
        gets(pat);
        ll = (int)strlen(pat);
        strncpy(pat + ll, pat, ll);
        memset(mark, 0, l * sizeof(int));
        for (int i = ll - 1; i >= 0; --i) {
            pat[i + ll] = '#';
            kmp(l, buf, ll, pat + i, mark);
        }
        ans = 0;
        for (int i = 0; i < l; i++)
            if(mark[i])
                ++ans;
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2918826 2008-05-16 21:52:50 Accepted 2737 C++ 00:00.00 400K Re:ReJudge

// 2012-09-07 01:37:06 | Accepted | 2737 | C++ | 0 | 188 | watashi | Source
