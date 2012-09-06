// modInverse

import java.io.*;

public class Main {
    public static int[] inv;

    static {
        inv = new int[10];
        for (int i = 0; i < inv.length; ++i) {
            for (int j = 0; j < inv.length; ++j) {
                if (i * j % 10 == 1) {
                    inv[i] = j;
                    inv[j] = i;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String s;
        while ((s = in.readLine()) != null) {
            int[] ar = new int[26];
            for (char c : s.toCharArray()) {
                ++ar[c - 'a'];
            }
            int ans = 1, two = 0, five = 0;
            for (int a : ar) {
                for (int i = 2; i <= a; ++i) {
                    int t = i;
                    while (t % 2 == 0) {
                        t /= 2;
                        --two;
                    }
                    while (t % 5 == 0) {
                        t /= 5;
                        --five;
                    }
                    ans = (ans * inv[t % 10]) % 10;
                }
            }
            for (int i = 2; i <= s.length(); ++i) {
                int t = i;
                while (t % 2 == 0) {
                    t /= 2;
                    ++two;
                }
                while (t % 5 == 0) {
                    t /= 5;
                    ++five;
                }
                ans = (ans * t) % 10;
            }
            for (int i = five; i < two; ++i) {
                ans = (ans * 2) % 10;
            }
            System.out.println(ans);
        }
    }
}

//1800954   2009-03-23 19:59:54       Accepted      3108    Java    0   17665   watashi@Zodiac

// 2012-09-07 02:01:43 | Accepted | 3108 | Java | 240 | 9667 | watashi | Source
