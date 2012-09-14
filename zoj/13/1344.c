/* //Of course you must not move into the wall, neither must you walk right into Fatdog, */
/* //*and you must not fall into Fatdog's sightline as well.* */

#include <stdio.h>
#include <string.h>
typedef struct{
    int x;
    int y;
}Pos;
typedef struct{
    int x;
    int y;
    int z;
}Status;

const Pos dir[5] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {0, 0}};

int mind[51][51][50];
int p, t;
Status q[50 * 50 * 50];
int n, m;
Pos b, e;
char mp[50][52][52];
int d, l;
Pos pos[50];
char act[51];

int main()
{
    int x, y, z, i, j, k, ri, loop;

    ri = 0;
    memset(mp, '*', sizeof(mp));
    while(scanf("%d%d", &n, &m) != EOF && (n || m)) {
        if(ri) printf("\n");

        scanf("%d%d", &b.x, &b.y);
        scanf("%d%d", &e.x, &e.y);
        scanf("%d%d", &pos[0].x, &pos[0].y);

        scanf("%d", &l);
        scanf("%s", act);

        for (i = 1; i <= n; i++)
            scanf("%s", mp[0][i] + 1);
        memcpy(mp[0][n + 1], mp[0][0], m + 2);
        for (k = 1; k < l; k++)
            for (i = 0; i <= n + 1; i++)
                memcpy(mp[k][i], mp[0][i], m + 2);
        memset(mind, 0xff, sizeof(mind));

        d = 0;
        for (i = 0; i < l; i++) {
            x = pos[i].x;
            y = pos[i].y;
            while(mp[i][x][y] == '.') {
                mp[i][x][y] = '*';
                x += dir[d].x;
                y += dir[d].y;
            };
            if(act[i] == 'G') {
                pos[i + 1].x = pos[i].x + dir[d].x;
                pos[i + 1].y = pos[i].y + dir[d].y;
            } else {
                pos[i + 1] = pos[i];
                if(act[i] == 'R') d = (d + 1) % 4;
                else d = (d + 3) % 4;
            }
        }

        printf("Case %d:\n", ++ri);

        p = 0;
        q[0].x = b.x;
        q[0].y = b.y;
        q[0].z = 0;
        mind[q[0].x][q[0].y][q[0].z] = 0;
        t = 1;
        while(p < t) {
            x = q[p].x;
            y = q[p].y;
            z = q[p].z;
            k = (z + 1) % l;
            for (loop = 0; loop < 5; loop++) {
                i = x + dir[loop].x;
                j = y + dir[loop].y;
                if(/*i && j && i <= n && j <= m && */mp[k][i][j] == '.' && mind[i][j][k] == -1) {
                    mind[i][j][k] = mind[x][y][z] + 1;
                    q[t].x = i;
                    q[t].y = j;
                    q[t].z = k;
                    t++;
                    if(i == e.x && j == e.y){
                        printf("Minimal time is: %d\n", mind[i][j][k]);
                        goto A;
                    }
                }
            }
            p++;
        }
        printf("No way out\n");
        continue;
A:
        ;
    }
}
/* //Run ID     Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name */
/* //2716119    2007-12-29 18:50:52     Accepted    1344    C   00:00.02    2504K   ¤ï¤¿¤· */

// 2012-09-07 00:46:36 | Accepted | 1344 | C | 0 | 2264 | watashi | Source
