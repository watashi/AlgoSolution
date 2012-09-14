#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <cassert>

using namespace std;

int main() {
    char const * const sign[] = {
        "Rat",      "Ox",       "Tiger",    "Rabbit",
        "Dragon",   "Snake",    "Horse",    "Ram",
        "Monkey",   "Rooster",  "Dog",      "Pig"};
    int re, age;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        assert(scanf("%d", &age) == 1);
        assert(1 <= age && age <= 200);
        puts(sign[(604 - age) % 12]);
    }
    assert(scanf("%d", &age) == EOF);

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//212   2011-04-03 01:07:25     Accepted    C   C++     10  180     watashi     Source

// 2012-09-07 16:50:50 | Accepted | 3479 | C++ | 0 | 180 | watashi | Source
