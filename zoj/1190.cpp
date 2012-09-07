#include <cstdlib> // auto fix CE
#include <cstdio>
#include <vector>
using namespace std;

int cnt, len;
vector<int> cur;
vector<vector<int> > programs[11];

void _gen_programs(int lv)
{
    if(2 * cnt < lv)
        return;
    if(lv == len) {
        if(2 * cnt == len)
            programs[len].push_back(cur);
        return;
    }
    for (int i = 0; i <= 4; i++) {
        if(i == 2)
            ++cnt;
        cur[lv] = i;
        _gen_programs(lv + 1);
        if(i == 2)
            --cnt;
    }
}

void gen_programs()
{
    for (int i = 0; i <= 10; i += 2) {
        len = i;
        cur.resize(i);
        cnt = 0;
        _gen_programs(0);
    }
}

bool check(const vector<int>& prog, const int src, const int tar)
{
    static int h, s[10];

    h = 1;
    s[0] = src;
    for (size_t i = 0; i < prog.size(); i++)
        switch(prog[i]) {
            case 2:
                s[h] = s[h - 1];
                ++h;
                break;
            case 0:
                --h;
                if(abs(s[h - 1] += s[h]) > 30000)
                   return false;
                break;
            case 4:
                --h;
                if(abs(s[h - 1] -= s[h]) > 30000)
                    return false;
                break;
            case 3:
                --h;
                if(abs(s[h - 1] *= s[h]) > 30000)
                    return false;
                break;
            case 1:
                --h;
                if(s[h] == 0)
                    return false;
                s[h - 1] /= s[h];
                break;
        }
    return s[0] == tar;
}

int n, src[11], tar[11];

int main(void)
{
    int ri = 0;
    int ans, pid;

    gen_programs();
    while(scanf("%d", &n) != EOF && n > 0) {
        for (int i = 0; i < n; i++)
            scanf("%d", &src[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &tar[i]);
        ans = pid = -1;
        for (int i = 0; i <= 10 && ans == -1; i++)
            for (size_t j = 0; j < programs[i].size(); j++) {
                bool flag = true;
                for (int k = 0; k < n; k++)
                    if(!check(programs[i][j], src[k], tar[k]))
                        flag = false;
                if(flag) {
                    ans = i;
                    pid = j;
                    break;
                }
            }
        printf("Program %d\n", ++ri);
        if(ans == -1)
            printf("Impossible\n");
        else if(ans == 0)
            printf("Empty sequence\n");
        else {
            for (int i = 0; i < ans; i++) {
                switch(programs[ans][pid][i]) {
                    case 2:
                        printf("DUP");
                        break;
                    case 0:
                        printf("ADD");
                        break;
                    case 4:
                        printf("SUB");
                        break;
                    case 3:
                        printf("MUL");
                        break;
                    case 1:
                        printf("DIV");
                        break;
                }
                putchar((i == ans - 1) ? '\n' : ' ');
            }
        }
        printf("\n");
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2835753   2008-04-10 15:33:10     Accepted    1190    C++     00:00.56    4188K   わたし
//2835752   2008-04-10 15:32:52     Accepted    1190    C++     00:00.57    3784K   わたし

// 2012-09-07 13:35:07 | Accepted | 1190 | C++ | 190 | 4536 | watashi | Source
