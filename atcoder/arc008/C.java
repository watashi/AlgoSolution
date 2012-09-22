import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        double[] x = new double[n];
        double[] y = new double[n];
        double[] t = new double[n];
        double[] r = new double[n];
        for (int i = 0; i < n; ++i) {
            x[i] = in.nextDouble();
            y[i] = in.nextDouble();
            t[i] = in.nextDouble();
            r[i] = in.nextDouble();
        }

        double[][] d = new double[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = Math.hypot(x[i] - x[j], y[i] - y[j]) / Math.min(t[i], r[j]);
            }
        }

        boolean[] mark = new boolean[n];
        double[] mind = new double[n];
        Arrays.fill(mind, 1e100);
        mind[0] = 0;
        for (int i = 0; i < n; ++i) {
            int k = -1;
            for (int j = 0; j < n; ++j) {
                if (!mark[j] && (k == -1 || mind[j] < mind[k])) {
                    k = j;
                }
            }
            mark[k] = true;
            for (int j = 0; j < n; ++j) {
                mind[j] = Math.min(mind[j], mind[k] + d[k][j]);
            }
        }

        Arrays.sort(mind);
        double ans = 0;
        for (int i = 1; i < n; ++i) {
            ans = Math.max(ans, mind[i] + n - 1 - i);
        }
        System.out.printf("%.8f\n", ans);
    }
}

