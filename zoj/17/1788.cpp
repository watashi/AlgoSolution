#include <cstdio>
#include <string>
using namespace std;

char tohex(const string& str)
{
    int ret = 0;

    for (int i = 0; i < 4; i++) {
        ret <<= 1;
        if(str[i] == '1')
            ++ret;
    }

    return (ret < 10) ? '0' + ret : 'A' + ret - 10;
}

string ToHex(const string& str)
{
    string tmp = str;
    string ret = "";

    while(tmp.length() % 4 != 0)
        tmp = "0" + tmp;
    for (size_t i = 0; i < tmp.length(); i += 4)
        ret += tohex(tmp.substr(i, 4));

    return ret;
}

char mp[512][512];
string ans[10];

string ToString(int x, int y, int n, int l)
{
    char all;
    string tmp, ret;

    if(n == 1)
        return mp[x][y] == '1' ? "01" : "00";
    n /= 2;
    ret = ToString(x, y, n, l + 1);
    if(ret[0] == '0')
        all = ret[1];
    else
        all = '*';
    ret.append(tmp = ToString(x, y + n, n, l + 1));
    if(tmp[0] != '0' || tmp[1] != all)
        all = '*';
    ret.append(tmp = ToString(x + n, y, n, l + 1));
    if(tmp[0] != '0' || tmp[1] != all)
        all = '*';
    ret.append(tmp = ToString(x + n, y + n, n, l + 1));
    if(tmp[0] != '0' || tmp[1] != all)
        all = '*';
    if(all != '*')
        return all == '1' ? "01" : "00";
    else {
        ans[l + 1].append(ret);
        return "1";
    }
}

int main(void)
{
    int re, n, l;

    scanf("%d", &re);
    while(re--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf(" %c", &mp[i][j]);
        l = 0;
        for (int i = 1; i <= n; i <<= 1)
            ans[l++] = "";
        ans[0] = ToString(0, 0, n, 0);
        l = 1;
        for (int i = 2; i <= n; i <<= 1)
            ans[0].append(ans[l++]);
        printf("%s\n", ToHex(ans[0]).c_str());
    }

    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2844279   2008-04-14 21:26:37     Accepted    1788    C++     00:00.33    1100K   Re:ReJudge

// 2012-09-07 01:00:50 | Accepted | 1788 | C++ | 120 | 436 | watashi | Source
