import java.util.*;

public class Main {
    private int[] c;

    public Main(int n) {
        c = new int[n + 1];
        for (int i = 0; i <= n; ++i) {
            c[i] = 0;
            for (int j = 1; j <= i; ++j) {
                c[i] += (i - j + 1) * (i - j + 1) * j;
            }
        }
    }

    public int get(int i) {
        return c[i];
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Main solution = new Main(100);
        while (true) {
            int n = in.nextInt();
            double total = in.nextInt() / 2400.;
            if (n == 0) {
                break;
            }
            total *= n * n;
            total *= n * n - 1;
            total *= n * n - 2;
            total *= n * n - 3;
            System.out.printf("%.2f\n", total / solution.get(n - 1));
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1758614   2009-02-06 07:44:13     Accepted    1515    Java    0   125     watashi@Zodiac

// 2012-09-07 00:51:59 | Accepted | 1515 | Java | 40 | 211 | watashi | Source
