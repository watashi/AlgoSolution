#include <cctype>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int w, h;
char mp[70][77];
string dp[70][70], ans;

inline bool pr(const string& lhs, const string& rhs)
{
    if(lhs.length() == rhs.length()) return lhs < rhs;
    else return lhs.length() < rhs.length();
}

int main(void)
{
    while(scanf("%d%d", &w, &h) != EOF && w + h > 0) {
        ans = "";
        for (int i = 0; i < h; i++)
            scanf("%s", mp[i]);
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++) {
                if(!isdigit(mp[i][j])) dp[i][j] = "";
                else if(mp[i][j] == '0') {
                    if(ans == "") ans = "0";
                    dp[i][j] = "";
                    if(i && dp[i - 1][j] != "") dp[i][j] = max(dp[i][j], dp[i - 1][j] + '0', pr);
                    if(j && dp[i][j - 1] != "") dp[i][j] = max(dp[i][j], dp[i][j - 1] + '0', pr);
                    ans = max(ans, dp[i][j], pr);
                }
                else {
                    dp[i][j] = mp[i][j];
                    if(i) dp[i][j] = max(dp[i][j], dp[i - 1][j] + mp[i][j], pr);
                    if(j) dp[i][j] = max(dp[i][j], dp[i][j - 1] + mp[i][j], pr);
                    ans = max(ans, dp[i][j], pr);
                }
            }
        puts(ans.c_str());
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2746281 2008-02-07 22:51:32 Accepted 1717 C++ 00:00.02 948K ¤ï¤¿¤·

// 2012-09-07 00:58:48 | Accepted | 1717 | C++ | 20 | 204 | watashi | Source
