import java.util.*;

public class Main {
    static final int MAXY = 2020;
    static int[] sum;

    static {
        sum = new int[MAXY];
        for (int i = 0; i < MAXY; ++i) {
            for (int m = 1; m <= 12; ++m) {
                if (m * m == i % 100 || m * m == i % 1000) {
                    sum[i] = 1;
                    break;
                }
            }
        }
        for (int i = 1; i < MAXY; ++i) {
            sum[i] += sum[i - 1];
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int re = in.nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            int x = in.nextInt();
            int y = in.nextInt();
            System.out.println(sum[y] - sum[x - 1]);
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801371   2009-03-24 00:13:54     Accepted    3174    Java    0   121     watashi@Zodiac

// 2012-09-07 02:06:01 | Accepted | 3174 | Java | 40 | 251 | watashi | Source
