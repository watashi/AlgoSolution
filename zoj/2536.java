import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int re = in.nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            int n = in.nextInt();
            int k = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
            Arrays.sort(a);
            int p = 0;
            int sum = 0;
            while (true) {
                if (p < a.length && a[p] <= sum + 1) {
                    sum += a[p];
                    ++p;
                } else if (k > 0) {
                    sum += sum + 1;
                    --k;
                } else {
                    break;
                }
            }
            System.out.println("Case " + ri + ":");
            System.out.println(sum + 1);
            if (ri < re) {
                System.out.println();
            }
        }
    }
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801934   2009-03-24 16:57:14     Accepted    2536    Java    0   485     watashi@Zodiac

// 2012-09-07 01:27:16 | Accepted | 2536 | Java | 50 | 633 | watashi | Source
