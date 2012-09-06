import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int n = in.nextInt();
            if (n == 0) {
                break;
            }
            int[] a = new int[n];
            for (int i = 0; i < a.length; ++i) {
                a[i] = in.nextInt();
            }
            Arrays.sort(a);
            int s = 0;
            for (int e : a) {
                s += e;
            }
            s -= a[0] + a[a.length - 1];
            s /= a.length - 2;
            System.out.println(s);
        }
    }
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//81762833  2009-02-14 13:31:15     Accepted    3100    Java    0   424     watashi@Zodiac

// 2012-09-07 02:01:25 | Accepted | 3100 | Java | 60 | 504 | watashi | Source
