#include <map>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

#define VALUE(i) make_pair(pstr[i], i)

const char *const pstr[12] = {
    "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"
};
const map<string, int>::value_type mps[12] = {
    VALUE(0), VALUE(1), VALUE(2), VALUE(3), VALUE(4), VALUE(5),
    VALUE(6), VALUE(7), VALUE(8), VALUE(9), VALUE(10), VALUE(11)
};
const map<string, int> mp(mps, mps + 12);

const int bin[12] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
const int off[8] = {0, 2, 4, 5, 7, 9, 11, 12};
int mask[12];

void init()
{
    for (int i = 0; i < 12; i++) {
        mask[i] = 0;
        for (int j = 0; j < 8; j++)
            mask[i] |= bin[(i + off[j]) % 12];
    }
}

int main(void)
{
    bool blank;
    string buf;

    init();
    while(getline(cin, buf) && buf != "END") {
        istringstream iss(buf);
        int s = 0;

        while(iss >> buf)
            s |= bin[mp.find(buf)->second];
        blank = false;
        for (int i = 0; i < 12; i++) {
            if((mask[i] | s) == mask[i]) {
                if(blank)
                    cout << " ";
                else
                    blank = true;
                cout << pstr[i];
            }
        }
        cout << endl;
    }

    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2874447   2008-04-27 16:16:25     Accepted    1924    C++     00:00.03    888K    Re:ReJudge

// 2012-09-07 01:06:44 | Accepted | 1924 | C++ | 50 | 188 | watashi | Source
