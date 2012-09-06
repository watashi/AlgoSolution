#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Hand;

class Card
{
        friend class Hand;
    private:
        int suit, rank;
    public:
        friend bool operator<(const Card& lhs, const Card& rhs)
        {
            return lhs.rank < rhs.rank;
        }
        friend istream& operator>>(istream& is, Card& c)
        {
            char ch;

            is >> ch;
            switch(ch) {
                case 'H': c.suit = 0; break;
                case 'S': c.suit = 1; break;
                case 'D': c.suit = 2; break;
                case 'C': c.suit = 3; break;
                default: throw "INVAILD_SUIT";
            }
            is >> ch;
            switch(ch) {
                case 'T': c.rank = 10; break;
                case 'J': c.rank = 11; break;
                case 'Q': c.rank = 12; break;
                case 'K': c.rank = 13; break;
                case 'A': c.rank = 14; break;
                default:
                    if (!(ch >= '2' && ch <= '9')) {
                        throw "INVALID_RANK";
                    }
                    c.rank = ch - '0'; break;
            }

            return is;
        }
};

class Hand
{
    private:
        vector<Card> vc;
        bool isflush()
        {
            for (size_t i = 1; i < 5; i++) {
                if (vc[i].suit != vc[0].suit) {
                    return false;
                }
            }
            return true;
        }
        bool isstraihgt()
        {
            for (size_t i = 1; i < 5; i++) {
                if (vc[i].rank != vc[0].rank + i) {
                    return false;
                }
            }
            return true;
        }
        bool has_4()
        {
            return vc[0].rank == vc[3].rank || vc[1].rank == vc[4].rank;
        }
        bool has_3_2()
        {
            return vc[0].rank == vc[2].rank && vc[3].rank == vc[4].rank ||
                vc[0].rank == vc[1].rank && vc[2].rank == vc[4].rank;
        }
        bool has_3()
        {
            for (int i = 2; i < 5; i++) {
                if (vc[i - 2].rank == vc[i].rank) {
                    return true;
                }
            }
            return false;
        }
        int cnt_2()
        {
            int ret = 0;

            for (int i = 1; i < 5; i++) {
                if (vc[i].rank == vc[i - 1].rank) {
                    ++ret;
                }
            }

            return ret;
        }
    public:
        void add(const Card& c)
        {
            vc.push_back(c);
        }
        int rate()
        {
            if (vc.size() != 5) {
                throw "INVALID_HAND";
            }
            sort(vc.begin(), vc.end());

            bool flush = isflush(), straihgt = isstraihgt();

            if (flush && straihgt) {
                return (vc[4].rank == 14) ? 500 : 100;
            }
            else if (has_4()) {
                return 50;
            }
            else if (has_3_2()) {
                return 15;
            }
            else if (flush) {
                return 10;
            }
            else if (straihgt) {
                return 8;
            }
            else if (has_3()) {
                return 4;
            }
            else {
                switch (cnt_2()) {
                    case 2: return 3;
                    case 1: return 2;
                    case 0: return 0;
                    default: throw "INVAILD_CNT_2";
                }
            }
        }
};

int rate(const vector<Card>& vc)
{
    int ret = 0;
    vector<bool> p(5, false);

    for (size_t i = vc.size() - 5; i < 5; i++) {
        p[i] = true;
    }
    do {
        Hand h;

        for (size_t i = 0; i < 5; i++) {
            if (p[i]) {
                h.add(vc[i]);
            }
        }
        for (size_t i = 5; i < vc.size(); i++) {
            h.add(vc[i]);
        }
        ret = max(ret, h.rate());
    } while (next_permutation(p.begin(), p.end()));

    return ret;
}

int main(void)
{
    int n;

    while (cin >> n) {
        vector<Card> vc(n);
        for (int i = 0; i < n; i++) {
            cin >> vc[i];
        }

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 5; i <= n; i++) {
            for (int j = max(0, i - 10); j <= i - 5; j++) {
                dp[i] = max(dp[i], min(9999, dp[j] * rate(vector<Card>(vc.begin() + j, vc.begin() + i))));
            }
        }

        int ans = *max_element(dp.begin() + 5, dp.end());
        cout << 16 + ((ans == 0) ? -1 : (10 * (ans - 1))) << endl;
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1711140   2008-11-26 21:25:48     Accepted    3051    C++     170     184     watashi@Zodiac

// 2012-09-07 01:58:46 | Accepted | 3051 | C++ | 170 | 188 | watashi | Source
