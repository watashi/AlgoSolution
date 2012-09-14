import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int re = in.nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            long n = in.nextLong();
            long ans = 0;
            long s, t, d;
            s = n;
            while (s > 0) {
                t = s;
                d = n / t;
                s = n / (d + 1);
                ans += (t - s) * (d - 1);
            }
            System.out.println(ans);
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801377   2009-03-24 00:24:08     Accepted    3175    Java    0   303     watashi@Zodiac

// 2012-09-07 02:06:07 | Accepted | 3175 | Java | 550 | 378 | watashi | Source
