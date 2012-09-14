import java.util.*;

public class Main {
    public static final double EPS = 1e-8;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int re = in.nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            double x0 = in.nextDouble();
            double y0 = in.nextDouble();
            double x1 = in.nextDouble();
            double y1 = in.nextDouble();
            double dx = in.nextDouble();
            double dy = in.nextDouble();
            double r0 = in.nextDouble();
            double r1 = in.nextDouble();
            double v = in.nextDouble();
            x0 -= x1;
            y0 -= y1;
            r0 += r1;
            double a = dx * dx + dy * dy - v * v;
            double b = 2 * (dx * x0 + dy * y0 - v * r0);
            double c = x0 * x0 + y0 * y0 - r0 * r0;
            // !c > 0!
            double t = -1;
            if (Math.abs(a) < EPS) {
                if (b < -EPS) {
                    t = -c / b;
                }
            } else {
                double d = b * b - 4 * a * c;
                if (d > -EPS) {
                    d = Math.sqrt(Math.abs(d));
                    double t1 = (-b - d) / (2 * a);
                    double t2 = (-b + d) / (2 * a);
                    if (t1 > -EPS && t2 > -EPS) {
                        t = Math.min(t1, t2);
                    } else if (t1 > -EPS) {
                        t = t1;
                    } else if (t2 > -EPS) {
                        t = t2;
                    }
                }
            }
            if (t < -EPS) {
                System.out.println("Impossible");
            } else {
                System.out.printf("%.4f\n", Math.abs(t));
            }
        }
    }
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801409   2009-03-24 01:13:47     Accepted    3177    Java    0   2650    watashi@Zodiac

// 2012-09-07 02:06:19 | Accepted | 3177 | Java | 180 | 2783 | watashi | Source
