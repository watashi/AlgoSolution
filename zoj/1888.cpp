#include <cctype>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

void ToLower(string& str)
{
    for (size_t i = 0; i < str.length(); i++)
        str[i] = tolower(str[i]);
}

char buf[128];
string v[12321];

int main(void)
{
    int i, n, m;
    bool blank = false, flag;

    while(scanf("%d%*[^A-Za-z]", &n) != EOF) {
        m = 0;
        while(scanf("%[A-Za-z]", buf) != EOF) {
            v[m] = buf;
            ToLower(v[m]);
            if(v[m] == "endoftext")
                break;
            else
                ++m;
            scanf("%*[^A-Za-z]");
        }
        v[m] = v[m + 1] = "";
        sort(v, v + m + 1);

        if(blank)
            putchar('\n');
        else
            blank = true;
        flag = false;
        i = n;
        while(i <= m) {
            if(v[i] == v[i - n + 1]) {
                if(v[i] != v[i - n] && v[i] != v[i + 1]) {
                    printf("%s\n", v[i].c_str());
                    flag = true;
                }
                i += n;
            }
            else
                ++i;
        }
        if(!flag)
            puts("There is no such word.");
    }

    return 0;
}

//2841431   2008-04-13 13:11:43     Accepted    1888    C++     00:00.23    2032K   Re:ReJudge

// 2012-09-07 01:04:36 | Accepted | 1888 | C++ | 70 | 624 | watashi | Source
