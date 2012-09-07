#include <cstdio> // auto fix CE
#include <stdio.h>
#define FREOPEN() freopen("showinput.php", "r", stdin),freopen("test.out", "w", stdout)
#define MAXN 10001
char str[MAXN << 1];
int n;
int pre[MAXN];
int cnt[MAXN];
int h[MAXN];
int h0, h1, h2;
int main()
{
    int ri, i, cur;

    /*FREOPEN();*/
    ri = 0;
    while(gets(str) && str[0] != '#') {
        n = cnt[0] = h[0] = 0;
        h0 = h1 = h2 = 0;
        cur = 0;
        for (i = 0; str[i]; i++) {
            if(str[i] == 'd') {
                h0++;
                if(h0 > h1) h1 = h0;
                n++;
                cnt[cur]++;
                pre[n] = cur;
                cnt[n] = 0;
                h[n] = h[cur] + cnt[cur];
                if(h[n] > h2) h2 = h[n];
                cur = n;
            } else {
                h0--;
                cur = pre[cur];
            }
        }
        printf("Tree %d: %d => %d\n", ++ri, h1, h2);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2719343 2008-01-04 14:44:32 Accepted 2885 C++ 00:00.08 528K わたし
//2719342 2008-01-04 14:44:20 Accepted 2885 C++ 00:00.09 528K わたし

/*
#include <cstdio> // auto fix CE
#include <stdio.h>
int calc_height(int level, int *height1)
{
  int c, n, t;
  int height = 0;

  if (level > *height1) {
    *height1 = level;
  }

  for (n = 0; (c = getchar()) == 'd'; n++) {
    if ((t = calc_height(level+1, height1) + n+1) > height) {
      height = t;
    }
  }

  return height;
}

int main(void)
{
  int c, height1, height2, num = 1;
  while ((c = getchar()) != '#') {
    ungetc(c, stdin);
    height1 = 0;
    height2 = calc_height(0, &height1);
    printf("Tree %d: %d => %d\n", num++, height1, height2);
  }

  return 0;
}
*/

// 2012-09-07 14:11:22 | Accepted | 2885 | C++ | 50 | 316 | watashi | Source
