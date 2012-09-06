import java.util.*;

public class Main {
    static final int MAXN = 32;
    static long[] ans;

    static {
        ans = new long[MAXN];
        ans[0] = 0;
        for (int i = 1; i < MAXN; ++i) {
            ans[i] = (ans[i - 1] << 1) + (i & 1);
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int re = in.nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            int n = in.nextInt();
            System.out.println(ans[n]);
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801436   2009-03-24 02:11:21     Accepted    3182    Java    0   122     watashi@Zodiac

// 2012-09-07 02:06:50 | Accepted | 3182 | Java | 30 | 252 | watashi | Source
