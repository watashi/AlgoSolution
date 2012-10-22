// SGU531. Bonnie and Clyde

import java.io.*;

public class Solution {
    static int nextInt() throws IOException {
        int ch = -1;
        do {
            ch = System.in.read();
        } while (!Character.isDigit(ch));
        int ret = 0;
        while (Character.isDigit(ch)) {
            ret *= 10;
            ret += Character.digit(ch, 10);
            ch = System.in.read();
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        int n = nextInt();
        int m = nextInt();
        int[] x = new int[n];
        int[] w = new int[n];
        int a = -2, b = -2, c = -1;
        for (int i = 0, j = 0; i < n; ++i) {
            x[i] = nextInt();
            w[i] = nextInt();
            while (x[j] <= x[i] - m) {
                if (c < 0 || w[c] < w[j]) {
                    c = j;
                }
                ++j;
            }
            if (c >= 0) {
                if (a < 0 || w[a] + w[b] < w[c] + w[i]) {
                    a = c;
                    b = i;
                }
            }
        }
        System.out.println((a + 1) + " " + (b + 1));
    }
}

// ID:     Date'n'Time:     Name:      Task: .Ext:   Status:      Time: Memory:
// 1313516 30.06.12 02:42   watashi    531   .JAVA   Accepted     90 ms 236 kb
