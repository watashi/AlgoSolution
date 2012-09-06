#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

struct Hand
{
    char suit;
    int value[5];
    pair <int, int> pii[13];
    bool isConsecutive() const
    {
        for (int i = 1; i < 5; i++)
            if(value[i] != value[0] - i) return false;
        return true;
    }
    int cmp(const Hand& that) const
    {
        if(suit != '#' && isConsecutive()) {
            if(that.suit != '#' && that.isConsecutive())
                return (value[0] == that.value[0]) ? 0 : ((value[0] > that.value[0]) ? 1 : -1);
            else return 1;
        }
        else if(that.suit != '#' && that.isConsecutive()) return -1;

        if(pii[0].first == 4) {
            if(that.pii[0].first == 4) return (pii[0].second > that.pii[0].second) ? 1 : -1;
            else return 1;
        }
        else if(that.pii[0].first == 4) return -1;

        if(pii[0].first == 3 && pii[1].first == 2) {
            if(that.pii[0].first == 3 && that.pii[1].first == 2) return (pii[0].second > that.pii[0].second) ? 1 : -1;
            else return 1;
        }
        else if(that.pii[0].first == 3 && that.pii[1].first == 2) return -1;

        if(suit != '#') {
            if(that.suit != '#') {
                for (int i = 0; i < 5; i++)
                    if(pii[i].second > that.pii[i].second) return 1;
                    else if(pii[i].second < that.pii[i].second) return -1;
            }
            else return 1;
        }
        else if(that.suit != '#') return -1;

        if(isConsecutive()) {
            if(that.isConsecutive())
                return (value[0] == that.value[0]) ? 0 : ((value[0] > that.value[0]) ? 1 : -1);
            else return 1;
        }
        else if(that.isConsecutive()) return -1;

        if(pii[0].first == 3) {
            if(that.pii[0].first == 3) return (pii[0].second > that.pii[0].second) ? 1 : -1;
            else return 1;
        }
        else if(that.pii[0].first == 3) return -1;

        if(pii[0].first == 2 && pii[1].first == 2) {
            if(that.pii[0].first == 2 && that.pii[1].first == 2) {
                for (int i = 0; i < 3; i++)
                    if(pii[i].second > that.pii[i].second) return 1;
                    else if(pii[i].second < that.pii[i].second) return -1;
                return 0;
            }
            else return 1;
        }
        else if(that.pii[0].first == 2 && that.pii[1].first == 2) return -1;

        if(pii[0].first == 2) {
            if(that.pii[0].first == 2) {
                for (int i = 0; i < 4; i++)
                    if(pii[i].second > that.pii[i].second) return 1;
                    else if(pii[i].second < that.pii[i].second) return -1;
                return 0;
            }
            else return 1;
        }
        else if(that.pii[0].first == 2) return -1;

        for (int i = 0; i < 5; i++)
            if(pii[i].second > that.pii[i].second) return 1;
            else if(pii[i].second < that.pii[i].second) return -1;
        return 0;
    }
};

Hand hand[2];
char buf[4];

int main(void)
{
    while(scanf("%s", buf) != EOF) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 13; j++)
                hand[i].pii[j] = make_pair(0, j);
            for (int j = 0; j < 5; j++) {
                if(i || j) scanf("%s", buf);
                if(j == 0) hand[i].suit = buf[1];
                else if(hand[i].suit != buf[1]) hand[i].suit = '#';
                switch(buf[0]) {
                    case 'T': ++hand[i].pii[hand[i].value[j] = 8].first; break;
                    case 'J': ++hand[i].pii[hand[i].value[j] = 9].first; break;
                    case 'Q': ++hand[i].pii[hand[i].value[j] = 10].first; break;
                    case 'K': ++hand[i].pii[hand[i].value[j] = 11].first; break;
                    case 'A': ++hand[i].pii[hand[i].value[j] = 12].first; break;
                    default: ++hand[i].pii[hand[i].value[j] = buf[0] - '2'].first; break;
                }
            }
            sort(hand[i].value, hand[i].value + 5, greater <int>());
            sort(hand[i].pii, hand[i].pii + 13, greater <pair <int, int> >());
        }
        switch(hand[0].cmp(hand[1])) {
            case 1: puts("Black wins."); break;
            case -1: puts("White wins."); break;
            case 0: puts("Tie."); break;
        }
    }

    return 0;
}

//2769204 2008-03-03 21:44:46 Accepted 1111 C++ 00:00.00 436K ¤ï¤¿¤·

// 2012-09-07 00:37:34 | Accepted | 1111 | C++ | 0 | 180 | watashi | Source
