/*
Pairs of Integers
Time limit 1 Seconds   Memory limit 32768K
Total Submit 279   Accepted Submit 96

You are to find all pairs of integers such that their sum is equal to the given integer number N and the second number results from the first one by striking out one of its digits. The first integer always has at least two digits and starts with a non-zero digit. The second integer always has one digit less than the first integer and may start with a zero digit.


Input

The input file consists of a single integer N (10 = N = 10^9).


Output

On the first line of the output file write the total number of different pairs of integers that satisfy the problem statement. On the following lines write all those pairs. Write one pair on a line in ascending order of the first integer in the pair. Each pair must be written in the following format

X + Y = N

Here X, Y, and N, must be replaced with the corresponding integer numbers. There should be exactly one space on both sides of '+' and '=' characters.


This problem contains multiple test cases!

The first line of a multiple input is an integer N, then a blank line followed by N input blocks. Each input block is in the format indicated in the problem description. There is a blank line between input blocks.

The output format consists of N output blocks. There is a blank line between output blocks.


Sample Input

1

302


Sample Output

5
251 + 51 = 302
275 + 27 = 302
276 + 26 = 302
281 + 21 = 302
301 + 01 = 302
Problem Source Northeastern Europe 2001

*/
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

class ANS
{
    private:
        int x;
        string y;
    public:
        ANS(const int x, const int a, const int b, const int w) : x(x)
        {
            ostringstream oss;

            if(a != 0)
                oss << a;
            if(w != 0)
                oss << setw(w) << setfill('0') << b;
            y = oss.str();
        }
        bool operator<(const ANS& rhs) const
        {
            return x < rhs.x;
        }
        bool operator==(const ANS& rhs) const
        {
            return x == rhs.x;
        }
        friend ostream& operator<<(ostream& os, const ANS& ans)
        {
            os << ans.x << " + " << ans.y << " = ";

            return os;
        }
};

int main(void)
{
    int re, n, a, b, c, t, l;
    vector<ANS> ans;

    cin >> re;
    while(re--) {
        cin >> n;
        ans.clear();
        b = n % 11;
        if(b < 10) {
            a = n / 11;
            ans.push_back(ANS(a * 10 + b, a, 0, 0));
        }
        if((n & 1) == 0) {
            t = 10;
            l = 1;
            while(t <= n) {
                b = (n % t) >> 1;
                a = n / t;
                c = a % 11;
                if(c < 10) {
                    a /= 11;
                    ans.push_back(ANS((a * 10 + c) * t + b, a, b, l));
                }
                b = (n % t + t) >> 1;
                a = n / t - 1;
                c = a % 11;
                if(a > 0 && c < 10) {
                    a /= 11;
                    ans.push_back(ANS((a * 10 + c) * t + b, a, b, l));
                }
                ++l;
                t *= 10;
            }
        }
        sort(ans.begin(), ans.end());
        //try 12
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        //
        cout << ans.size() << endl;
        for (size_t i = 0; i < ans.size(); i++)
            cout << ans[i] << n << endl;
        if(re)
            cout << endl;
    }

    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2868970   2008-04-25 19:02:45     Accepted    1469    C++     00:00.00    880K    Re:ReJudge

// 2012-09-07 00:50:03 | Accepted | 1469 | C++ | 0 | 188 | watashi | Source
