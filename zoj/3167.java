import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int k = in.nextInt();
            int m = in.nextInt();
            int[] a = new int[k];
            a[0] = 1;
            for (int n = 1; ; ++n) {
                int c = 0;
                for (int i = 0; i < k; ++i) {
                    a[i] = a[i] * m + c;
                    c = a[i] / 10;
                    a[i] %= 10;
                }
                if (a[k - 1] == 7) {
                    System.out.println(n);
                    break;
                }
            }
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801357   2009-03-23 23:43:01     Accepted    3167    Java    0   2428    watashi@Zodiac

// 2012-09-07 02:05:24 | Accepted | 3167 | Java | 260 | 2523 | watashi | Source
