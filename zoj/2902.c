#include <stdio.h>
#define isin(x, y) (x >= 0 && y >= 0 && x < n && y < n)
int mp[20][20];
int q[4][500][2];
const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int head[4], rear[4], tail[4];
int n, m, k, p;
void doit()
{
    int x, y, z;
    int i, j;

    do {
        z = 0;
        for (i = 0; i < 4; i++)
            rear[i] = tail[i];
        for (i = 0; i < 4; i++) {
            if(head[i] >= rear[i]) {
                z++;
                continue;
            }
            while(head[i] < rear[i]) {
                x = q[i][head[i]][0] + dir[i][0];
                y = q[i][head[i]][1] + dir[i][1];
                if(isin(x, y)){
                    if(mp[x][y] == 0) {
                        q[i][tail[i]][0] = x;
                        q[i][tail[i]][1] = y;
                        tail[i]++;
                    }
                    else {
                        mp[x][y]++;
                        if(mp[x][y] == k) {
                            mp[x][y] = 0;
                            for (j = 0; j < 4; j++){
                                q[j][tail[j]][0] = x;
                                q[j][tail[j]][1] = y;
                                tail[j]++;
                            }
                        }
                    }
                }
                head[i]++;
            }
        }
    }while(z < 4);
}
int main()
{
    int i, j, blank = 0;

    while(scanf("%d%d%d%d ", &n, &m, &k, &p) != EOF) {
        if(blank) putchar('\n');
        else blank = 1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                mp[i][j] = getchar() - '0';
            getchar();
        }
        while(p--) {
            scanf("%d%d", &i, &j);
            if(m == 0) continue;
            if(mp[i][j] == 0) continue;
            m--;
            mp[i][j]++;
            if(mp[i][j] < k) continue;
            mp[i][j] = 0;
            head[0] = head[1] = head[2] = head[3] = 0;
            tail[0] = tail[1] = tail[2] = tail[3] = 1;
            q[0][0][0] = q[1][0][0] = q[2][0][0] = q[3][0][0] = i;
            q[0][0][1] = q[1][0][1] = q[2][0][1] = q[3][0][1] = j;
            doit();
        }
        printf("%d\n", m);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                putchar(mp[i][j] + '0');
            putchar('\n');
        }
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2735593 2008-01-27 17:54:27 Accepted 2902 C 00:00.01 416K ¤ï¤¿¤· */

// 2012-09-07 03:15:03 | Accepted | 2902 | C | 0 | 176 | watashi | Source
