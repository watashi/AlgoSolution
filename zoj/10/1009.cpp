#include <string>
#include <iostream>
using namespace std;
class Enigma
{
private:
    static const int n = 3;
    int m;
    int p[n];
    int* a[n];
    int* b[n];
    inline int format(int x) const
    {
        return (x %= m) < 0 ? x + m : x;
    }
    inline void reset()
    {
        for (int i = 0; i < n; i++)
            p[i] = 0;
    }
    inline void revolve()
    {
        for (int i = 0; i < n; i++) {
            p[i]++;
            if(p[i] == m) {
                p[i] = 0;
            } else {
                break;
            }
        }
    }
    inline char trans(char ch) const
    {
        int res = ch - 'a';
        for (int i = 0; i < n; i++)
            res = format(res + a[i][format(res - p[i])]);
        return res + 'A';
    }
    inline char decipher(char ch) const
    {
        int res = ch - 'A';
        for (int i = n - 1; i >= 0; i--)
            res = format(res + b[i][format(res - p[i])]);
        return res + 'a';
    }
public:
    Enigma(int m) : m(m)
    {
        for (int i = 0; i < n; i++) {
            a[i] = new int[m];
            b[i] = new int[m];
        }
    }
    ~Enigma()
    {
        for (int i = 0; i < n; i++) {
            delete[] a[i];
            delete[] b[i];
        }
    }
    inline string operator[](const string& str)
    {
        reset();
        string res = "";
        for (unsigned i = 0; i < str.length(); i++) {
            res += trans(str[i]);
            revolve();
        }
        return res;
    }
    inline string operator()(const string& str)
    {
        reset();
        string res = "";
        for (unsigned i = 0; i < str.length(); i++) {
            res += decipher(str[i]);
            revolve();
        }
        return res;
    }
    inline friend istream& operator>>(istream& is, Enigma& that)
    {
        for (int i = 0; i < n; i++) {
            string cur;
            is >> cur;
            for (int j = 0; j < that.m; j++) {
                that.a[i][j] = cur[j] - 'A' - j;
                that.b[i][cur[j] - 'A'] = j + 'A' - cur[j];
            }
        }
        return is;
    }
};
int main()
{
    int ri = 0;
    int m;
    while(cin >> m && m) {
        Enigma enigma(m);
        cin >> enigma;
        if(ri) cout << endl;
        cout << "Enigma " << ++ri << ":" << endl;
        int p;
        cin >> p;
        while(p--) {
            string str;
            cin >> str;
            cout << enigma(str) << endl;
        }
    }
}
//2712885 2007-12-25 19:55:54 Accepted 1009 C++ 00:00.51 2988K わたし
//2712884 2007-12-25 19:55:10 Presentation Error 1009 C++ 00:00.52 872K わたし

// 2012-09-07 00:32:54 | Accepted | 1009 | C++ | 110 | 188 | watashi | Source
