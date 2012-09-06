#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool IsValid(const string& str)
{
    return str == "0" || str[0] != '0';
}

bool LT(const string& lhs, const string& rhs)
{
    if(lhs.length() == rhs.length())
        return lhs < rhs;
    else
        return lhs.length() < rhs.length();
}

string input, base, tmp;
long long dp[108];

int main(void)
{
    int l, n;
    long long ans;

    while(cin >> input) {
        if(input == "#")
            break;
        ans = 0;
        l = (int)input.length();
        // '0*' spj
        if(input[0] == '0') {
            if(l > 1 && input[1] != '0')
                ans = 1;
            goto OUTPUT;
        }
        for (int i = 1; i < l; i++) {
            base = input.substr(l - i, i);
            if(!IsValid(base))
                continue;
            n = l - i;
            fill(dp + 1, dp + n + 1, 0);
            dp[0] = 1;
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= i && k <= j; k++) {
                    tmp = input.substr(j - k, k);
                    if(IsValid(tmp) && LT(tmp, base))
                        dp[j] += dp[j - k];
                }
            ans += dp[n];
        }
OUTPUT:
        cout << "The code " << input;
        if(ans == 0)
            cout << " is invalid." << endl;
        else
            cout << " can represent " << ans << " numbers." << endl;
    }

    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2869145   2008-04-25 19:55:05     Accepted    2159    C++     00:00.23    852K    Re:ReJudge
//
//2 WA, AC

// 2012-09-07 01:14:24 | Accepted | 2159 | C++ | 110 | 188 | watashi | Source
