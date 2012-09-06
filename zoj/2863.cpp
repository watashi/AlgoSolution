// ¶þ·ÖÍ¼

#include <list>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> xp[250];
list<int> xe[250];
int x, y, x2y[250], y2x[250];
int mp[20][20];
int doit, next, mark[250], temp[250];

void dfs(int id)
{
    if(doit != -1) return;
    for (list<int>::iterator itr = xe[id].begin(); itr != xe[id].end(); ++itr) {
        int yy = *itr;
        if(mark[yy] == -1) {
            mark[yy] = 1;
            temp[yy] = id;
            if(y2x[yy] == -1) {
                doit = yy;
                break;
            }
            else dfs(y2x[yy]);
        }
    }
}

int main()
{
    int re;
    scanf("%d", &re);
    for (int ri = 1; ri <= re; ri++) {
        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 15; j++)
                scanf("%d", &mp[i][j]);
        x = y = 0;
        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 15; j++) {
                if(mp[i][j] == 1) {
                    xp[x].first = i;
                    xp[x].second = j;
                    xe[x].clear();
                    if(j > 0 && mp[i][j - 1] != 0 && mp[i][j - 1] != 1) xe[x].push_front((mp[i][j - 1] >> 1) - 1);
                    if(j < 14 && mp[i][j + 1] != 0 && mp[i][j + 1] != 1) xe[x].push_front((mp[i][j + 1] >> 1) - 1);
                    if(i > 0) {
                        if(mp[i - 1][j] != 0 && mp[i - 1][j] != 1) xe[x].push_front((mp[i - 1][j] >> 1) - 1);
                        if(j > 0 && mp[i - 1][j - 1] != 0 && mp[i - 1][j - 1] != 1) xe[x].push_front((mp[i - 1][j - 1] >> 1) - 1);
                        if(j < 14 && mp[i - 1][j + 1] != 0 && mp[i - 1][j + 1] != 1) xe[x].push_front((mp[i - 1][j + 1] >> 1) - 1);
                    }
                    if(i < 14) {
                        if(mp[i + 1][j] != 0 && mp[i + 1][j] != 1) xe[x].push_front((mp[i + 1][j] >> 1) - 1);
                        if(j > 0 && mp[i + 1][j - 1] != 0 && mp[i + 1][j - 1] != 1) xe[x].push_front((mp[i + 1][j - 1] >> 1) - 1);
                        if(j < 14 && mp[i + 1][j + 1] != 0 && mp[i + 1][j + 1] != 1) xe[x].push_front((mp[i + 1][j + 1] >> 1) - 1);
                    }
                    x++;
                }
                else if(mp[i][j] != 0)
                    y = max(y, mp[i][j] >> 1);
            }
        printf("Round #%d:\n", ri);
        if(x != y && x != y + 1) {
            puts("No solution.\n");
            continue;
        }
        fill(x2y, x2y + x, -1);
        fill(y2x, y2x + y, -1);
        for (int i = 0; i < x; i++) {
            doit = -1;
            fill(mark, mark + y, -1);
            fill(temp, temp + y, -1);
            dfs(i);
            while(doit != -1) {
                y2x[doit] = temp[doit];
                next = x2y[temp[doit]];
                x2y[temp[doit]] = doit;
                doit = next;
            }
        }
        if(*min_element(y2x, y2x + y) == -1) {
            puts("No solution.\n");
            continue;
        }
        for (int i = 0; i < x; i++) {
            if(x2y[i] == -1) mp[xp[i].first][xp[i].second] = (y << 1) + 1;
            else mp[xp[i].first][xp[i].second] = (x2y[i] << 1) + 1;
        }
        for (int i = 0; i < 15; i++) {
            printf("%d", mp[i][0]);
            for (int j = 1; j < 15; j++)
                printf(" %d", mp[i][j]);
            putchar('\n');
        }
        putchar('\n');
    }
}

//2747426 2008-02-10 00:49:10 Accepted 2863 C++ 00:00.01 852K ¤ï¤¿¤·

// 2012-09-07 01:43:42 | Accepted | 2863 | C++ | 0 | 188 | watashi | Source
