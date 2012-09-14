import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int re = in.nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            int x = in.nextInt();
            int y = in.nextInt();
            String[] a = new String[8];
            for (int i = 0; i < 8; ++i) {
                a[i] = in.next();
            }
            int s = 0;
            for (int i = 0; i < 6; ++i) {
                s *= 10;
                if (a[0].charAt(i) == '|') {
                    s += 5;
                }
                for (int j = 0; j < 5; ++j) {
                    if (a[j + 3].charAt(i) == '|') {
                        s += j;
                        break;
                    }
                }
            }
            System.out.println((s == (x + y) * (y - x + 1) / 2) ? "No mistake" : "Mistake");
        }
    }
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801422   2009-03-24 01:29:11     Accepted    3179    Java    0   303     watashi@Zodiac

// 2012-09-07 02:06:32 | Accepted | 3179 | Java | 60 | 378 | watashi | Source
