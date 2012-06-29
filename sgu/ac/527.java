// SGU527. Explode 'Em All

import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int r = in.nextInt();
        int c = in.nextInt();
        int[] a = new int[r];
        for (int i = 0; i < r; ++i) {
            String s = in.next();
            for (int j = 0; j < c; ++j) {
                if (s.charAt(j) == '*') {
                    a[i] |= 1 << j;
                }
            }
        }

        int[] m = new int[1 << r];
        int ans = r;
        for (int i = 1; i < (1 << r); ++i) {
            int j = Integer.numberOfTrailingZeros(i);
            m[i] = m[i ^ (1 << j)] | a[j];
            ans = Math.min(ans,
                    Math.max(r - Integer.bitCount(i), Integer.bitCount(m[i])));
        }
        System.out.println(ans);
    }
}

// ID:     Date'n'Time:     Name:      Task: .Ext:   Status:      Time: Memory:
// 1313509 30.06.12 02:21   watashi    527   .JAVA   Accepted     481   131692
