#include <cstdio> // auto fix CE
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

string buf[16];
int cnt[10];

int main(void)
{
    int re;
    scanf("%d", &re);
    while(re--) {
        while(cin >> buf[0] && buf[0] != "-1") {
            for (int i = 0; i < 15; i++) {
                for (int j = 0; j < 10; j++)
                    cnt[j] = 0;
                for (int j = 0; j < buf[i].length(); j++)
                    ++cnt[buf[i][j] - '0'];
                ostringstream os;
                for (int j = 0; j < 10; j++)
                    if(cnt[j] != 0) os << cnt[j] << j;
                buf[i + 1] = os.str();
                if(buf[i + 1] == buf[i]) {
                    if(i == 0) cout << buf[0] << " is self-inventorying" << endl;
                    else cout << buf[0] << " is self-inventorying after " << i << " steps" << endl;
                    break;
                }
                for (int j = 0; j < i; j++)
                    if(buf[i + 1] == buf[j]) {
                        cout << buf[0] << " enters an inventory loop of length " << i - j + 1 << endl;
                        i = 15;
                        break;
                    }
                if(i == 14) {
                    cout << buf[0] << " can not be classified after 15 iterations" << endl;
                    break;
                }
            }
        }
        if(re) printf("\n");
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2746314 2008-02-07 23:36:39 Accepted 1189 C++ 00:00.48 880K ¤ï¤¿¤·

// 2012-09-07 13:35:01 | Accepted | 1189 | C++ | 100 | 188 | watashi | Source
