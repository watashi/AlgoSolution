// SGU532. Building Foundation

import java.util.*;

public class Solution {
    static class Line {
        int x, l, r;
        Line(int x, int l, int r) {
            this.x = x;
            this.l = Math.min(l, r);
            this.r = Math.max(l, r);
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        ArrayList<Line> h = new ArrayList<Line>(n);
        ArrayList<Line> v = new ArrayList<Line>(n);
        for (int i = 0; i < n; ++i) {
            int x1 = in.nextInt();
            int y1 = in.nextInt();
            int x2 = in.nextInt();
            int y2 = in.nextInt();
            if (x1 == x2) {
                h.add(new Line(x1, y1, y2));
            } else if (y1 == y2) {
                v.add(new Line(y1, x1, x2));
            }
        }

        int ans = 0;
        for (Line a: h) {
            for (Line b: h) {
                if (a == b) {
                    break;
                }
                int y1 = Math.max(a.l, b.l);
                int y2 = Math.min(a.r, b.r);
                if (y1 >= y2) {
                    continue;
                }
                int x1 = Math.min(a.x, b.x);
                int x2 = Math.max(a.x, b.x);
                int tmp = 0;
                for (Line c: v) {
                    if (c.l <= x1 && x2 <= c.r && y1 <= c.x && c.x <= y2) {
                        ++tmp;
                    }
                }
                ans += tmp * (tmp - 1) / 2;
            }
        }
        System.out.println(ans);
    }
}

// ID:     Date'n'Time:    Name:      Task: .Ext:   Status:      Time: Memory:
// 1313518 30.06.12 03:06  watashi    532   .JAVA   Accepted     348   472 kb
