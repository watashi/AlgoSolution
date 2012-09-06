/*
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int re = Integer.parseInt(in.readLine());

        for (int ri = 1; ri <= re; ++ri) {
            String[] ns = in.readLine().split(" ");
            int n = Integer.parseInt(ns[0]), s = Integer.parseInt(ns[1]);
            String[] a = in.readLine().split(" ");
            int cur = 0, sum = 0, ans = n + 1;

            for (int i = 0; i < a.length; ++i) {
                sum += Integer.parseInt(a[i]);
                if (sum >= s) {
                    do {
                        sum -= Integer.parseInt(a[cur++]);
                    } while (sum >= s);
                    ans = Math.min(ans, i - cur + 2);
                }
            }
            if (ans == n + 1) {
                ans = 0;
            }
            System.out.println(ans);
        }
    }
}
*/

#include <cctype>
#include <cstdio>
#include <algorithm>

using namespace std;

inline int readInt() {
    static char ch;
    int ret = 0;

    while (!isdigit(ch = getchar())) {
        continue;
    }
    do {
        ret *= 10;
        ret += ch - '0';
    } while (isdigit(ch = getchar()));

    return ret;
}

int a[100000];

int main() {
    int re = readInt(), n, s;
    int cur, sum, ans;

    for (int ri = 1; ri <= re; ++ri) {
        n = readInt();
        s = readInt();
        cur = 0;
        sum = 0;
        ans = n + 1;
        for (int i = 0; i < n; ++i) {
            sum += (a[i] = readInt());
            if (sum >= s) {
                do {
                    sum -= a[cur++];
                } while (sum >= s);
                ans = min(ans, i - cur + 2);
            }
        }
        printf("%d\n", ans == n + 1 ? 0 : ans);
    }
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1746060   2009-01-21 02:07:33     Accepted    3123    C++     10  568     watashi@Zodiac

// 2012-09-07 02:02:20 | Accepted | 3123 | C++ | 20 | 572 | watashi | Source
