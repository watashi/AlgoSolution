import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int n = in.nextInt();
            int w = in.nextInt();
            int h = in.nextInt();
            int[] x = new int[n + 1];
            int[] y = new int[n + 1];
            x[0] = 0;   // if! WA
            y[0] = 0;   // !
            for (int i = 1; i <= n; ++i) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
            }
            int ans = 0, xx = -1, yy = -1;
            for (int p : x) {
                for (int q : y) {
                    int tmp = Math.min(w - p, h - q);
                    for (int i = 1; i <= n; ++i) {
                        if (x[i] > p && y[i] > q) {
                            tmp = Math.min(tmp, Math.max(x[i] - p, y[i] - q));
                        }
                    }
                    if (tmp > ans) {
                        ans = tmp;
                        xx = p;
                        yy = q;
                    }
                }
            }
            System.out.println(xx + " " + yy + " " + ans);
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1759844   2009-02-07 01:01:06     Accepted    1551    Java    0   1635    watashi@Zodiac

/*
##BUG##
Submit Time     Language    Run Time(ms)    Run Memory(KB)      User Name
2006-10-18 10:25:28     C++     0   440     ???
2006-10-18 10:25:45     C++     0   444     SHiVa
2009-02-07 01:01:06     Java    0   1635    watashi@Zodiac
2007-05-10 20:25:41     C++     10  440     AlPacino
2007-05-10 20:27:11     C++     10  440     AlPacino
2006-05-03 11:04:50     C++     10  856     billynyh
2005-09-22 20:55:19     FPC     20  396     Farmer John
2005-10-06 14:46:13     C++     20  844     Pc
2008-03-07 12:58:23     C++     30  444     flowsky
2006-01-31 21:38:06     C++     40  440     Ronin
2006-12-04 13:52:20     C   40  524     mj
2008-03-07 23:27:30     C++     40  844     vacuum_zhou
2006-01-31 21:34:27     C++     50  444     Ronin
2008-03-07 23:31:31     C++     50  844     Fire!
2008-04-07 20:00:24     FPC     60  408     yllw
2006-10-04 21:02:51     C++     70  396     rui
2005-10-15 08:14:36     FPC     70  400     推倒萝莉大作战
2006-10-06 15:56:02     C++     70  852     tiramisu
2005-12-01 16:50:23     FPC     80  412     zouyuhan
2006-06-17 22:05:42     FPC     80  420     sm3
*/

// 2012-09-07 00:53:31 | Accepted | 1551 | Java | 260 | 1690 | watashi | Source
