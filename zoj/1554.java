import java.util.*;

public class Main {
    private String str;
    private String[][] dp;

    public Main(String str) {
        this.str = str;
        dp = new String[str.length()][str.length() + 1];
    }

    private String fold(int begin, int end) {
        if (dp[begin][end] != null) {
            return dp[begin][end];
        }
        int len = end - begin;
        String best, temp;
        // Self
        best = str.substring(begin, end);
        // X(S)
        if (len > 1) {
            for (int l = 1; l * l <= len; ++l) {
                if (len % l != 0) {
                    continue;
                }
                int ll = len / l;
                if (str.substring(begin, end-l).equals(str.substring(begin+l, end))) {
                    temp = ll + "(" + fold(begin, begin+l) + ")";
                    if (temp.length() < best.length()) {
                        best = temp;
                    }
                }
                if (ll > l && l > 1 &&
                        str.substring(begin, end-ll).equals(str.substring(begin+ll, end))) {
                    temp = l + "(" + fold(begin, begin+ll) + ")";
                    if (temp.length() < best.length()) {
                        best = temp;
                    }
                }
            }
        }
        // S'Q'
        for (int l = 1; l < len; ++l) {
            if (fold(begin, begin+l).length() + fold(begin+l, end).length() < best.length()) {
                best = fold(begin, begin+l) + fold(begin+l, end);
            }
        }
        return (dp[begin][end] = best);
    }

    public String fold() {
        return fold(0, str.length());
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            String str = in.next();
            Main folder = new Main(str);
            System.out.println(folder.fold());
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1759779   2009-02-06 23:36:20     Accepted    1554    Java    0   3119    watashi@Zodiac

/*
##BUG##
Submit Time     Language    Run Time(ms)    Run Memory(KB)      User Name
2009-02-06 23:36:20     Java    0   3119    watashi@Zodiac
2008-10-23 19:28:53     C++     30  296     luxu
2008-04-07 22:30:15     FPC     40  556     yllw
2005-11-12 00:59:53     C++     90  476     XXXXXX
2005-09-22 22:35:19     C++     90  480     mast_whu
2007-05-01 10:13:11     C++     90  520     ÉË¸ÐÄÐÈË
2007-02-25 09:50:17     C++     100     516     Windows2k
2006-10-05 17:27:38     C++     100     924     Oxygen
2007-06-26 15:38:17     C++     100     996     gbb
*/

// 2012-09-07 00:53:43 | Accepted | 1554 | Java | 330 | 8407 | watashi | Source
